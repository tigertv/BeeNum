#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <BeeNum/Brat.h>
#include <chrono>

using namespace BeeNum;


int main() {

	std::vector<std::vector<std::string>> data = {
		{"1", "3", "1", "8", "11", "24"},  
		{"2", "3", "3", "8", "25", "24"},  
		{"2444234", "3434634563567456", "34563457727", "457536743223454565677473721", "559163491374441896220487035953613", "785735756188682526849306693345947725411888"},  
	};

	///////////////////////////////////////////////////////////

	std::cout << "addition:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		Brat a(s[0], s[1]);
		std::cout << "a = " << a << std::endl;
		Brat b(s[2], s[3]);
		std::cout << "b = " << b << std::endl;
		Brat t(s[4], s[5]);
		std::cout << "t = " << t << std::endl;

		Brat c = a + b;
		std::cout << "c = a + b" << std::endl;
		std::cout << "c = " << c << std::endl;
		assert(c.toString() == t.toString());

		std::cout << std::endl;
	}
	
	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		Brat a("-" + s[0], s[1]);
		std::cout << "a = " << a << std::endl;
		Brat b(s[2], "-" + s[3]);
		std::cout << "b = " << b << std::endl;
		Brat t("-" + s[4], s[5]);
		std::cout << "t = " << t << std::endl;

		Brat c = a + b;
		std::cout << "c = a + b" << std::endl;
		std::cout << "c = " << c << std::endl;
		assert(c.toString() == t.toString());

		std::cout << std::endl;
	}

}
