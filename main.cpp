#include <iostream>
#include <string>
#include "Bint.h"

using namespace TigerTV;


int main() {
	Bint a = "1345908937";
	Bint b("1753435836");
	Bint c = a&b;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.toBinString() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.toBinString() << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.toBinString() << std::endl;
}
