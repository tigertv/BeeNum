#include <iostream>
#include <string>
#include "BigInteger.h"

int main() {
	std::string s = "2218";
	BigInteger bigI;

	bigI.setDecimal(s);
	std::cout << s << std::endl;
	std::cout << bigI.toString() << std::endl;
	std::cout << std::endl;

	s = "9999999999";
	bigI.setDecimal(s);
	std::cout << s << std::endl;
	std::cout << bigI.toString() << std::endl;
	std::cout << std::endl;

	BigInteger bigI2;
	s = "2";
	bigI2.setDecimal(s);
	std::cout << s << std::endl;
	std::cout << bigI2.toString() << std::endl;
	std::cout << std::endl;

	bigI2 += bigI;
	std::cout << s << std::endl;
	std::cout << (std::string)bigI2 << std::endl;
	std::cout << std::endl;

	//bigI2 += bigI;
	//bigI2.addition(bigI);
	//std::cout << s << std::endl;
	//std::cout << bigI2.toString() << std::endl;
	//std::cout << std::endl;
}
