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

#ifndef TIGERTV_BIG_RATIONAL_H
#define TIGERTV_BIG_RATIONAL_H

#include <string>
#include "Bint.h"


namespace TigerTV {

class Brat {
private:
	Bint numerator;
	Bint denominator;

	void simplify();

public:
	// Constructors
	//Brat();
	Brat(const Bint& numerator, const Bint& denominator);

	// String representation
	std::string toString() const;
	std::string base(const uint64_t base) const;
	std::string point(const uint64_t num) const;
	operator std::string() const;

	// Arithmetics
	Brat operator ++ (int); // postfix
	Brat& operator ++ (); // prefix
	Brat operator -- (int); // postfix
	Brat& operator -- (); // prefix
	Brat operator - () const; // prefix
	Brat operator + (const Brat& a) const;
	Brat& operator += (const Brat& a);
	Brat operator - (const Brat& a) const;
	Brat& operator -= (const Brat& a);
	Brat operator * (const Brat& a) const;
	Brat& operator *= (const Brat& a);
	Brat operator / (const Brat& a) const;
	Brat& operator /= (const Brat& a);

	// Comparison
	bool operator <= (const Brat &b) const;
	bool operator >= (const Brat &b) const;
	bool operator == (const Brat &b) const;
	bool operator != (const Brat &b) const;
	bool operator < (const Brat &b) const;
	bool operator > (const Brat &b) const;
/*
	Bint operator + (const int64_t a) const;
	Bint& operator += (const int64_t a);
	Bint operator - (const int64_t a) const;
	Bint& operator -= (const int64_t a);
	Bint operator * (const int64_t a) const;
	Bint& operator *= (const int64_t a);
	Bint operator / (const int64_t a) const;
	Bint& operator /= (const int64_t a);


	bool operator <= (const int64_t a) const;
	bool operator >= (const int64_t a) const;
	bool operator == (const int64_t a) const;
	bool operator != (const int64_t a) const;
	bool operator < (const int64_t a) const;
	bool operator > (const int64_t a) const;
	//*/
};

// Input-output
std::ostream& operator << (std::ostream& strm, const Brat& a);
/*
std::istream& operator >> (std::istream& strm, Brat& a); 
//*/
// Left side operators for int 
// Arithmetics
Brat operator + (const int64_t a, const Brat& b);
Brat operator - (const int64_t a, const Brat& b);
Brat operator * (const int64_t a, const Brat& b);
Brat operator / (const int64_t a, const Brat& b);
/*
// Comparison
bool operator <= (const int64_t a, const Bint &b);
bool operator >= (const int64_t a, const Bint &b);
bool operator == (const int64_t a, const Bint &b);
bool operator != (const int64_t a, const Bint &b);
bool operator < (const int64_t a, const Bint &b);
bool operator > (const int64_t a, const Bint &b);
//*/

} // namespace

#endif
