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

	std::vector<std::vector<std::string>> data = {
		{"500000000000000000000/200000000000000000000000000", "50000000004000000000000/400000000000000000000", "0"},
		{"537483929/484588458292993", "543563/24994884934885", "1"},
		{"2/3", "6/11", "1"},
		{"2/3", "2/3", "0"},
		{"-2/3", "6/-11", "0"},
	};

	///////////////////////////////////////////////////////////
	std::cout << "comparison:" << std::endl;

	std::cout << "operator >:" << std::endl;
	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;

		bool t = (s[2] != "0");
		std::cout << "t = " << t << std::endl;
		bool c = a > b;
		std::cout << "c = a > b" << std::endl;
		std::cout << "c = " << c << std::endl;
		assert(t == c);
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		a = -a;
		std::cout << "a = " << a << std::endl;
		b = s[1];
		b = -b;
		std::cout << "b = " << b << std::endl;

		bool t = !(s[2] != "0");
		if (a == b) {
			t = !t;
		}
		std::cout << "t = " << t << std::endl;
		bool c = a > b;
		std::cout << "c = a > b" << std::endl;
		std::cout << "c = " << c << std::endl;
		assert(t == c);
		std::cout << std::endl;
	}

	///////////////////////////////////////////////////////////

	std::cout << "operator <=:" << std::endl;
	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;

		bool t = !(s[2] != "0");
		std::cout << "t = " << t << std::endl;
		bool c = (a <= b);
		std::cout << "c = a <= b" << std::endl;
		std::cout << "c = " << c << std::endl;
		assert(t == c);
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		a = -a;
		std::cout << "a = " << a << std::endl;
		b = s[1];
		b = -b;
		std::cout << "b = " << b << std::endl;

		bool t = (s[2] != "0");
		if (a == b) {
			t = !t;
		}
		std::cout << "t = " << t << std::endl;
		bool c = (a <= b);
		std::cout << "c = a <= b" << std::endl;
		std::cout << "c = " << c << std::endl;
		assert(t == c);
		std::cout << std::endl;
	}

	///////////////////////////////////////////////////////////

	std::cout << "operator <:" << std::endl;
	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;

		bool t = !(s[2] != "0");
		if (a == b) {
			t = false;
		}
		std::cout << "t = " << t << std::endl;
		bool c = (a < b);
		std::cout << "c = a < b" << std::endl;
		std::cout << "c = " << c << std::endl;
		assert(t == c);
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		a = -a;
		std::cout << "a = " << a << std::endl;
		b = s[1];
		b = -b;
		std::cout << "b = " << b << std::endl;

		bool t = (s[2] != "0");
		if (a == b) {
			t = false;
		}
		std::cout << "t = " << t << std::endl;
		bool c = (a < b);
		std::cout << "c = a < b" << std::endl;
		std::cout << "c = " << c << std::endl;
		assert(t == c);
		std::cout << std::endl;
	}

	///////////////////////////////////////////////////////////

	std::cout << "operator >=:" << std::endl;
	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;

		bool t = (s[2] != "0");
		if (a == b) {
			t = true;
		}
		std::cout << "t = " << t << std::endl;
		bool c = (a >= b);
		std::cout << "c = a >= b" << std::endl;
		std::cout << "c = " << c << std::endl;
		assert(t == c);
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		a = -a;
		std::cout << "a = " << a << std::endl;
		b = s[1];
		b = -b;
		std::cout << "b = " << b << std::endl;

		bool t = !(s[2] != "0");
		if (a == b) {
			t = true;
		}
		std::cout << "t = " << t << std::endl;
		bool c = (a >= b);
		std::cout << "c = a >= b" << std::endl;
		std::cout << "c = " << c << std::endl;
		assert(t == c);
		std::cout << std::endl;
	}
}
