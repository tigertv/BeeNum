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

	std::map<int, std::string> data;
	data = {
		{61, "2305843009213693952"}, {62, "4611686018427387904"}, {63, "9223372036854775808"},
		{64, "18446744073709551616"}, {65, "36893488147419103232"}
	};

	///////////////////////////////////////////////////////////

	std::cout << "comparison operators:" << std::endl;
	a = "-3235345345345";
	b = "-2935107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a > b) {
		std::cout << "a > b" << std::endl;
	} else {
		std::cout << "a !> b" << std::endl;
	}
	assert((a > b)==false);
	std::cout << std::endl;

	a = "-2135107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a > b) {
		std::cout << "a > b" << std::endl;
	} else {
		std::cout << "a !> b" << std::endl;
	}
	assert((a > b)==true);
	std::cout << std::endl;
	///
	a = "3235345345345";
	b = "2935107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a > b) {
		std::cout << "a > b" << std::endl;
	} else {
		std::cout << "a !> b" << std::endl;
	}
	assert((a > b)==true);
	std::cout << std::endl;

	a = "2135107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a > b) {
		std::cout << "a > b" << std::endl;
	} else {
		std::cout << "a !> b" << std::endl;
	}
	assert((a > b)==false);
	std::cout << std::endl;

	///////////////////////////////////////////////////////////

	a = "-3235345345345";
	b = "-2935107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a < b) {
		std::cout << "a < b" << std::endl;
	} else {
		std::cout << "a !< b" << std::endl;
	}
	assert((a < b)==true);
	std::cout << std::endl;

	a = "-2135107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a < b) {
		std::cout << "a < b" << std::endl;
	} else {
		std::cout << "a !< b" << std::endl;
	}
	assert((a < b)==false);
	std::cout << std::endl;
	///
	a = "3235345345345";
	b = "2935107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a < b) {
		std::cout << "a < b" << std::endl;
	} else {
		std::cout << "a !< b" << std::endl;
	}
	assert((a < b)==false);
	std::cout << std::endl;

	a = "2135107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a < b) {
		std::cout << "a < b" << std::endl;
	} else {
		std::cout << "a !< b" << std::endl;
	}
	assert((a < b)==true);
	std::cout << std::endl;
}
