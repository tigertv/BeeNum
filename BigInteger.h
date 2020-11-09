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


#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <string>
#include <vector>
#include <functional>
#include <iostream>

class BigInteger {
private:
	std::vector<uint64_t> number;

	void mult10();
	void addDigit(char c);
	void addUintWithCarry(uint64_t& operand1res, const uint64_t& operand2, bool& carry);
	void mult(uint64_t& operand1High, uint64_t& operand2Low);
	uint64_t div(const uint64_t& dividend, const uint64_t& divisor, uint64_t& prevRmd);
	BigInteger& bitOperation(const BigInteger& a, std::function<uint64_t(uint64_t& a,const uint64_t& b)>&& lambda);
	bool compare(const BigInteger& a, bool b, bool c, std::function<bool(const uint64_t&, const uint64_t&)>&& lambda);
	void eraseLeadingZeros();

public:
	BigInteger();
	BigInteger(const char* decimal);
	BigInteger(const uint64_t num);
	BigInteger(const std::string& decimal);

	void setDecimal(const std::string& s);

	std::string toBinString();
	std::string toHexString();
	std::string toString();
	std::string toBaseString(uint64_t base);
	operator std::string();

	// Bit
	BigInteger operator & (const BigInteger& a);
	BigInteger& operator &= (const BigInteger& a);
	BigInteger operator | (const BigInteger& a);
	BigInteger& operator |= (const BigInteger& a);
	BigInteger operator ^ (const BigInteger& a);
	BigInteger& operator ^= (const BigInteger& a);
	BigInteger& operator ~ ();

	// Arithmetic
	BigInteger operator + (const BigInteger& a);
	BigInteger& operator += (const BigInteger& a);
	BigInteger operator ++ (int); // postfix
	BigInteger& operator ++ (); // prefix
	BigInteger operator - (const BigInteger& a);
	BigInteger& operator -= (const BigInteger& a);
	BigInteger operator -- (int); // postfix
	BigInteger& operator -- (); // prefix
	BigInteger operator * (const BigInteger& a);
	BigInteger& operator *= (const BigInteger& a);
	BigInteger operator / (const BigInteger& a);
	BigInteger& operator /= (const BigInteger& a);
	BigInteger operator % (const BigInteger& a);
	BigInteger& operator %= (const BigInteger& a);

	// Shifts
	BigInteger operator << (const int shift);
	BigInteger& operator <<= (const int shift);
	BigInteger operator >> (const int shift);
	BigInteger& operator >>= (const int shift);

	// Comparison
	bool operator < (const BigInteger& a);
	bool operator <= (const BigInteger& a);
	bool operator > (const BigInteger& a);
	bool operator >= (const BigInteger& a);
	bool operator == (const BigInteger& a);
	bool operator != (const BigInteger& a);

	// Input-output
	friend std::ostream& operator << (std::ostream &strm, BigInteger &a);
	friend std::istream& operator >> (std::istream& strm, BigInteger& a); 
};

#endif
