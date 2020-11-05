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

	s = "20103020999011";
	s = "555234000000000000000000000000000000000056789012345";
	bigI.setDecimal(s);
	std::cout << s << std::endl;
	std::cout << bigI.toBinString() << std::endl;
	std::cout << bigI << std::endl;
	std::cout << std::endl;

	BigInteger bigI2;
	s = "50000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"; 
	bigI2.setDecimal(s);
	std::cout << s << std::endl;
	std::cout << bigI2.toBinString() << std::endl;
	std::cout << bigI2 << std::endl;
	std::cout << std::endl;

	bigI2 += bigI;
	std::cout << (std::string)bigI2 << std::endl;
	std::cout << bigI2.toBinString() << std::endl;
	std::cout << bigI2 << std::endl;
	std::cout << std::endl;

	BigInteger big3 = bigI2 + bigI2;
	std::cout << big3 << std::endl;
	std::cout << std::endl;

	BigInteger big4;
	s = "5112345"; 
	big4.setDecimal(s);
	std::cout << big4 << std::endl;
	std::cout << big4.toBinString() << std::endl;

	BigInteger big5;
	s = "5712345"; 
	big5.setDecimal(s);
	std::cout << big5 << std::endl;
	std::cout << big5.toBinString() << std::endl;

	BigInteger big6 = big4 & big5;
	std::cout << big6.toBinString() << std::endl;
	std::cout << big6 << std::endl;
	std::cout << std::endl;

	std::cout << big4 << std::endl;
	std::cout << big5 << std::endl;
	BigInteger big7 = big4 * big5;
	std::cout << "BIG7 = " << big7.toBinString() << std::endl;
	std::cout << "BIG7 = " << big7 << std::endl;
	std::cout << std::endl;

	BigInteger big8 = big7++;
	std::cout << "BIG7 = " << big7 << std::endl;
	std::cout << "BIG8 = " << big8 << std::endl;
	std::cout << std::endl;

	big7 -= big8;
	std::cout << "BIG7 = " << big7 << std::endl;
	std::cout << "BIG8 = " << big8 << std::endl;
	std::cout << std::endl;

	std::cout << "BIG8 = " << big8 << std::endl;

}
