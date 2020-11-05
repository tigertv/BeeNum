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
	uint32_t i = (uint32_t)c;
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

	for(int i = 0;i < s.size(); i++) {
		this->mult10();
		this->addDigit(s[i]);
	}
}

std::string BigInteger::toBinString() {
	// binary number output, '0' and '1'
	std::string s = "";
	uint32_t current;

	int j = 0;
	for(; j < number.size()-1; j++) {
		current = number[j];
		for (int i = 0; i < 32; i++){
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
}

BigInteger BigInteger::andOp(const BigInteger& a, const BigInteger& b) {
	BigInteger res;
	return res;
}

BigInteger BigInteger::operator + (const BigInteger& a) {
	BigInteger b = *this;
	b += a;
	return b;
}

BigInteger& BigInteger::operator += (const BigInteger& a) {

	const std::vector<uint32_t>& bin = a.number;

	if (number.size() < bin.size()) {
		int diff = bin.size() - number.size();
		for(int i = 0; i < diff; i++) {
			number.push_back(0);
		}
	}

	int j = 0;
	bool carry = false;

	for(; j < bin.size(); j++) {
		addUintWithCarry(number[j], bin[j], carry);
	}

	if (carry) {
		for(int i = j; i < number.size(); i++) {
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
		for (int i=0; i < number.size(); i++) {
			uint32_t num = number[i] & 0x80000000;
			number[i] &= 0x7fffffff;
			number[i] <<= 1;
			number[i] += carry;
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

void BigInteger::addUintWithCarry(uint32_t& operand1res, const uint32_t& operand2, bool& carry) {
	uint32_t result = (operand1res & 0x7fffffff) + (operand2 & 0x7fffffff) + carry;
	uint32_t s = ((operand1res & 0x80000000) >> 31) + ((operand2 & 0x80000000) >> 31) + ((result & 0x80000000) >> 31);
	result &= 0x7fffffff;
	result |= ((s & 0x1) << 31);
	carry = (s & 0b10) >> 1;
	operand1res = result;
}

BigInteger::operator std::string() {
	return this->toString();
}

std::string BigInteger::toString() {
	// decimal output
	std::string s = "";
	const uint32_t base = 10;
	std::vector<uint32_t>current = number;

	while(current[0] || (current.size() > 1)) {
		std::vector<uint32_t>res;
		bool notFirst = false;
		uint64_t rmd = 0;

		for(int j = current.size() - 1; j >= 0; j--) {
			uint64_t c = ((uint64_t)current[j]) + (rmd << 32);
			auto d = std::lldiv(c, base);	
			rmd = d.rem;
			if (d.quot) {
				notFirst = true;
			}
			if (notFirst) {
				res.push_back(d.quot);
			}
		}

		if (res.size() == 0) res.push_back(0);

		s += '0'+(char)rmd;
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

	const std::vector<uint32_t>& bin = a.number;

	BigInteger c;

	for(int j = 0; j < bin.size(); j++) {
		for (int i = 0; i < number.size(); i++) {
			BigInteger b;
			// add zeros
			for (int k = 0; k < i+j; k++) {
				b.number.push_back(0);
			}

			uint32_t opH = number[i];	
			uint32_t opL = bin[j];	
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

void BigInteger::mult(uint32_t& operand1ResHigh, uint32_t& operand2ResLow) {
	uint32_t low1 = 0x0000ffff & operand1ResHigh;	
	uint32_t high1 = (0xffff0000 & operand1ResHigh) >> 16;	
	uint32_t low2 = 0x0000ffff & operand2ResLow;	
	uint32_t high2 = (0xffff0000 & operand2ResLow) >> 16;	

	uint32_t ll = low1 * low2;
	uint32_t hh = high1 * high2;

	uint32_t lh = low1 * high2;
	uint32_t hl = high1 * low2;

	uint32_t lhh = (lh & 0xffff0000) >> 16;
	uint32_t lhl = (lh & 0x0000ffff) << 16;

	uint32_t hlh = (hl & 0xffff0000) >> 16;
	uint32_t hll = (hl & 0x0000ffff) << 16;

	uint32_t resL = lhl;
	uint32_t resH = lhh;
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

BigInteger& BigInteger::bitOperation(const BigInteger& a, std::function<uint32_t(uint32_t&,const uint32_t&)>& lambda) {
	const std::vector<uint32_t>& bin = a.number;
	if (number.size() < bin.size()) {
		int diff = bin.size() - number.size();
		for(int i = 0; i < diff; i++) {
			number.push_back(0);
		}
	}

	for(int j = 0; j < bin.size(); j++) {
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
	std::function<uint32_t(uint32_t& a, const uint32_t& b)> s = [](uint32_t& a, const uint32_t& b) -> uint32_t { return a | b; };
	return bitOperation(a, s);
}

BigInteger BigInteger::operator & (const BigInteger& a) {
	BigInteger b = a;
	b &= *this;
	return b;
}

BigInteger& BigInteger::operator &= (const BigInteger& a) {
	std::function<uint32_t(uint32_t& a, const uint32_t& b)> s = [](uint32_t& a, const uint32_t& b) -> uint32_t { return a & b; };
	return bitOperation(a, s);
}

BigInteger BigInteger::operator ^ (const BigInteger& a) {
	BigInteger b = a;
	b |= *this;
	return b;
}

BigInteger& BigInteger::operator ^= (const BigInteger& a) {
	std::function<uint32_t(uint32_t& a, const uint32_t& b)> s = [](uint32_t& a, const uint32_t& b) -> uint32_t { return a ^ b; };
	return bitOperation(a, s);
}

BigInteger BigInteger::operator - (const BigInteger& a) {
	BigInteger b = *this;
	b -= a;
	return b;
}

BigInteger& BigInteger::operator -= (const BigInteger& a) {

	const std::vector<uint32_t>& bin = a.number;

	if (bin.size() > number.size()) {
		int diff = bin.size() - number.size();
		for(int i = 0; i < diff; i++) {
			number.push_back(-1);
		}
	}

	int j = 0;
	bool borrow = false;

	for(; j < bin.size(); j++) {
		uint32_t t = bin[j] + borrow;
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
