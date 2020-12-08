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
	static const std::string alphabet;

	void addUintWithCarry(uint64_t& operand1res, const uint64_t operand2, bool& carry) const;
	void mult(uint64_t& operand1High, uint64_t& operand2Low) const;
	Bint& bitOperation(const Bint& a, std::function<uint64_t(uint64_t& a,const uint64_t& b)>&& lambda);
	Bint& bitOperation(const int64_t a, std::function<uint64_t(uint64_t& a,const uint64_t& b)>&& lambda);
	void eraseLeadingSign();
	void extendNumberBySizeOf(Bint& extNumber, const Bint&a);
	uint64_t div(const uint64_t& dividend, const uint64_t& divisor, uint64_t& prevRmd) const;
	void div(Bint& rmdDividend, Bint& resQuot, const Bint& divisor) const;
	void setDecimal(const std::string& s);
	void setNumber(const std::string& num, int base);
	bool isNegative() const;
	std::string base2(const uint64_t base) const;
	Bint& urshift(const uint64_t shift);
	void addUintAt(uint64_t index, uint64_t operand);

public:
	// Constructors
	Bint();
	Bint(int64_t num);
	Bint(const char* decimal);
	Bint(const std::string& decimal);

	// String representation
	std::string bin() const;
	std::string hex() const;
	std::string oct() const;
	std::string toString() const;
	std::string base(const uint64_t base) const;
	operator std::string() const;

	// Bits
	Bint operator & (const Bint& a) const;
	Bint& operator &= (const Bint& a);
	Bint operator | (const Bint& a) const;
	Bint& operator |= (const Bint& a);
	Bint operator ^ (const Bint& a) const;
	Bint& operator ^= (const Bint& a);

	Bint operator & (const int64_t a) const;
	Bint& operator &= (const int64_t a);
	Bint operator | (const int64_t a) const;
	Bint& operator |= (const int64_t a);
	Bint operator ^ (const int64_t a) const;
	Bint& operator ^= (const int64_t a);

	Bint operator ~ () const; // prefix

	// Arithmetics
	Bint operator ++ (int); // postfix
	Bint& operator ++ (); // prefix
	Bint operator -- (int); // postfix
	Bint& operator -- (); // prefix
	Bint operator - () const; // prefix

	Bint operator + (const Bint& a) const;
	Bint& operator += (const Bint& a);
	Bint operator - (const Bint& a) const;
	Bint& operator -= (const Bint& a);
	Bint operator * (const Bint& a) const;
	Bint& operator *= (const Bint& a);
	Bint operator / (const Bint& a) const;
	Bint& operator /= (const Bint& a);
	Bint operator % (const Bint& a) const;
	Bint& operator %= (const Bint& a);

	Bint operator + (const int64_t a) const;
	Bint& operator += (const int64_t a);
	Bint operator - (const int64_t a) const;
	Bint& operator -= (const int64_t a);
	Bint operator * (const int64_t a) const;
	Bint& operator *= (const int64_t a);
	Bint operator / (const int64_t a) const;
	Bint& operator /= (const int64_t a);
	Bint operator % (const int64_t a) const;
	Bint& operator %= (const int64_t a);

	// Shifts
	Bint operator << (const uint64_t shift) const;
	Bint& operator <<= (const uint64_t shift);
	Bint operator >> (const uint64_t shift) const;
	Bint& operator >>= (const uint64_t shift);

	// Comparison
	bool operator <= (const Bint &b) const;
	bool operator >= (const Bint &b) const;
	bool operator == (const Bint &b) const;
	bool operator != (const Bint &b) const;
	bool operator < (const Bint &b) const;
	bool operator > (const Bint &b) const;

	bool operator <= (const int64_t a) const;
	bool operator >= (const int64_t a) const;
	bool operator == (const int64_t a) const;
	bool operator != (const int64_t a) const;
	bool operator < (const int64_t a) const;
	bool operator > (const int64_t a) const;
};

// Input-output
std::ostream& operator << (std::ostream& strm, const Bint& a);
std::istream& operator >> (std::istream& strm, Bint& a); 

// Left side operators for int 
// Arithmetics
Bint operator + (const int64_t a, const Bint& b);
Bint operator - (const int64_t a, const Bint& b);
Bint operator * (const int64_t a, const Bint& b);
Bint operator / (const int64_t a, const Bint& b);
Bint operator % (const int64_t a, const Bint& b);
// Comparison
bool operator <= (const int64_t a, const Bint &b);
bool operator >= (const int64_t a, const Bint &b);
bool operator == (const int64_t a, const Bint &b);
bool operator != (const int64_t a, const Bint &b);
bool operator < (const int64_t a, const Bint &b);
bool operator > (const int64_t a, const Bint &b);
// Bits
Bint operator & (const int64_t a, const Bint &b);
Bint operator | (const int64_t a, const Bint &b);
Bint operator ^ (const int64_t a, const Bint &b);


} // namespace

#endif
