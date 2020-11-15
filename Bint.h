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


#ifndef TIGERTV_BIG_INTEGER_H
#define TIGERTV_BIG_INTEGER_H

#include <string>
#include <vector>
#include <functional>
#include <iostream>


namespace TigerTV {


class Bint {
private:
	std::vector<uint64_t> number;

	void addUintWithCarry(uint64_t& operand1res, const uint64_t& operand2, bool& carry) const;
	void mult(uint64_t& operand1High, uint64_t& operand2Low) const;
	Bint& bitOperation(const Bint& a, std::function<uint64_t(uint64_t& a,const uint64_t& b)>&& lambda);
	bool compare(const Bint& a, bool b, bool c, std::function<bool(const uint64_t&, const uint64_t&)>&& lambda); // not used now
	void eraseLeadingSign();
	void extendNumberBySizeOf(Bint& extNumber, const Bint&a);
	uint64_t div(const uint64_t& dividend, const uint64_t& divisor, uint64_t& prevRmd) const;
	void div(Bint& c, Bint& res, const Bint& a) const;
	void setDecimal(const std::string& s);
	bool isNegative() const;

public:
	// Constructors
	Bint();
	Bint(int num);
	Bint(const char* decimal);
	Bint(const std::string& decimal);

	// String representation
	std::string bin() const;
	std::string hex() const;
	std::string toString() const;
	std::string base(uint64_t base) const;
	operator std::string() const;

	// Bit
	Bint operator & (const Bint& a) const;
	Bint& operator &= (const Bint& a);
	Bint operator | (const Bint& a) const;
	Bint& operator |= (const Bint& a);
	Bint operator ^ (const Bint& a) const;
	Bint& operator ^= (const Bint& a);
	Bint operator ~ () const;

	// Arithmetic
	Bint operator + (const Bint& a) const;
	Bint& operator += (const Bint& a);
	Bint operator ++ (int); // postfix
	Bint& operator ++ (); // prefix
	Bint operator - (const Bint& a) const;
	Bint& operator -= (const Bint& a);
	Bint operator -- (int); // postfix
	Bint& operator -- (); // prefix
	Bint operator * (const Bint& a) const;
	Bint& operator *= (const Bint& a);
	Bint operator / (const Bint& a) const;
	Bint& operator /= (const Bint& a);
	Bint operator % (const Bint& a) const;
	Bint& operator %= (const Bint& a);
	Bint operator - () const; // prefix

	// Shifts
	Bint operator << (const int shift) const;
	Bint& operator <<= (const int shift);
	Bint operator >> (const int shift) const;
	Bint& operator >>= (const int shift);

	// Comparison
	bool operator <= (const Bint &b) const;
	bool operator >= (const Bint &b) const;
	bool operator == (const Bint &b) const;
	bool operator != (const Bint &b) const;
	bool operator < (const Bint &b) const;
	bool operator > (const Bint &b) const;
};

// Input-output
std::ostream& operator << (std::ostream& strm, Bint& a);
std::istream& operator >> (std::istream& strm, Bint& a); 

} // namespace

#endif
