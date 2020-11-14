#include <iostream>
#include <string>
#include "Bint.h"

using namespace TigerTV;


int main() {
	Bint a = "-5000000000000000000";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.toBinString() << std::endl;

	Bint b("5000000000000000000");
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.toBinString() << std::endl;

	Bint c = a-b;
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.toBinString() << std::endl;
	/*
	int i = 5;
	i = ~i + 1;
	std::cout << "i = " << i << std::endl;
	c = ~c;
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.toBinString() << std::endl;
	//*/
}
