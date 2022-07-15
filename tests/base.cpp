#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <BeeNum/Bint.h>

using namespace BeeNum;


int main() {
	Bint a;
	Bint c;

	std::vector<std::vector<std::string>> data = {
		{"453453a::32", "4466021482", "21uyc8a::36"},
		{"-453453a::32", "-4466021482", "-21uyc8a::36"},
		{"cc453453a::32", "13610922415210", "4torrs60a::36"},
		{"cc45A3453a::50", "23909464394262660", "6jf74b49m6c::36"},
		{"0::150", "0", "0::36"},
		{"1::150", "1", "1::36"},
		{"1:12::150", "162", "4i::36"},
		{"1:12:20::150", "24320", "irk::36"},
		{"1:12:20:111::150", "3648111", "266wf::36"},
		{"1:1::150", "151", "47::36"},
		{"1:1:1::150", "22651", "hh7::36"},
	};
	
	///////////////////////////////////////////////////////////

	std::cout << "Different Bases:" << std::endl;
	std::cout << "From base to decimal:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << "s = " << s[1] << std::endl;
		assert(a.toString()==s[1]);
		std::cout << std::endl;
	}

	std::cout << "From decimal to base62:" << std::endl;
	int base = 36;
	for (auto& s : data) {
		a = s[1];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.base(base) << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(a.base(base)==s[2]);
		std::cout << std::endl;
	}



}
