/*
 * MIT License
 *
 * This file is part of the big-integer (https://github.com/tigertv/big-integer).
 * Copyright (c) 2020 Max Vetrov(tigertv).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Bint.h"

#include "Bint/arithmetics.cpp"
#include "Bint/comparison.cpp"
#include "Bint/bitoperations.cpp"
#include "Bint/shifts.cpp"
#include "Bint/io.cpp"

#include <stdexcept>


namespace TigerTV {

const std::string Bint::alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

Bint::Bint() {
	number.push_back(0);
}

Bint::Bint(const std::string& s) : Bint() {
	std::string::size_type n = s.rfind("_b");
	int base;
	if (n == std::string::npos) {
		base = 10;
		setDecimal(s);
	} else {
		try {
			base = std::stoi(s.substr(n + 2));
		} catch (...) {
			std::string err("Invalid base! The base should be decimal and not too big.");
			throw std::invalid_argument(err);
		}
		setNumber(s.substr(0, n) , base);
	}

}

void Bint::setNumber(const std::string& s, int base) {
	auto it = s.begin();
	std::string a = alphabet.substr(0, base);
	bool neg = (*it == '-');
	if (neg) ++it;

	if (base <= (int)alphabet.size()) {
		for(; it != s.end(); ++it) {
			(*this) *= base;
			// find digit in the alphabet
			int i = a.find(*it);
			if (i == (int)std::string::npos) {
				std::string err("Unexpected symbol! - '");
				err.push_back(*it);
				err.push_back('\'');
				throw std::invalid_argument(err);
			};
			(*this) += i;
		}
	} else {
		// If the base is more than size of the alphabet we use ':' as a separator for digits in decimal
		std::string::size_type prev = 0;
		std::string::size_type n;
		while (true) {
			n = s.find(':', prev);
			int dec; 
			try {
				if (n != std::string::npos) {
					dec = std::stoi(s.substr(prev, n - prev));
				} else {
					dec = std::stoi(s.substr(prev));
					(*this) *= base;
					(*this) += dec;
					break;
				}
			} catch (...) {
				std::string err("Unexpected symbol in string!");
				throw std::invalid_argument(err);
			}

			(*this) *= base;
			(*this) += dec;
			prev = n + 1;
		} 
	}

	if (neg) {
		*this = -(*this);
	}
	
	eraseLeadingSign();
}

Bint::Bint(const char* decimal) : Bint((std::string)decimal) {

}

Bint::Bint(const int64_t num) {
	number.push_back(num);
}

void Bint::setDecimal(const std::string& s) {
	auto it = s.begin();

	bool neg = (*it == '-');
	if (neg) ++it;

	for(; it != s.end(); ++it) {
		(*this) *= 10;
		// add digit
		int64_t i = *it - '0';
		if (i > 9) {
			std::string s("Unexpected symbol! - ");
			s.push_back(*it);
			throw std::invalid_argument(s);
		}
		(*this) += i;
	}

	if (neg) {
		*this = -(*this);
	}
	
	eraseLeadingSign();
}

void Bint::eraseLeadingSign() {
	bool neg = isNegative();
	// refactor
	if (neg) {
		for (size_t i = number.size() - 1; i != 0; i--) {
			if (number[i] != (uint64_t)-1) break;
			bool sign = number[i-1] >> 63;
			// erase last
			if (neg == sign) number.erase(number.end()-1);
		}
	} else {
		for (size_t i = number.size() - 1; i != 0; i--) {
			if (number[i] != 0) break;
			bool sign = number[i-1] >> 63;
			// erase last
			if (neg == sign) number.erase(number.end()-1);
		}
	}
}

void Bint::extendNumberBySizeOf(Bint& extNumber, const Bint& a) {
	const std::vector<uint64_t>& bin = a.number;
	std::vector<uint64_t>& ext = extNumber.number;

	int diff = (int)bin.size() - (int)ext.size();
	int num = extNumber.isNegative() ? -1 : 0;

	for(int i = 0; i < diff; i++) {
		ext.push_back(num);
	}
}

bool Bint::isNegative() const {
	uint64_t last = number.back();	
	last >>= 63; // size specific
	return last;
}


} // namespace
