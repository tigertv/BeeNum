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
#include <Bint/Math.h>


namespace TigerTV {

Brat::Brat() {
	//numerator = 0;
	denominator = 1;
}

Brat::Brat(const Bint& numerator, const Bint& denominator) : numerator(numerator), denominator(denominator) {
	simplify();
}

Brat::Brat(const int64_t num) {
	numerator = num;
	denominator = 1;
}

Brat::Brat(const std::string& s) {
	auto end = s.find('/');	
	numerator = s.substr(0, end);
	if (end != std::string::npos) {
		denominator = s.substr(end + 1);
	} else {
		denominator = 1;
	}
}

Brat::Brat(const char* s) : Brat((std::string)s) {

}

void Brat::simplify() {
	if (denominator < 0) {
		denominator = -denominator;
		numerator = -numerator;
	}

	Bint c = Math::gcd(numerator, denominator);
	if (c != 1) {
		numerator /= c;
		denominator /= c;
	}
}


} // namespace
