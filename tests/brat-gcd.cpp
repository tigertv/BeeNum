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
		{"4/5", "8/15", "4/15"},
		{"4434/2345", "3422448/14345345", "6/961138115"},
		{"44123456789034/23123456789045", "34123456789022448/141234567890345345", "6/653166285546368606189972549105"},
		{"441234567890341234567/231234567890451234567", "341234567890224481234567/1412345678903453451234567", "1/108861047591062015671942869376375371818559163"},
		{"4412345678903412345672/2312345678904512345672", "3412345678902244812345672/14123456789034534512345672", "3/510286160583103198462673630487219350369017681"},
		{"4412345678903412345672345/2312345678904512345672", "3412345678902244812345672345/14123456789034534512345672", "15/4082289284664825587701389043897754802952141448"},
	};

	///////////////////////////////////////////////////////////

	std::cout << "Greatest Common Divisor:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		c = Math::gcd(a, b);
		std::cout << "c = " << c << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(c.toString()==s[2]);
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		a = -a;
		std::cout << "a = " << a << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		c = Math::gcd(a, b);
		std::cout << "c = " << c << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(c.toString()==s[2]);
		std::cout << std::endl;
	}


}
