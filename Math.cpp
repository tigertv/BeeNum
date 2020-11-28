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
	Bint temp(1);
	if (exp == 0) return temp;
	Bint b(a);
	while (exp > 1) {
        if (exp & 1) {
            temp *= b;
		}
        b *= b;
        exp >>= 1;
    }

	return b*temp;
}

Bint Math::modPow(const Bint& base, const uint64_t exp, const uint64_t mod) {
	Bint ret;
	if (mod == 1) return ret;
	ret = 1;
	Bint b(base);
	Bint x(exp);

	b %= mod;
	while(x > 0) {
		if ((x & 1) == 1) {
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

	for(int i = (int)bitc.size() - 1; i >= 0; --i) {
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

	Bint last(n + 2);
	last *= (begin - 2);
	
	for (uint64_t m = n - begin + 2; m >= 2; m -= 4) {
		last += m << 1;
		ret *= last;
	}

	return ret;
}

Bint Math::gcd(const Bint& a, const Bint& b) {
	Bint c;
	Bint aa(a);
	Bint bb(b);

	if (aa < 0) {
		aa = -aa;
	}
	if (bb < 0) {
		bb = -bb;
	}

	if (a == 0) return bb;
	if (b == 0) return aa;

	while(1) {
		if (aa > bb) {
			aa %= bb;
			if (aa == 0) {
				c = bb;
				break;
			}
		} else {
			bb %= aa;
			if (bb == 0) {
				c = aa;
				break;
			}
		}
	}

	return c;
}

Bint Math::lcm(const Bint& a, const Bint& b) {
	Bint c = a * b / gcd(a, b);
	if (c < 0) return -c;
	return c;
}

// Fibonnaci number
Bint Math::fib(const uint64_t a) {
	if (a < 2) return a;
	Bint f1;
	Bint f2(1);
	Bint f;

	for(uint64_t i = 2; i <= a; ++i) {
		f = f1 + f2;
		if (i & 1) {
			f2 = f;
		} else {
			f1 = f;
		}
	}
	return f;
}



} // namespace
