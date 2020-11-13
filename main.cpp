#include <iostream>
#include <string>
#include "Bint.h"

using namespace TigerTV;


int main() {
	Bint a = "17";
	Bint b("5");
	Bint c = a&b;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.toBinString() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.toBinString() << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.toBinString() << std::endl;

}
