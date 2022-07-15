#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <BeeNum/Brat.h>

using namespace BeeNum;


int main() {
	Brat a;
	Brat c;

	std::vector<std::vector<std::string>> data = {
		{"453453a::32/43453b::32", "4466021482/137499755", "453453a::32/43453b::32"},
		{"-453453a::32/-45afA3a::62", "171770057/8920503206", "53q069::32/89r84t6::32"},
		{"1:12:20:111::150/1:12:20:112::150", "3648111/3648112", "3fajf::32/3fajg::32"},
	};
	
	///////////////////////////////////////////////////////////

	std::cout << "Different Bases:" << std::endl;
	std::cout << "Decimal:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "s = " << s[1] << std::endl;
		assert(a.toString() == s[1]);
		std::cout << std::endl;
	}

	std::cout << "Base32:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a.base(32) << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(a.base(32) == s[2]);
		std::cout << std::endl;
	}

}
