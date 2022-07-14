#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <BeeNum/Bint.h>

using namespace BeeNum;


int main() {

	std::string data[][3] = {
		{"-500000000000000000000", "500000000000000000000", "-1000000000000000000000"},
		{"500000000000000000000", "-500000000000000000000", "1000000000000000000000"},
		{"18446744073709551616", "1", "18446744073709551615"}, // (1 << 64) - 1
		{"115792089237316195423570985008687907853269984665640564039457584007913129639936", "1", "115792089237316195423570985008687907853269984665640564039457584007913129639935"}, // (1 << 256) - 1
	};

	///////////////////////////////////////////////////////////

	Bint a;
	Bint b;
	Bint c;
	std::string s;

	for (auto& item: data) {
		a = item[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.hex() << std::endl;

		b = item[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.hex() << std::endl;

		s = item[2];
		std::cout << "s = " << s << std::endl;

		c = a - b;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.hex() << std::endl;
		std::cout << std::endl;

		assert(c.toString() == s);
	}

}
