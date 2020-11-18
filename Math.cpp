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

#include "Math.h"


namespace TigerTV {


Bint Math::pow(const Bint& a, uint64_t exp) {
	Bint b(a), temp(1);
	while (exp > 1) {
        if (exp & 1) {
            temp *= b;
		}
        b *= b;
        exp >>= 1;
    }

	return b*temp;
}

Bint Math::modPow(const Bint& base, const Bint& exp, const Bint& mod) {
	Bint ret;
	const Bint one(1);
	if (mod == one) return ret;
	ret = one;
	Bint b(base);
	Bint x(exp);
	const Bint zero;

	b %= mod;
	while(x > zero) {
		if (one == (x & one) ) {
			ret *= b;
			ret %= mod;
		}
		x >>= 1;
		b *= b;
		b %= mod;
	}

	return ret;
}

Bint Math::fact(const Bint& a) {
	Bint ret(1), mult(1), two(2), twos(a);
	if (a <= 1) return ret;
	if (a == 2) return a;

	twos >>= 1;

	while (mult <= a) {
		ret *= mult;
		mult += two;
	}
	ret <<= twos;

	ret *= fact(twos);
	return ret;
}


} // namespace
