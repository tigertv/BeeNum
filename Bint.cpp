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

#include <bits/stdc++.h>
#include <cstdlib>
#include "Bint.h"

#include "Bint/arithmetics.cpp"
#include "Bint/comparison.cpp"
#include "Bint/bitoperations.cpp"
#include "Bint/shifts.cpp"
#include "Bint/io.cpp"


namespace TigerTV {

const std::string Bint::alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

Bint::Bint() {
	number.push_back(0);
}

Bint::Bint(const std::string& decimal) : Bint() {
	setDecimal(decimal);
}

Bint::Bint(const char* decimal) : Bint() {
	setDecimal(decimal);
}

Bint::Bint(const int64_t num) {
	number.push_back(num);
}

void Bint::setDecimal(const std::string& s) {
	//const Bint ten(10);
	Bint temp;
	auto it = s.begin();

	bool neg = (*it == '-');
	if (neg) ++it;

	for(; it != s.end(); ++it) {
		//*
		Bint t(*this);
		*this <<= 3;
		t <<= 1;
		*this += t;
		//*/

		//(*this) *= ten;
		// add digit

		uint64_t i = *it - '0';
		if (i > 9) {
			std::string s("Unexpected symbol! - ");
			s.push_back(*it);
			throw std::invalid_argument(s);
		}
		temp.number[0] = i;
		*this += temp;
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
		for (int i = number.size() - 1; i > 0; i--) {
			if (number[i] != (uint64_t)-1) break;
			bool sign = number[i-1] >> 63;
			// erase last
			if (neg == sign) number.erase(number.end()-1);
		}
	} else {
		for (int i = number.size() - 1; i > 0; i--) {
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

	int diff = bin.size() - ext.size();
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
