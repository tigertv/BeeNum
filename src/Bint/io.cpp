/*
 * MIT License
 *
 * This file is part of the BeeNum (https://github.com/tigertv/BeeNum).
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

#include <algorithm>
#include <BeeNum/Bint.h>


namespace BeeNum {

Bint::operator std::string() const {
	return this->toString();
}

std::string Bint::bin() const {
	return "0b" + base2(1);
}

std::string Bint::base2(const uint64_t base) const {
	uint64_t mask = (1 << base) - 1;
	std::string s = "";

	Bint a(*this);
	uint64_t j = a.number.size() << 6;
	const uint64_t limit = j / base;
	const uint64_t rmd = j % base;
	j = 0;

	for(uint64_t i = 0; i < limit; i++) {
		j = a.number[0] & mask;
		s.push_back(alphabet[j]);
		a.urshift(base);
	}

	if (rmd) {
		j = a.number[0] & mask;
		s.push_back(alphabet[j]);
	}

	if (s.size() == 0) return "0";
	std::reverse(s.begin(), s.end());
	return s;
}

std::string Bint::toString() const {
	return base(10);
}

std::string Bint::hex() const {
	return "0x" + base2(4);
}

std::string Bint::oct() const {
	return "0" + base2(3);
}

std::string Bint::base(const uint64_t base) const {
	bool isBaseBig = (base > alphabet.size());

	Bint temp(*this);
	bool neg = isNegative();
	if (neg) {
		temp = -temp;
	}

	std::vector<uint64_t>current = temp.number;
	std::string s = "";

	while(current[0] || (current.size() > 1)) {
		std::vector<uint64_t>res;
		bool notFirst = false;
		uint64_t rmd = 0;

		for(int j = (int)current.size() - 1; j >= 0; j--) {
			uint64_t quot = div(current[j], base, rmd);
			if (quot) {
				notFirst = true;
			}
			if (notFirst) {
				res.push_back(quot);
			}
		}

		if (res.size() == 0) res.push_back(0);

		if (isBaseBig) {
			uint64_t current = rmd;
			do {
				rmd = current % 10;
				current = current / 10;
				s.push_back(alphabet[rmd]);
			} while (current);
			s.push_back(':');
		} else {
			s.push_back(alphabet[rmd]);
		}

		std::reverse(res.begin(), res.end());
		current = res;
	}

	if (s.size() == 0) {
		s = "0";
		if (base == 10) return s;
		return s + "::" + std::to_string(base);
	}

	if (isBaseBig) s.pop_back();
	if (neg) s += '-';

	std::reverse(s.begin(), s.end());

	if (base == 10) return s;
	return s + "::" + std::to_string(base);
}

////////////////////////////////////////////////////////////////////////
//            INPUT-OUTPUT FUNCTIONS
////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& strm, const Bint& a) {
	return strm << a.toString(); 
}

std::istream& operator >> (std::istream& strm, Bint& a) {
    std::string s;
    strm >> s;
    a = s; 
    return strm;
}


} // namespace
