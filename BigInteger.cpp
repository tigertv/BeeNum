 /*
 * This file is part of the big-integer (https://github.com/tigertv/big-integer).
 * Copyright (c) 2020 Max Vetrov(tigertv).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <bits/stdc++.h>
#include <cstdlib>
#include "BigInteger.h"


namespace TigerTV {


void BigInteger::mult10() {
	BigInteger k = *this;
	*this <<= 3;
	k <<= 1;
	(*this) += k;
}

void BigInteger::addDigit(char c) {
	c = c & 0xf;
	uint64_t i = (uint64_t)c;
	if (i > 9) i = 0;

	BigInteger b;
	b.number[0] = i;
	*this += b;
}

BigInteger::BigInteger() {
	number.push_back(0);
}

BigInteger::BigInteger(const std::string& decimal) {
	number.push_back(0);
	setDecimal(decimal);
}

BigInteger::BigInteger(const char* decimal) {
	number.push_back(0);
	setDecimal(decimal);
}

BigInteger::BigInteger(const uint64_t num) {
	number.push_back(num);
}

void BigInteger::setDecimal(const std::string& s) {

	number.clear();
	number.push_back(0);

	for(const char& c : s) {
		this->mult10();
		this->addDigit(c);
	}
}

BigInteger BigInteger::operator + (const BigInteger& a) {
	BigInteger b = *this;
	b += a;
	return b;
}

BigInteger& BigInteger::operator += (const BigInteger& a) {

	const std::vector<uint64_t>& bin = a.number;

	if (number.size() < bin.size()) {
		int diff = bin.size() - number.size();
		for(int i = 0; i < diff; i++) {
			number.push_back(0);
		}
	}

	int j = 0;
	bool carry = false;

	for(; j < (int)bin.size(); j++) {
		addUintWithCarry(number[j], bin[j], carry);
	}

	if (carry) {
		for(int i = j; i < (int)number.size(); i++) {
			addUintWithCarry(number[i], 0, carry);
			if (!carry) break;
		}

		if (carry) {
			number.push_back(1);
		}
	}

	return *this;
}

void BigInteger::addUintWithCarry(uint64_t& operand1res, const uint64_t& operand2, bool& carry) {
	uint64_t bigCarry = (operand1res & 1) + (operand2 & 1) + carry;
	uint64_t result = (operand1res >> 1) + (operand2 >> 1) + (bigCarry >> 1);
	carry = (bool)(result & 0x8000000000000000);
	result <<= 1;
	result |= (bigCarry & 1);
	operand1res = result;
}

BigInteger::operator std::string() {
	return this->toString();
}

std::string BigInteger::toBinString() {
	//return toBaseString(2);
	//*
	// binary number output, '0' and '1'
	std::string s = "";
	uint64_t current;

	int j = 0;
	for(; j < (int)number.size() - 1; j++) {
		current = number[j];
		for (int i = 0; i < 64; i++){
			s += (current & 1) + 0x30;
			current >>= 1;
		}
	}

	current = number[j];
	while(current){
		s += (current & 1) + 0x30;
		current >>= 1;
	}

	if (s.size() == 0) return "0";
	std::reverse(s.begin(), s.end());
	return s;
	//*/
}

std::string BigInteger::toString() {
	return toBaseString(10);
}

std::string BigInteger::toHexString() {
	return toBaseString(16);
}

std::string BigInteger::toBaseString(uint64_t base) {

	std::string s = "";
	std::vector<uint64_t>current = number;

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

		if (rmd < 10) {
			s += '0'+(char)rmd;
		} else {
			s += 'a'+(char)(rmd-10);
		}

		current.clear();
		std::reverse(res.begin(), res.end());
		current = res;
	}

	if (s.size() == 0) return "0";
	std::reverse(s.begin(), s.end());
	return s;
}

BigInteger BigInteger::operator * (const BigInteger& a) {
	BigInteger b = *this;
	b *= a;
	return b;
}

BigInteger& BigInteger::operator *= (const BigInteger& a) {

	const std::vector<uint64_t>& bin = a.number;

	BigInteger c;

	for(int j = 0; j < (int)bin.size(); j++) {
		for (int i = 0; i < (int)number.size(); i++) {
			BigInteger b;
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
			}

			c += b;
		}

	}
	
	this->number = c.number;
	return (*this);
}

void BigInteger::mult(uint64_t& operand1ResHigh, uint64_t& operand2ResLow) {
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

BigInteger& BigInteger::operator ++ () { // prefix
	BigInteger c;
	c.number[0] = 1;
	*this += c;
	return *this;
}

BigInteger BigInteger::operator ++ (int) { // postfix
	BigInteger b = *this; 
	BigInteger c;
	c.number[0] = 1;
	*this += c;
	return b;
}

BigInteger& BigInteger::bitOperation(const BigInteger& a, std::function<uint64_t(uint64_t&,const uint64_t&)>&& lambda) {
	const std::vector<uint64_t>& bin = a.number;
	if (number.size() < bin.size()) {
		int diff = bin.size() - number.size();
		for(int i = 0; i < diff; i++) {
			number.push_back(0);
		}
	}

	for(int j = 0; j < (int)bin.size(); j++) {
		number[j] = lambda(number[j], bin[j]);
	}

	return *this;
}

BigInteger BigInteger::operator | (const BigInteger& a) {
	BigInteger b = a;
	b |= *this;
	return b;
}

BigInteger& BigInteger::operator |= (const BigInteger& a) {
	return bitOperation(a, [](auto a, auto b) { return a | b; });
}

BigInteger BigInteger::operator & (const BigInteger& a) {
	BigInteger b = a;
	b &= *this;
	return b;
}

BigInteger& BigInteger::operator &= (const BigInteger& a) {
	return bitOperation(a, [](auto a, auto b) { return a & b; });
}

BigInteger BigInteger::operator ^ (const BigInteger& a) {
	BigInteger b = a;
	b |= *this;
	return b;
}

BigInteger& BigInteger::operator ^= (const BigInteger& a) {
	return bitOperation(a, [](auto a, auto b) { return a ^ b; });
}

BigInteger BigInteger::operator - (const BigInteger& a) {
	BigInteger b = *this;
	b -= a;
	return b;
}

BigInteger& BigInteger::operator -= (const BigInteger& a) {

	const std::vector<uint64_t>& bin = a.number;

	if (bin.size() > number.size()) {
		int diff = bin.size() - number.size();
		for(int i = 0; i < diff; i++) {
			number.push_back(-1);
		}
	}

	int j = 0;
	bool borrow = false;

	for(; j < (int)bin.size(); j++) {
		uint64_t t = bin[j] + borrow;
		borrow = number[j] < t;
		number[j] -= t;
	}

	if (borrow) {
		for(; j < (int)number.size(); j++) {
			if (number[j] == 0) {
				number[j] -= 1;
			} else {
				number[j] -= 1;
				break;
			}
		}
	}

	eraseLeadingZeros();

	return *this;
}

std::ostream& operator << (std::ostream &strm, BigInteger &a) {
	return strm << a.toString(); 
}

BigInteger& BigInteger::operator -- () { // prefix
	BigInteger c;
	c.number[0] = 1;
	*this -= c;
	return *this;
}

BigInteger BigInteger::operator -- (int) { // postfix
	BigInteger b = *this; 
	BigInteger c;
	c.number[0] = 1;
	*this -= c;
	return b;
}

std::istream& operator >> (std::istream& strm, BigInteger& a) {
    std::string s;
    strm >> s;
	BigInteger b;
	b.setDecimal(s);
    a = b; 
    return strm;
}

uint64_t BigInteger::div(const uint64_t& dividend, const uint64_t& divisor, uint64_t& prevRmd) {
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

BigInteger BigInteger::operator >> (const int shift) {
	BigInteger b = *this;
	b >>= shift;
	return b;
}

BigInteger& BigInteger::operator >>= (const int shift) {
	int sh = shift;
	if (sh > 63) {
		int q = sh / 64;
		sh %= 64;
		number.erase(number.begin(), number.begin() + q);
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

	eraseLeadingZeros();
	return *this;
}

BigInteger BigInteger::operator << (const int shift) {
	BigInteger b = *this;
	b <<= shift;
	return b;
}

BigInteger& BigInteger::operator <<= (const int shift) {
	int sh = shift;
	int q = 0;
	if (sh > 63) {
		q = sh / 64;
		sh %= 64;
	}

	uint64_t mask = ~(((uint64_t)-1) >> sh);
	int maskShift = 64 - sh;
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
		carry >>= maskShift;
		number.push_back(carry);
	}

	if (q) {
		std::vector<uint64_t> a(q, 0);
		number.insert(number.begin(), a.begin(), a.end());
	}

	return *this;
}

bool BigInteger::operator < (const BigInteger& a) {
	const std::vector<uint64_t>& n = a.number;
	if (number.size() < n.size()) return true;
	if (number.size() > n.size()) return false;

	for(int i = n.size() - 1; i >= 0; i--) {
		if(number[i] < n[i]) {
			return true;
		}
	}

	return false;
}

bool BigInteger::operator <= (const BigInteger& a) {
	const std::vector<uint64_t>& n = a.number;
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

bool BigInteger::operator > (const BigInteger& a) {
	const std::vector<uint64_t>& n = a.number;
	if (number.size() < n.size()) return false;
	if (number.size() > n.size()) return true;

	for(int i = n.size() - 1; i >= 0; i--) {
		if(number[i] > n[i]) {
			return true;
		}
	}

	return false;
}

bool BigInteger::operator >= (const BigInteger& a) {
	const std::vector<uint64_t>& n = a.number;
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

bool BigInteger::operator == (const BigInteger& a) {
	return compare(a, false, false, [](auto a, auto b) { return a == b; });
}

bool BigInteger::operator != (const BigInteger& a) {
	const std::vector<uint64_t>& n = a.number;
	if (number.size() < n.size()) return true;
	if (number.size() > n.size()) return true;

	for(int i = n.size() - 1; i >= 0; i--) {
		if(number[i] != n[i]) {
			return true;
		}
	}

	return false;
}

bool BigInteger::compare(const BigInteger& a, bool b, bool c, std::function<bool(const uint64_t&,const uint64_t&)>&& lambda) {
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

BigInteger BigInteger::operator / (const BigInteger& a) {
	BigInteger b = *this;
	b /= a;
	return b;
}

void BigInteger::div(BigInteger& c, BigInteger& res, const BigInteger& a) {

	BigInteger b = a;
	std::vector<uint64_t>& bin = b.number;

	int diff = number.size() - bin.size();

	if (diff < 0) {
		return; 
	}

	for(int i = diff; i > 0; --i) {
		bin.insert(bin.begin(), 0);
	}

	if (b < c) {
		while(b < c) {
			b <<= 1;
		}
		b >>= 1;
	} else {
		while(b > c) {
			b >>= 1;
		}
	}

	while(b != a) {
		res <<= 1;
		if (b <= c) {
			res.number[0] |= 1;
			c -= b;
		} 
		b >>= 1;
	}

	res <<= 1;
	if (c >= b) {
		res.number[0] |= 1;
	}

}

BigInteger& BigInteger::operator /= (const BigInteger& a) {

	BigInteger c = *this;
	BigInteger res;

	div(c, res, a);

	this->number = res.number;
	return (*this);
}

BigInteger BigInteger::operator % (const BigInteger& a) {
	BigInteger b = *this;
	b %= a;
	return b;
}

BigInteger& BigInteger::operator %= (const BigInteger& a) {

	BigInteger c = *this;
	BigInteger res;

	div(c, res, a);

	this->number = c.number;
	return (*this);
}

void BigInteger::eraseLeadingZeros() {
	for (int i = number.size() - 1; i > 0; i--) {
		if (number.back() != 0) break;
		number.erase(number.end()-1);
	}
}

BigInteger& BigInteger::operator ~ () {
	for(auto& item : number) {
		item = ~item;
	}
	return *this;
}


} // namespace
