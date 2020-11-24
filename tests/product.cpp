#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include "../Bint.h"
#include <chrono>

using namespace TigerTV;


int main() {
	Bint a;
	Bint b;
	Bint c;

	std::vector<std::vector<std::string>> data = {
		{"2305843009213693952", "5316911983139663491615228241121378304"}, 
		{"4611686018427387904", "21267647932558653966460912964485513216"}, 
		{"9223372036854775808", "85070591730234615865843651857942052864"},
		{"18446744073709551616", "340282366920938463463374607431768211456"},
		{"36893488147419103232", "1361129467683753853853498429727072845824"}
	};

	///////////////////////////////////////////////////////////

	a = "-500000000000000000000000000000000000000000000000";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;

	b = "-500000000000000000000000000000000000000000";
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;

	c = a * b;
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.bin() << std::endl;
	assert(c.toString()=="250000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	std::cout << std::endl;

	///////////////////////////////////////////////////////////

	std::cout << "square:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		a *= a;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		assert(a.toString()==s[1]);
		std::cout << std::endl;
	}
	
	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-" + s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		a *= a;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		assert(a.toString()==s[1]);
		std::cout << std::endl;
	}

	///////////////////////////////////////////////////////////

	std::cout << "product:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[1];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		int i = -10;
		std::cout << "i = " << i << std::endl;
		a *= i;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		assert(a.toString()==("-" + s[1]+ "0"));
		std::cout << std::endl;
	}
	
	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-" + s[1];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		std::string t = "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		std::cout << "t = " << t << std::endl;
		a *= t;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		assert(a.toString()==("-" + s[1] + "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
		std::cout << std::endl;
	}

}
