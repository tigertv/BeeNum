#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <Bint/Bint.h>
#include <chrono>

using namespace TigerTV;


int main() {
	Bint a;
	Bint b;
	Bint c;

	std::map<int, std::string> data;
	data = {
		{61, "2305843009213693952"}, {62, "4611686018427387904"}, {63, "9223372036854775808"},
		{64, "18446744073709551616"}, {65, "36893488147419103232"}
	};

	///////////////////////////////////////////////////////////

	std::cout << "shift left:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = "1";
		std::cout << "a = " << a << std::endl;
		std::cout << "a <<= " << s.first << std::endl;
		a <<= s.first;
		assert(a.toString()==s.second);
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-1";
		std::cout << "a = " << a << std::endl;
		std::cout << "a <<= " << s.first << std::endl;
		a <<= s.first;
		assert(a.toString()==("-"+s.second));
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}

	///////////////////////////////////////////////////////////

	std::cout << "shift right:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = "1";
		std::cout << "a = " << a << std::endl;
		std::cout << "a <<= " << (s.first + 1) << std::endl;
		a <<= s.first + 1;
		a >>= 1;
		std::cout << "a >>= 1" << std::endl;
		std::cout << "a = " << a << std::endl;
		assert(a.toString()==s.second);
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-1";
		std::cout << "a = " << a << std::endl;
		std::cout << "a <<= " << (s.first + 1) << std::endl;
		a <<= s.first + 1;
		a >>= 1;
		std::cout << "a >>= 1" << std::endl;
		std::cout << "a = " << a << std::endl;
		assert(a.toString()==("-"+s.second));
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}

	a = "5000000000000000000";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << std::endl;
	a <<= 2;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	assert(a.toString()=="20000000000000000000");
	std::cout << std::endl;

}
