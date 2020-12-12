#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <Bint/Brat.h>
#include <chrono>

using namespace TigerTV;


int main() {
	Brat a;
	Brat b;
	Brat c;

	std::vector<std::vector<std::string>> data = {
		{"-500000000000000000000/200000000000000000000000000", "-50000000004000000000000/400000000000000000000", "250/12500000001"},
		{"543563/24994884934885", "-537483929/484588458292993", "-263404356155114154059/13434348959704898963165"},
	};

	///////////////////////////////////////////////////////////
	std::cout << "product:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;

		Brat t = s[2];
		std::cout << "t = " << t << std::endl;
		c = a / b;
		std::cout << "c = " << c << std::endl;
		assert(t.toString() == c.toString());
		std::cout << std::endl;
	}
	
	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		b = s[1];
		b = -b;
		std::cout << "b = " << b << std::endl;

		Brat t = s[2];
		t = -t;
		std::cout << "t = " << t << std::endl;
		c = a / b;
		std::cout << "c = " << c << std::endl;
		assert(t.toString() == c.toString());
		std::cout << std::endl;
	}

}
