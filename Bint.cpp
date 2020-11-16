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


namespace TigerTV {


Bint::Bint() {
	number.push_back(0);
}

Bint::Bint(const std::string& decimal) : Bint() {
	setDecimal(decimal);
}

Bint::Bint(const char* decimal) : Bint() {
	setDecimal(decimal);
}

Bint::Bint(int num) {
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

Bint Bint::operator + (const Bint& a) const {
	Bint b = *this;
	b += a;
	return b;
}

Bint& Bint::operator += (const Bint& a) {
	Bint aa(a);
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

	eraseLeadingSign();
	return *this;
}

bool Bint::operator == (const Bint &b) const {
	const std::vector<uint64_t>& n = b.number;
	if (number.size() < n.size()) return false;
	if (number.size() > n.size()) return false;

	for(int i = n.size() - 1; i >= 0; i--) {
		if(number[i] != n[i]) {
			return false;
		}
	}

	return true;
}

bool Bint::operator != (const Bint &b) const {
	const std::vector<uint64_t>& n = b.number;
	if (number.size() < n.size()) return true;
	if (number.size() > n.size()) return true;

	for(int i = n.size() - 1; i >= 0; i--) {
		if(number[i] != n[i]) {
			return true;
		}
	}

	return false;
}

bool Bint::operator > (const Bint& b) const {
	const std::vector<uint64_t>& n = b.number;
	if (number.size() < n.size()) return false;
	if (number.size() > n.size()) return true;

	for(int i = n.size() - 1; i >= 0; i--) {
		if(number[i] > n[i]) {
			return true;
		}
		if(number[i] != n[i]) break;
	}

	return false;
}

bool Bint::operator < (const Bint &b) const {
	const std::vector<uint64_t>& n = b.number;
	if (number.size() < n.size()) return true;
	if (number.size() > n.size()) return false;

	for(int i = n.size() - 1; i >= 0; i--) {
		if(number[i] < n[i]) {
			return true;
		}
		if(number[i] != n[i]) break;
	}

	return false;
}

bool Bint::operator <= (const Bint &b) const {
	const std::vector<uint64_t>& n = b.number;
	if (number.size() < n.size()) return true;
	if (number.size() > n.size()) return false;

	for(int i = n.size() - 1; i >= 0; i--) {
		if(number[i] < n[i]) {
			return true;
		} else if(number[i] != n[i]) {
			return false;
		}
	}

	return true;
}

bool Bint::operator >= (const Bint &b) const {
	const std::vector<uint64_t>& n = b.number;
	if (number.size() < n.size()) return false;
	if (number.size() > n.size()) return true;

	for(int i = n.size() - 1; i >= 0; i--) {
		if(number[i] > n[i]) {
			return true;
		} else if(number[i] != n[i]) {
			return false;
		}
	}

	return true;
}

void Bint::addUintWithCarry(uint64_t& operand1res, const uint64_t& operand2, bool& carry) const {
	uint64_t bigCarry = (operand1res & 1) + (operand2 & 1) + carry;
	uint64_t result = (operand1res >> 1) + (operand2 >> 1) + (bigCarry >> 1);
	carry = (bool)(result & 0x8000000000000000);
	result <<= 1;
	result |= (bigCarry & 1);
	operand1res = result;
}

Bint::operator std::string() const {
	return this->toString();
}

std::string Bint::bin() const {
	return "0b" + base2(1);
}

std::string Bint::base2(const uint64_t base) const {
	uint64_t mask = (1 << base) - 1;
	std::string s = "";
	const std::string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	Bint a(*this);
	int j = a.number.size() << 6;
	const int limit = j / base;
	const int rmd = j % base;
	j = 0;
	Bint zero;

	for(int i = 0; i < limit; i++) {
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
	const std::string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
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

		for(int j = current.size() - 1; j >= 0; j--) {
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
			while(current) {
				rmd = current % 10;
				current = current / 10;
				s.push_back(alphabet[rmd]);
			}
			s.push_back(':');
		} else {
			s.push_back(alphabet[rmd]);
		}

		std::reverse(res.begin(), res.end());
		current = res;
	}

	if (s.size() == 0) return "0";
	if (isBaseBig) s.pop_back();
	if (neg) s += '-';

	std::reverse(s.begin(), s.end());

	if (base == 10) return s;
	return s + "_b" + std::to_string(base);
}

Bint Bint::operator * (const Bint& a) const {
	Bint b = *this;
	b *= a;
	return b;
}

Bint& Bint::operator *= (const Bint& a) {
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

	for(int j = 0; j < (int)bin.size(); j++) {
		for (int i = 0; i < (int)number.size(); i++) {
			Bint b;
			// add zeros
			for (int k = 0; k < i+j; k++) {
				b.number.push_back(0);
			}

			uint64_t opH = number[i];	
			uint64_t opL = bin[j];	
			mult(opH, opL);
			b.number[i+j] = opL;
			if (opH) {
				b.number.push_back(opH);
				if (opH & 0x8000000000000000) {
					b.number.push_back(0);
				}
			} else {
				if (opL & 0x8000000000000000) {
					b.number.push_back(0);
				}
			}

			c += b;
		}

	}

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
		resH++;
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

Bint& Bint::bitOperation(const Bint& a, std::function<uint64_t(uint64_t&,const uint64_t&)>&& lambda) {
	const std::vector<uint64_t>& bin = a.number;
	extendNumberBySizeOf(*this, a);

	for(int j = 0; j < (int)bin.size(); j++) {
		number[j] = lambda(number[j], bin[j]);
	}

	return *this;
}

Bint Bint::operator | (const Bint& a) const {
	Bint b(a);
	b |= *this;
	return b;
}

Bint& Bint::operator |= (const Bint& a) {
	return bitOperation(a, [](auto a, auto b) { return a | b; });
}

Bint Bint::operator & (const Bint& a) const {
	Bint b(a);
	b &= *this;
	return b;
}

Bint& Bint::operator &= (const Bint& a) {
	return bitOperation(a, [](auto a, auto b) { return a & b; });
}

Bint Bint::operator ^ (const Bint& a) const {
	Bint b(a);
	b |= *this;
	return b;
}

Bint& Bint::operator ^= (const Bint& a) {
	return bitOperation(a, [](auto a, auto b) { return a ^ b; });
}

Bint Bint::operator - (const Bint& a) const {
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

uint64_t Bint::div(const uint64_t& dividend, const uint64_t& divisor, uint64_t& prevRmd) const {
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

Bint Bint::operator >> (const int shift) const {
	Bint b = *this;
	b >>= shift;
	return b;
}

Bint& Bint::operator >>= (const int shift) {
	int sh = shift;
	if (sh > 63) {
		int q = sh / 64; // container size specific
		sh %= 64;
		// check q limits
		if (q >= (int)number.size()) {
			number.clear();
			number.push_back(0);
			return *this;
		} else {
			number.erase(number.begin(), number.begin() + q);
		}
	}

	int neg = isNegative();

	uint64_t mask = (1 << sh) - 1;
	int maskShift = 64 - sh;
	uint64_t carry = 0;

	for (int i = number.size() - 1; i >= 0; --i) {
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
	int sh = shift;
	if (sh > 63) {
		int q = sh / 64;
		sh %= 64;
		// check q limits
		if (q >= (int)number.size()) {
			number.clear();
			number.push_back(0);
			return *this;
		} else {
			number.erase(number.begin(), number.begin() + q);
		}
	}

	uint64_t mask = (1 << sh) - 1;
	int maskShift = 64 - sh;
	uint64_t carry = 0;

	for (int i = number.size() - 1; i >= 0; --i) {
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

Bint Bint::operator << (const int shift) const {
	Bint b = *this;
	b <<= shift;
	return b;
}

Bint& Bint::operator <<= (const int shift) {
	int sh = shift;
	int q = 0;
	if (sh > 63) { // size specific
		q = sh / 64;
		sh %= 64;
	}
	bool neg = isNegative();
	uint64_t mask = ~(((uint64_t)-1) >> sh);
	int maskShift = 64 - sh; // size specific
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

bool Bint::compare(const Bint& a, bool b, bool c, std::function<bool(const uint64_t&,const uint64_t&)>&& lambda) {
	const std::vector<uint64_t>& n = a.number;
	if (number.size() < n.size()) return b;
	if (number.size() > n.size()) return c;

	for(int i = n.size() - 1; i >= 0; i--) {
		if(!lambda(number[i], n[i])) {
			return false;
		}
	}

	return true;
}

Bint Bint::operator / (const Bint& a) const {
	Bint b = *this;
	b /= a;
	return b;
}

// c - rmd, res - quot, a - divisor
void Bint::div(Bint& rmdDividend, Bint& resQuot, const Bint& divisor) const {

	Bint& a = rmdDividend; 
	Bint& b = resQuot;

	if (a < divisor) {
		return;
	}

	Bint d = divisor;
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
	while(d >= divisor) {
		b <<= 1;
		if (d <= a) {
			b.number[0] |= 1;
			a -= d;
		} 
		d >>= 1;
	}

}

Bint& Bint::operator /= (const Bint& a) {

	Bint c = *this;
	Bint res;

	div(c, res, a);

	//this->neg ^= a.neg;
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

Bint Bint::operator ~ () const {
	Bint a(*this);
	std::vector<uint64_t>& number = a.number;
	for(auto& item : number) {
		item = ~item;
	}
	return a;
}

bool Bint::isNegative() const {
	uint64_t last = number.back();	
	last >>= 63; // size specific
	return last;
}

Bint Bint::operator - () const { // prefix
	Bint r(*this);
	r = ~r + 1;
	return r;
}


////////////////////////////////////////////////////////////////////////
//            INPUT-OUTPUT FUNCTIONS
////////////////////////////////////////////////////////////////////////

std::ostream& operator << (std::ostream& strm, Bint& a) {
	return strm << a.toString(); 
}

std::istream& operator >> (std::istream& strm, Bint& a) {
    std::string s;
    strm >> s;
    a = s; 
    return strm;
}


} // namespace
