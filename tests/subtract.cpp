#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include "Bint/Bint.h"
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

	std::cout << "subtraction:" << std::endl;
	std::string s = "5000000000000000000";

	a = "-" + s;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;

	b = s;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;

	c = a - b;
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.bin() << std::endl;
	assert(c.toString()=="-10000000000000000000");
	std::cout << std::endl;

	///////////////////////////////////////////////////////////

	s = "50000000000000000000";

	b = s;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;

	a = "-" + s;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;

	c = b - a;
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.bin() << std::endl;
	assert(c.toString()=="100000000000000000000");
	std::cout << std::endl;

	///////////////////////////////////////////////////////////


}
