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

#include <BeeNum/Brat.h>


namespace TigerTV {

bool Brat::operator == (const Brat& b) const {
	return (numerator == b.numerator && denominator == b.denominator);
}

bool Brat::operator != (const Brat& b) const {
	return (numerator != b.numerator || denominator != b.denominator);
}

bool Brat::operator > (const Brat& b) const {
	Brat a(*this);
	Brat bb(b);

	a.numerator *= bb.denominator;
	bb.numerator *= a.denominator;
	a.denominator *= bb.denominator;
	bb.denominator = a.denominator;

	if (a.denominator > 0) {
		return (a.numerator > bb.numerator);
	}

	return (a.numerator < bb.numerator);
}

bool Brat::operator < (const Brat& b) const {
	Brat a(*this);
	Brat bb(b);

	a.numerator *= bb.denominator;
	bb.numerator *= a.denominator;
	a.denominator *= bb.denominator;
	bb.denominator = a.denominator;

	if (a.denominator > 0) {
		return (a.numerator < bb.numerator);
	}

	return (a.numerator > bb.numerator);
}

bool Brat::operator <= (const Brat& b) const {
	return !(*this > b);
}

bool Brat::operator >= (const Brat& b) const {
	return !(*this < b);
}

/*
bool Bint::operator == (const int64_t a) const {
	if (number.size() != 1) return false;
	return (number[0] == (uint64_t)a); 
}

bool Bint::operator != (const int64_t a) const {
	if (number.size() != 1) return true;
	return (number[0] != (uint64_t)a); 
}

bool Bint::operator > (const int64_t a) const {
	bool neg = isNegative();
	bool negA = (a < 0);
	if (neg != negA) return negA;
	if (number.size() > 1) return !neg;
	return (number[0] > (uint64_t)a);
}

bool Bint::operator < (const int64_t a) const {
	bool neg = isNegative();
	bool negA = (a < 0);
	if (neg != negA) return neg;
	if (number.size() > 1) return neg;
	return (number[0] < (uint64_t)a);
}


bool Bint::operator <= (const int64_t a) const {
	return !(*this > a);
}

bool Bint::operator >= (const int64_t a) const {
	return !(*this < a);
}

///////////////////////////////////////////////////////////////
// Left side operators for int 
///////////////////////////////////////////////////////////////

bool operator <= (const int64_t a, const Bint &b) {
	return b < a;
}

bool operator >= (const int64_t a, const Bint &b) {
	return b > a;
}

bool operator == (const int64_t a, const Bint &b) {
	return b == a;
}

bool operator != (const int64_t a, const Bint &b) {
	return b != a;
}

bool operator < (const int64_t a, const Bint &b) {
	return b > a;
}

bool operator > (const int64_t a, const Bint &b) {
	return b < a;
}
//*/

} // namespace
