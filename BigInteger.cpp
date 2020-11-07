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


BigInteger BigInteger::operator << (const int shift) {
	BigInteger b = *this;
	b <<= shift;
	return b;
}

BigInteger& BigInteger::operator <<= (const int shift) {
	bool carry = false;
	for (int j=0; j < shift; j++) {
		for (uint64_t& n : number) {
			uint64_t num = n & 0x8000000000000000;
			n &= 0x7fffffffffffffff;
			n <<= 1;
			n += carry;
			carry = false;
			if (num) carry = true;
		}
		if (carry) {
			number.push_back(1);
			carry = false;
		}
	}
	return *this;
}

void BigInteger::addUintWithCarry(uint64_t& operand1res, const uint64_t& operand2, bool& carry) {
	uint64_t result = (operand1res & 0x7fffffffffffffff) + (operand2 & 0x7fffffffffffffff) + carry;
	uint64_t s = ((operand1res & 0x8000000000000000) >> 63) + ((operand2 & 0x8000000000000000) >> 63) + ((result & 0x8000000000000000) >> 63);
	result &= 0x7fffffffffffffff;
	result |= ((s & 0x1) << 63);
	carry = (s & 0b10) >> 1;
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

BigInteger& BigInteger::bitOperation(const BigInteger& a, std::function<uint64_t(uint64_t&,const uint64_t&)>& lambda) {
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
	std::function<uint64_t(uint64_t& a, const uint64_t& b)> s = [](uint64_t& a, const uint64_t& b) -> uint64_t { return a | b; };
	return bitOperation(a, s);
}

BigInteger BigInteger::operator & (const BigInteger& a) {
	BigInteger b = a;
	b &= *this;
	return b;
}

BigInteger& BigInteger::operator &= (const BigInteger& a) {
	std::function<uint64_t(uint64_t& a, const uint64_t& b)> s = [](uint64_t& a, const uint64_t& b) -> uint64_t { return a & b; };
	return bitOperation(a, s);
}

BigInteger BigInteger::operator ^ (const BigInteger& a) {
	BigInteger b = a;
	b |= *this;
	return b;
}

BigInteger& BigInteger::operator ^= (const BigInteger& a) {
	std::function<uint64_t(uint64_t& a, const uint64_t& b)> s = [](uint64_t& a, const uint64_t& b) -> uint64_t { return a ^ b; };
	return bitOperation(a, s);
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
	for (int j = 0; j < shift; j++) {
		bool carry = false;
		for (int i = number.size() - 1; i >= 0; i--) {
			bool nextCarry = number[i] & 1;
			number[i] >>= 1;
			if (carry) {
				number[i] |= 0x8000000000000000;
			}
			carry = nextCarry;
		}
	}

	for (int i = number.size() - 1; i > 0; i--) {
		if (number[i] == 0) {
			number.erase(number.end()-1);
			break;
		}
	}

	return *this;
}
