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


namespace TigerTV {


Bint Bint::operator >> (const uint64_t shift) const {
	Bint b(*this);
	b >>= shift;
	return b;
}

Bint& Bint::operator >>= (const uint64_t shift) {
	uint64_t sh = shift;
	if (sh > 63) {
		uint64_t q = sh / 64; // container size specific
		sh %= 64;
		// check q limits
		if (q >= number.size()) {
			number.clear();
			number.push_back(0);
			return *this;
		} else {
			number.erase(number.begin(), number.begin() + q);
		}
	}

	bool neg = isNegative();

	uint64_t mask = (1 << sh) - 1;
	uint64_t maskShift = 64 - sh;
	uint64_t carry = 0;

	for (int i = (int)number.size() - 1; i >= 0; --i) {
		uint64_t nextCarry = number[i] & mask;
		number[i] >>= sh;
		if (carry) {
			carry <<= maskShift;
			number[i] |= carry;
		}
		carry = nextCarry;
	}

	if (neg) {
		uint64_t t = -1;
		t <<= maskShift;
		uint64_t& num = number.back();
		num |= t;
	}

	eraseLeadingSign();
	return *this;
}

// unsigned right shift
Bint& Bint::urshift(const uint64_t shift) {
	uint64_t sh = shift;
	if (sh > 63) {
		uint64_t q = sh / 64;
		sh %= 64;
		// check q limits
		if (q >= number.size()) {
			number.clear();
			number.push_back(0);
			return *this;
		} else {
			number.erase(number.begin(), number.begin() + q);
		}
	}

	uint64_t mask = (1 << sh) - 1;
	uint64_t maskShift = 64 - sh;
	uint64_t carry = 0;

	for (int i = (int)number.size() - 1; i >= 0; --i) {
		uint64_t nextCarry = number[i] & mask;
		number[i] >>= sh;
		if (carry) {
			carry <<= maskShift;
			number[i] |= carry;
		}
		carry = nextCarry;
	}

	eraseLeadingSign();

	return *this;
}

Bint Bint::operator << (const uint64_t shift) const {
	Bint b(*this);
	b <<= shift;
	return b;
}

Bint& Bint::operator <<= (const uint64_t shift) {
	uint64_t sh = shift;
	uint64_t q = 0;
	if (sh > 63) { // size specific
		q = sh / 64;
		sh %= 64;
	}
	bool neg = isNegative();
	uint64_t mask = ~(((uint64_t)-1) >> sh);
	uint64_t maskShift = 64 - sh; // size specific
	uint64_t carry = 0;

	for (uint64_t& n : number) {
		uint64_t nextCarry = n & mask;
		n <<= sh ;
		if (carry) {
			carry >>= maskShift;
			n |= carry;
		}
		carry = nextCarry;
	}

	if (carry) {
		uint64_t t = neg ? -1 : 0;
		t <<= sh;
		carry >>= maskShift;
		carry |= t;
		number.push_back(carry);
	}

	if (neg != isNegative()) {
		if (neg) {
			number.push_back(-1);
		} else {
			number.push_back(0);
		}
	}

	if (q) {
		std::vector<uint64_t> a(q, 0);
		number.insert(number.begin(), a.begin(), a.end());
	}

	eraseLeadingSign();

	return *this;
}


} // namespace
