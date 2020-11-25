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


namespace TigerTV {

Bint Bint::operator + (const Bint& a) const {
	Bint b = *this;
	b += a;
	return b;
}

Bint Bint::operator + (const int64_t a) const {
	Bint b = *this;
	b += a;
	return b;
}

Bint& Bint::operator += (const Bint& a) {
	if (a.number.size() == 1) return (*this) += a.number[0];

	Bint aa(a);
	// no need so many calls to extend
	extendNumberBySizeOf(*this, aa);	
	extendNumberBySizeOf(aa, *this);	

	std::vector<uint64_t>& bin = aa.number;

	int j = 0;
	bool carry = false;

	bool neg = isNegative();
	bool negA = aa.isNegative();

	for(; j < (int)number.size(); j++) {
		addUintWithCarry(number[j], bin[j], carry);
	}

	// check signed overflow 
	if ((neg == negA) && (neg != isNegative())) {
		// refactor it
		if (neg) {
			number.push_back(-1);
		} else {
			number.push_back(0);
		}
	}

	// TODO: check need
	eraseLeadingSign();
	return *this;
}

Bint& Bint::operator += (const int64_t a) {
	bool neg = isNegative();
	bool negA = (a < 0);
	bool carry = false;
	addUintWithCarry(number[0], a, carry);

	if (carry) {
		if (negA) {
			for(int j = 1; j < (int)number.size(); j++) {
				addUintWithCarry(number[j], -1, carry);
			}
		} else {
			for(int j = 1; j < (int)number.size(); j++) {
				addUintWithCarry(number[j], 0, carry);
				if (!carry) break;
			}
		}
	}

	// check signed overflow 
	if ((neg == negA) && (neg != isNegative())) {
		if (neg) {
			number.push_back(-1);
		} else {
			number.push_back(0);
		}
	}

	// TODO: check need
	eraseLeadingSign();
	return *this;
}

Bint Bint::operator * (const Bint& a) const {
	Bint b = *this;
	b *= a;
	return b;
}

Bint Bint::operator * (const int64_t a) const {
	Bint b = *this;
	b *= a;
	return b;
}

Bint& Bint::operator *= (const int64_t a) {
	if (a == 1) return *this;

	int64_t aa = a;
	bool neg = ((aa < 0) != isNegative());

	if (isNegative()) {
		*this = -(*this);
	}
	
	if (aa < 0) {
		aa = -aa;
	}
	
	uint64_t bigCarry = 0;	
	bool carry = false;
	for(int i = 0; i < (int)number.size(); ++i) {
		uint64_t opH = aa;
		mult(opH, number[i]);
		addUintWithCarry(number[i], bigCarry, carry);
		bigCarry = opH;
	}

	if (bigCarry || carry) {
		if (bigCarry != (uint64_t)-1) {
			number.push_back(bigCarry + carry);
		} else {
			number.push_back(0);
			number.push_back(1);
		}
	}

	if (isNegative()) {
		number.push_back(0);
	}

	eraseLeadingSign();

	if (neg) {
		*this = -(*this);
	}

	return *this;
}

Bint& Bint::operator *= (const Bint& a) {
	if (a.number.size() == 1) return (*this) *= a.number[0];

	Bint aa(a);

	bool neg = (a.isNegative() != isNegative());

	if (isNegative()) {
		*this = -(*this);
	}

	if (aa.isNegative()) {
		aa = -aa;
	}

	std::vector<uint64_t>& bin = aa.number;

	Bint c;
	int m = bin.size() * number.size();
	for (int i = 0; i < m; ++i) {
		c.number.push_back(0);
	}

	for(int j = bin.size() - 1; j >= 0 ; --j) {
		for(int i = number.size() - 1; i >= 0 ; --i) {
			uint64_t opH = number[i];	
			uint64_t opL = bin[j];	
			mult(opH, opL);
			c.addUintAt(i+j, opL);
			c.addUintAt(i+j+1, opH);
		}
	}

	c.eraseLeadingSign();

	if (neg) {
		c = -c;
	}

	this->number = c.number;
	return (*this);
}

void Bint::mult(uint64_t& operand1ResHigh, uint64_t& operand2ResLow) const {
	uint64_t low1 = 0x00000000ffffffff & operand1ResHigh;	
	uint64_t high1 = (0xffffffff00000000 & operand1ResHigh) >> 32;	
	uint64_t low2 = 0x00000000ffffffff & operand2ResLow;	
	uint64_t high2 = (0xffffffff00000000 & operand2ResLow) >> 32;	

	uint64_t ll = low1 * low2;
	uint64_t hh = high1 * high2;

	uint64_t lh = low1 * high2;
	uint64_t hl = high1 * low2;

	uint64_t lhh = (lh & 0xffffffff00000000) >> 32;
	uint64_t lhl = (lh & 0x00000000ffffffff) << 32;

	uint64_t hlh = (hl & 0xffffffff00000000) >> 32;
	uint64_t hll = (hl & 0x00000000ffffffff) << 32;

	uint64_t resL = lhl;
	uint64_t resH = lhh;
	resH += hlh;
	bool carry = false;
	addUintWithCarry(resL, hll, carry);
	if (carry) {
		++resH;
		carry = false;
	}
	addUintWithCarry(resL, ll, carry);
	addUintWithCarry(resH, hh, carry);
	operand1ResHigh = resH;
	operand2ResLow = resL;
}

Bint& Bint::operator ++ () { // prefix
	Bint c;
	c.number[0] = 1;
	*this += c;
	return *this;
}

Bint Bint::operator ++ (int) { // postfix
	Bint b = *this; 
	Bint c;
	c.number[0] = 1;
	*this += c;
	return b;
}

Bint Bint::operator - (const Bint& a) const {
	Bint b = *this;
	b -= a;
	return b;
}

Bint Bint::operator - (const int64_t a) const {
	Bint b = *this;
	b -= a;
	return b;
}

Bint& Bint::operator -= (const Bint& a) {
	Bint aa(a);
	aa = -aa;
	*this += aa;
	return *this;
}

Bint& Bint::operator -= (const int64_t a) {
	*this += -a;
	return *this;
}

Bint& Bint::operator -- () { // prefix
	Bint c;
	c.number[0] = 1;
	*this -= c;
	return *this;
}

Bint Bint::operator -- (int) { // postfix
	Bint b = *this; 
	Bint c;
	c.number[0] = 1;
	*this -= c;
	return b;
}

Bint Bint::operator / (const Bint& a) const {
	Bint b = *this;
	b /= a;
	return b;
}


Bint& Bint::operator /= (const Bint& a) {
	Bint c = *this;
	Bint res;

	div(c, res, a);

	this->number = res.number;
	return (*this);
}

Bint Bint::operator % (const Bint& a) const {
	Bint b = *this;
	b %= a;
	return b;
}

Bint& Bint::operator %= (const Bint& a) {

	Bint c = *this;
	Bint res;

	div(c, res, a);

	this->number = c.number;
	return (*this);
}

////////////////////////////////////////////////////////////////////////

void Bint::addUintWithCarry(uint64_t& operand1res, const uint64_t operand2, bool& carry) const {
	uint64_t bigCarry = (operand1res & 1) + (operand2 & 1) + carry;
	uint64_t result = (operand1res >> 1) + (operand2 >> 1) + (bigCarry >> 1);
	carry = (bool)(result & 0x8000000000000000);
	result <<= 1;
	result |= (bigCarry & 1);
	operand1res = result;
}

// it doesn't check bounds
void Bint::addUintAt(uint64_t index, uint64_t operand) {
	bool carry = false;
	addUintWithCarry(number[index], operand, carry);
	while(carry) {
		++index;
		if (number[index] != (uint64_t)-1) {
			++number[index];
			break;
		}
		number[index] = 0;
	}
}

uint64_t Bint::div(const uint64_t& dividend, const uint64_t& divisor, uint64_t& prevRmd) const {
	if (divisor == 0) {
		throw std::invalid_argument("Division by zero!");
	}

	uint64_t quot = 0;
	uint64_t rmd = 0;

	// count prevRmd
	if (prevRmd) {
		quot = (uint64_t)-1 / divisor;
		rmd = (uint64_t)-1 % divisor + 1;
		if (rmd == divisor) {
			++quot;
			rmd = 0;
		}

		quot *= prevRmd;
		rmd *= prevRmd;
	}

	// division of dividend and divisor	
	quot += dividend / divisor;
	rmd += dividend % divisor;

	quot += rmd / divisor;
	rmd %= divisor;

	prevRmd = rmd;
	return quot;
}

void Bint::div(Bint& rmdDividend, Bint& resQuot, const Bint& divisor) const {
	if (divisor == 0) {
		throw std::invalid_argument("Division by zero!");
	}

	Bint& a = rmdDividend; 
	Bint d = divisor;
	Bint& c = resQuot;

	bool neg = (a.isNegative() != d.isNegative());

	if (a.isNegative()) {
		a = -a;
	}

	if (d.isNegative()) {
		d = -d;
	}

	if (a < d) {
		// c = 0;
		if (neg) {
			a = -a;
		}
		return;
	}

	Bint dvsr = d;

	std::vector<uint64_t>& dnum = d.number;

	// add zeros at the end
	int diff = a.number.size() - dnum.size();
	for(int i = diff; i > 0; --i) {
		dnum.insert(dnum.begin(), 0);
	}

	// find where to subtruct
	while(a >= d) {
		d <<= 1;
	}

	while(d > a) {
		d >>= 1;
	}

	// do subtruction
	while(d >= dvsr) {
		c <<= 1;
		if (d <= a) {
			c.number[0] |= 1;
			a -= d;
		} 
		d >>= 1;
	}

	if (neg) {
		c = -c;
		a = -a;
	}

}

Bint Bint::operator - () const { // prefix
	Bint r(*this);
	r = ~r + 1;
	return r;
}

} // namespace
