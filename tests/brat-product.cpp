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
		{"-500000000000000000000/200000000000000000000000000", "-50000000004000000000000/400000000000000000000" , "12500000001/40000000000000", "1/160000000000"},
		{"543563/24994884934885", "-537483929/484588458292993" , "-292156376899027/12112232755806678879056760805", "295460734969/624744272908141130689963225"},
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
		c = a * b;
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
		c = a * b;
		std::cout << "c = " << c << std::endl;
		assert(t.toString() == c.toString());
		std::cout << std::endl;
	}

	///////////////////////////////////////////////////////////
	std::cout << "square:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;

		Brat t = s[3];
		std::cout << "t = " << t << std::endl;
		c = a * a;
		std::cout << "c = " << c << std::endl;
		assert(t.toString() == c.toString());
		std::cout << std::endl;
	}
	
	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		a = -a;
		std::cout << "a = " << a << std::endl;

		Brat t = s[3];
		std::cout << "t = " << t << std::endl;
		c = a * a;
		std::cout << "c = " << c << std::endl;
		assert(t.toString() == c.toString());
		std::cout << std::endl;
	}
}
