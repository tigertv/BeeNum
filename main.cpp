#include <iostream>
#include <string>
#include "BigInteger.h"

int main() {
	std::string s = "2218";
	BigInteger bigI;

	bigI.setDecimal(s);
	std::cout << s << std::endl;
	std::cout << bigI.toBinString() << std::endl;
	std::cout << std::endl;

	s = "2";
	bigI.setDecimal(s);
	std::cout << s << std::endl;
	std::cout << bigI.toBinString() << std::endl;
	std::cout << std::endl;

	BigInteger bigI2;
	s = "50000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"; 
	bigI2.setDecimal(s);
	std::cout << s << std::endl;
	std::cout << bigI2.toBinString() << std::endl;
	std::cout << bigI2.toString() << std::endl;
	std::cout << std::endl;

	bigI2 += bigI;
	std::cout << (std::string)bigI2 << std::endl;
	std::cout << bigI2.toBinString() << std::endl;
	std::cout << bigI2.toString() << std::endl;
	std::cout << std::endl;
}
