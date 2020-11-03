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

	s = "200000000000000000000000000000000000000000000000000000000000000000000000000";
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

	BigInteger big3 = bigI2 + bigI2;
	std::cout << big3.toString() << std::endl;
	std::cout << std::endl;

	BigInteger big4;
	s = "51"; 
	big4.setDecimal(s);
	std::cout << big4.toBinString() << std::endl;

	BigInteger big5;
	s = "57"; 
	big5.setDecimal(s);
	std::cout << big5.toBinString() << std::endl;

	BigInteger big6 = big4 & big5;
	std::cout << big6.toBinString() << std::endl;
	std::cout << big6.toString() << std::endl;
	std::cout << std::endl;

}
