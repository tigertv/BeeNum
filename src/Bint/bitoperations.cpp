/*
 * MIT License
 *
 * This file is part of the BeeNum (https://github.com/tigertv/BeeNum).
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

#include <BeeNum/Bint.h>


namespace BeeNum {

Bint& Bint::bitOperation(const Bint& a, std::function<uint64_t(uint64_t&,const uint64_t&)>&& lambda) {
	Bint aa(a);
	extendNumberBySizeOf(*this, aa);
	extendNumberBySizeOf(aa, *this);

	const std::vector<uint64_t>& bin = aa.number;

	for(int j = 0; j < (int)bin.size(); j++) {
		number[j] = lambda(number[j], bin[j]);
	}

	return *this;
}

Bint& Bint::bitOperation(const int64_t a, std::function<uint64_t(uint64_t&,const uint64_t&)>&& lambda) {
	number[0] = lambda(number[0], a);
	uint64_t b;

	if (a < 0) {
		b = -1;
	} else {
		b = 0;
	}

	for(int j = 1; j < (int)number.size(); j++) {
		number[j] = lambda(number[j], b);
	}

	return *this;
}

Bint Bint::operator | (const Bint& a) const {
	Bint b(*this);
	b |= a;
	return b;
}

Bint Bint::operator | (const int64_t a) const {
	Bint b(*this);
	b |= a;
	return b;
}

Bint& Bint::operator |= (const Bint& a) {
	return bitOperation(a, [](auto a, auto b) { return a | b; });
}

Bint& Bint::operator |= (const int64_t a) {
	return bitOperation(a, [](auto a, auto b) { return a | b; });
}

Bint Bint::operator & (const Bint& a) const {
	Bint b(*this);
	b &= a;
	return b;
}

Bint Bint::operator & (const int64_t a) const {
	Bint b(*this);
	b &= a;
	return b;
}

Bint& Bint::operator &= (const Bint& a) {
	return bitOperation(a, [](auto a, auto b) { return a & b; });
}

Bint& Bint::operator &= (const int64_t a) {
	return bitOperation(a, [](auto a, auto b) { return a & b; });
}

Bint Bint::operator ^ (const Bint& a) const {
	Bint b(*this);
	b ^= a;
	return b;
}

Bint Bint::operator ^ (const int64_t a) const {
	Bint b(*this);
	b ^= a;
	return b;
}

Bint& Bint::operator ^= (const Bint& a) {
	return bitOperation(a, [](auto a, auto b) { return a ^ b; });
}

Bint& Bint::operator ^= (const int64_t a) {
	return bitOperation(a, [](auto a, auto b) { return a ^ b; });
}

Bint Bint::operator ~ () const {
	Bint a(*this);
	std::vector<uint64_t>& number = a.number;
	for(auto& item : number) {
		item = ~item;
	}
	return a;
}

///////////////////////////////////////////////////////////////
// Left side operators for int 
///////////////////////////////////////////////////////////////

Bint operator & (const int64_t a, const Bint& b) { 
	return b & a;
}

Bint operator | (const int64_t a, const Bint& b) { 
	return b | a;
}

Bint operator ^ (const int64_t a, const Bint& b) { 
	return b ^ a;
}
} // namespace
