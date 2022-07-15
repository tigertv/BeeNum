#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <chrono>
#include <BeeNum/Brat.h>

using namespace BeeNum;


int main() {
	Brat a(1, "34534534");
	Brat b("-SomeNumbersAreHere::62", "-SomeNumbersAreHere::62");	// base 62
	Brat c = "-9:10:79:100:16:3:35:72:76:15:11::101 / 2";			// base 101

	a += b;
	a *= c;

	std::cout << "a = " << a << std::endl;
	std::cout << "a b62 = " << a.base(62) << std::endl;
	std::cout << "a point = " << a.point(50) << std::endl;
	std::cout << "a point b62 = " << a.point(50, 62) << std::endl;
}
