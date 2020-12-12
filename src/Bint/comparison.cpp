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

#include <BeeNum/Bint.h>

namespace TigerTV {

bool Bint::operator == (const int64_t a) const {
	if (number.size() != 1) return false;
	return (number[0] == (uint64_t)a); 
}

bool Bint::operator == (const Bint &b) const {
	const std::vector<uint64_t>& n = b.number;
	if (number.size() < n.size()) return false;
	if (number.size() > n.size()) return false;

	for(int i = (int)n.size() - 1; i >= 0; i--) {
		if(number[i] != n[i]) {
			return false;
		}
	}

	return true;
}

bool Bint::operator != (const int64_t a) const {
	if (number.size() != 1) return true;
	return (number[0] != (uint64_t)a); 
}

bool Bint::operator != (const Bint &b) const {
	const std::vector<uint64_t>& n = b.number;
	if (number.size() < n.size()) return true;
	if (number.size() > n.size()) return true;

	for(int i = (int)n.size() - 1; i >= 0; i--) {
		if(number[i] != n[i]) {
			return true;
		}
	}

	return false;
}

bool Bint::operator > (const Bint& b) const {
	bool neg = isNegative();
	bool negB = b.isNegative();
	if (neg != negB) return negB;

	const std::vector<uint64_t>& n = b.number;
	if (number.size() < n.size()) return neg;
	if (number.size() > n.size()) return !neg;

	for(int i = (int)n.size() - 1; i >= 0; i--) {
		if(number[i] > n[i]) {
			return true;
		}
		if(number[i] != n[i]) return false;
	}

	return false;
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

bool Bint::operator < (const Bint &b) const {
	bool neg = isNegative();
	bool negB = b.isNegative();
	if (neg != negB) return neg;

	const std::vector<uint64_t>& n = b.number;
	if (number.size() < n.size()) return !neg;
	if (number.size() > n.size()) return neg;

	for(int i = (int)n.size() - 1; i >= 0; i--) {
		if(number[i] < n[i]) {
			return true;
		}
		if(number[i] != n[i]) return false;
	}

	return false;
}

bool Bint::operator <= (const Bint &b) const {
	return !(*this > b);
}

bool Bint::operator >= (const Bint &b) const {
	return !(*this < b);
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

} // namespace
