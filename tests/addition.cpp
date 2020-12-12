#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <BeeNum/Bint.h>
#include <chrono>

using namespace TigerTV;


int main() {
	Bint a;
	Bint c;

	std::map<std::string, std::string> data;
	data = {
		{"2305843009213693952", "4611686018427387904"}, {"4611686018427387904", "9223372036854775808"}, 
		{"9223372036854775808", "18446744073709551616"}, {"18446744073709551616", "36893488147419103232"},
		{"36893488147419103232", "73786976294838206464"}
	};

	///////////////////////////////////////////////////////////

	std::cout << "addition:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s.first;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		c = a+a;
		std::cout << "c = a + a" << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		assert(c.toString()==s.second);

		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-" + s.first;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		c = a+a;
		std::cout << "c = a + a" << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		assert(c.toString()=="-"+s.second);

		std::cout << std::endl;
	}

}
