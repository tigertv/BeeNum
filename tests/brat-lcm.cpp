#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <BeeNum/Brat.h>
#include <BeeNum/Math.h>

using namespace BeeNum;


int main() {
	Brat a;
	Brat b;
	Brat c;

	std::vector<std::vector<std::string>> data = {
		{"4/5", "8/15", "8/5"},
		{"4434/2345", "3422448/14345345", "2529189072/35"},
		{"44123456789034/23123456789045", "34123456789022448/141234567890345345", "250940811853816811901637705872/5"},
		{"441234567890341234567/231234567890451234567", "341234567890224481234567/1412345678903453451234567", "150564487112290508962653036830640507095677489/3"},
		{"4412345678903412345672/2312345678904512345672", "3412345678902244812345672/14123456789034534512345672", "78419003704317973418084047912047984406339227/1"},
		{"4412345678903412345672345/2312345678904512345672", "3412345678902244812345672345/14123456789034534512345672", "1003763247415270059751554398708779566810310006519935/8"},
	};

	///////////////////////////////////////////////////////////

	std::cout << "Least Common Multiple:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		c = Math::lcm(a, b);
		std::cout << "c = " << c << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(c.toString() == s[2]);
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		a = -a;
		std::cout << "a = " << a << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		c = Math::lcm(a, b);
		std::cout << "c = " << c << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(c.toString()==s[2]);
		std::cout << std::endl;
	}


}
