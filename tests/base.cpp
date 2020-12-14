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
		{"453453a_b32", "4466021482"},
		{"-453453a_b32", "-4466021482"},
		{"cc453453a_b32", "13610922415210"},
		{"cc45A3453a_b50", "23909464394262660"},
		{"0_b150", "0"},
		{"1_b150", "1"},
		{"1:12_b150", "162"},
		{"1:12:20_b150", "24320"},
		{"1:12:20:111_b150", "3648111"},
		{"1:1_b150", "151"},
		{"1:1:1_b150", "22651"},
	};
	
	///////////////////////////////////////////////////////////

	std::cout << "Different Bases:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << "s = " << s[1] << std::endl;
		assert(a.toString()==s[1]);
		std::cout << std::endl;
	}


	Bint d;
	d = "333333";
	d = "acc45A3453a_b50";
	std::cout << "d = " << d << std::endl;
		//*/


}
