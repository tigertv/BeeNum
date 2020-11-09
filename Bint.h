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


namespace TigerTV {


class Bint {
private:
	std::vector<uint64_t> number;

	void mult10();
	void addDigit(char c);
	void addUintWithCarry(uint64_t& operand1res, const uint64_t& operand2, bool& carry);
	void mult(uint64_t& operand1High, uint64_t& operand2Low);
	uint64_t div(const uint64_t& dividend, const uint64_t& divisor, uint64_t& prevRmd);
	Bint& bitOperation(const Bint& a, std::function<uint64_t(uint64_t& a,const uint64_t& b)>&& lambda);
	bool compare(const Bint& a, bool b, bool c, std::function<bool(const uint64_t&, const uint64_t&)>&& lambda);
	void eraseLeadingZeros();
	void div(Bint& c, Bint& res, const Bint& a);

public:
	Bint();
	Bint(const char* decimal);
	Bint(const uint64_t num);
	Bint(const std::string& decimal);

	void setDecimal(const std::string& s);

	std::string toBinString();
	std::string toHexString();
	std::string toString();
	std::string toBaseString(uint64_t base);
	operator std::string();

	// Bit
	Bint operator & (const Bint& a);
	Bint& operator &= (const Bint& a);
	Bint operator | (const Bint& a);
	Bint& operator |= (const Bint& a);
	Bint operator ^ (const Bint& a);
	Bint& operator ^= (const Bint& a);
	Bint& operator ~ ();

	// Arithmetic
	Bint operator + (const Bint& a);
	Bint& operator += (const Bint& a);
	Bint operator ++ (int); // postfix
	Bint& operator ++ (); // prefix
	Bint operator - (const Bint& a);
	Bint& operator -= (const Bint& a);
	Bint operator -- (int); // postfix
	Bint& operator -- (); // prefix
	Bint operator * (const Bint& a);
	Bint& operator *= (const Bint& a);
	Bint operator / (const Bint& a);
	Bint& operator /= (const Bint& a);
	Bint operator % (const Bint& a);
	Bint& operator %= (const Bint& a);

	// Shifts
	Bint operator << (const int shift);
	Bint& operator <<= (const int shift);
	Bint operator >> (const int shift);
	Bint& operator >>= (const int shift);

	// Comparison
	bool operator < (const Bint& a);
	bool operator <= (const Bint& a);
	bool operator > (const Bint& a);
	bool operator >= (const Bint& a);
	bool operator == (const Bint& a);
	bool operator != (const Bint& a);

	// Input-output
	friend std::ostream& operator << (std::ostream &strm, Bint &a);
	friend std::istream& operator >> (std::istream& strm, Bint& a); 
};


} // namespace

#endif
