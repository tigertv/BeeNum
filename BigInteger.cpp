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

#include <iostream>
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
	uint32_t i = (int32_t)c;
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
		for (int i = 0; i < 31; i++){
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

BigInteger BigInteger::add(const BigInteger& a, const BigInteger& b) {
	BigInteger res;
	res = a;
	res += b;
	return res;
}

BigInteger BigInteger::andOp(const BigInteger& a, const BigInteger& b) {
	BigInteger res;
	return res;
}

BigInteger BigInteger::operator + (const BigInteger& a) {
	return add(*this, a);
}

BigInteger& BigInteger::operator += (const BigInteger& a) {
	bool carry = false;

	const std::vector<uint32_t>& bin = a.number;

	if (number.size() < bin.size()) {
		int diff = bin.size() - number.size();
		for(int i = 0; i < diff; i++) {
			number.push_back(0);
		}
	}

	int j = 0;
	for(; j < bin.size(); j++) {
		number[j] += bin[j] + carry;
		carry = takeCarry(number[j]);
	}

	if (carry) {
		for(int i = j; i < number.size(); i++) {
			number[i] += carry;	
			carry = takeCarry(number[i]);
			if (!carry) break;
		}

		if (carry) {
			number.push_back(1);
		}
	}

	return *this;
}

BigInteger BigInteger::operator & (const BigInteger& a) {
	BigInteger b = a;
	b &= *this;
	return b;
}

BigInteger& BigInteger::operator &= (const BigInteger& a) {
	const std::vector<uint32_t>& bin = a.number;
	if (number.size() < bin.size()) {
		int diff = bin.size() - number.size();
		for(int i = 0; i < diff; i++) {
			number.push_back(0);
		}
	}

	for(int j = 0; j < bin.size(); j++) {
		number[j] &= bin[j];
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
			number[i] <<= 1;
			number[i] += carry;
			carry = takeCarry(number[i]);
		}
		if (carry) {
			number.push_back(1);
			carry = false;
		}
	}
	return *this;
}

bool BigInteger::takeCarry(uint32_t& num) {
	if (num & 0x80000000) {
		num &= 0x7fffffff;
		return true;
	}
	return false;
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
			uint64_t c = ((uint64_t)current[j]) + (rmd << 31);
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
