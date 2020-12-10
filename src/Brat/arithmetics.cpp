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

#include <Bint/Brat.h>


namespace TigerTV {

Brat Brat::operator + (const Brat& a) const {
	Brat b = *this;
	b += a;
	return b;
}

Brat& Brat::operator += (const Brat& a) {
	numerator *= a.denominator;
	numerator += denominator * a.numerator;
	denominator *= a.denominator;
	simplify();
	return *this;
}

/*
Bint Bint::operator + (const int64_t a) const {
	Bint b = *this;
	b += a;
	return b;
}

Bint& Bint::operator += (const int64_t a) {

}
//*/

Brat Brat::operator - (const Brat& a) const {
	Brat b(*this);
	b -= a;
	return b;
}

Brat& Brat::operator -= (const Brat& a) {
	Brat b(a);
	b.numerator = - b.numerator;
	(*this) += b;
	return *this;
}

Brat Brat::operator * (const Brat& a) const {
	Brat b(*this);
	b *= a;
	return b;
}

Brat& Brat::operator *= (const Brat& a) {
	numerator *= a.numerator;
	denominator *= a.denominator;
	simplify();
	return *this;
}

Brat Brat::operator / (const Brat& a) const {
	Brat b(*this);
	b /= a;
	return b;
}

Brat& Brat::operator /= (const Brat& a) {
	numerator *= a.denominator;
	denominator *= a.numerator;
	simplify();
	return *this;
}

Brat& Brat::operator ++ () { // prefix
	numerator += denominator;
	return *this;
}

Brat Brat::operator ++ (int) { // postfix
	Brat b = (*this); 
	++(*this);
	return b;
}


Brat& Brat::operator -- () { // prefix
	numerator -= denominator;
	return *this;
}

Brat Brat::operator -- (int) { // postfix
	Brat b(*this); 
	--(*this);
	return b;
}

Brat Brat::operator - () const { // prefix
	Brat a(*this);
	a.numerator = -a.numerator;
	return a;
}

/*
Bint Bint::operator - (const int64_t a) const {
	Bint b(*this);
	b -= a;
	return b;
}

Bint& Bint::operator -= (const int64_t a) {
	*this += -a;
	return *this;
}

Bint Bint::operator * (const int64_t a) const {
	Bint b = *this;
	b *= a;
	return b;
}

Bint& Bint::operator *= (const int64_t a) {

}

Bint Bint::operator / (const int64_t a) const {
	Bint b(*this);
	b /= a;
	return b;
}

Bint& Bint::operator /= (const int64_t a) {
	Bint c(*this);
	Bint res;

	div(c, res, a);

	this->number = res.number;
	return (*this);
}

////////////////////////////////////////////////////////////////////////

//*/
///////////////////////////////////////////////////////////////
// Left side operators for int 
///////////////////////////////////////////////////////////////

Brat operator + (const int64_t a, const Brat& b) { 
	Brat c(a, 1); 
	c += b;
	return c;
}

Brat operator - (const int64_t a, const Brat& b) { 
	Brat d(a, 1);
	d -= b;
	return d;
}

Brat operator * (const int64_t a, const Brat& b) { 
	Brat c(a, 1); 
	c *= b;
	return c;
}

Brat operator / (const int64_t a, const Brat& b) { 
	Brat c(a, 1);
	c /= b;
	return c;
}

} // namespace
