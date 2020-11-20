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

Bint Math::fact(const uint64_t a) {
	Bint ret(1);
	if (a <= 1) return ret;
	if (a == 2) return a;

	uint64_t c(a);
	uint64_t sum = 0;
	std::vector<uint64_t> bitc;

	while (c != 1) {
		bitc.push_back((c-1)|1);
		c >>= 1;
		sum += c;
	}

	uint64_t prev = 1;
	Bint result(1);

	for(int i = bitc.size() - 1; i >= 0; --i) {
		result *= oddFact(bitc[i], prev + 2);
		ret *= result;
		prev = bitc[i];
	}

	ret <<= sum;
	return ret;
}

Bint Math::oddFact(const uint64_t a, const uint64_t begin) {
	Bint ret(1);
	if (a < 3) {
		return ret;
	}
	if (a == 3) {
		return a;
	}

	uint64_t n = (a - 1) | 1;
	if (((n - begin) % 4) == 0) {
		ret = n;
		n -= 2;
	}

	Bint last(n+2);
	last *= (begin - 2);
	
	for (uint64_t m = n - begin + 2; m >= 2; m -= 4) {
		last += m << 1;
		ret *= last;
	}

	return ret;
}

} // namespace
