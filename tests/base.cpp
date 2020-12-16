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
		{"453453a_b32", "4466021482", "21uyc8a_b36"},
		{"-453453a_b32", "-4466021482", "-21uyc8a_b36"},
		{"cc453453a_b32", "13610922415210", "4torrs60a_b36"},
		{"cc45A3453a_b50", "23909464394262660", "6jf74b49m6c_b36"},
		{"0_b150", "0", "0_b36"},
		{"1_b150", "1", "1_b36"},
		{"1:12_b150", "162", "4i_b36"},
		{"1:12:20_b150", "24320", "irk_b36"},
		{"1:12:20:111_b150", "3648111", "266wf_b36"},
		{"1:1_b150", "151", "47_b36"},
		{"1:1:1_b150", "22651", "hh7_b36"},
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
