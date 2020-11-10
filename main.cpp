#include <iostream>
#include <string>
#include "Bint.h"

using namespace TigerTV;


int main() {
	/*
	std::string s = "2218";
	Bint bigI;

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

	Bint bigI2;
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

	Bint big3 = bigI2 + bigI2;
	std::cout << big3 << std::endl;
	std::cout << big3.toHexString() << std::endl;
	std::cout << std::endl;

	Bint big4;
	s = "5112345"; 
	big4.setDecimal(s);
	std::cout << big4 << std::endl;
	std::cout << big4.toBinString() << std::endl;

	Bint big5;
	s = "5712345"; 
	big5.setDecimal(s);
	std::cout << big5 << std::endl;
	std::cout << big5.toBinString() << std::endl;

	Bint big6 = big4 & big5;
	std::cout << big6.toBinString() << std::endl;
	std::cout << big6 << std::endl;
	std::cout << std::endl;

	std::cout << big4 << std::endl;
	std::cout << big5 << std::endl;
	Bint big7 = big4 * big5;
	std::cout << "BIG7 = " << big7.toBinString() << std::endl;
	std::cout << "BIG7 = " << big7 << std::endl;
	std::cout << std::endl;

	Bint big8 = big7++;
	std::cout << "BIG7 = " << big7 << std::endl;
	std::cout << "BIG8 = " << big8 << std::endl;
	std::cout << std::endl;

	big7 -= big8;
	std::cout << "BIG7 = " << big7 << std::endl;
	std::cout << "BIG8 = " << big8 << std::endl;
	std::cout << std::endl;

	--big8;
	std::cout << "BIG8 = " << big8 << std::endl;
	std::cout << "BIG8 = " << big8.toHexString() << std::endl;
	std::cout << std::endl;
	//*/

	/*
	std::cin >> big8;
	std::cout << "BIG8 = " << big8 << std::endl;
	//*/

	/*
	Bint big9;
	big9.setDecimal("34534535646786745963567567");
	std::cout << "BIG9 = " << big9 << std::endl;
	big9 >>= 1;
	std::cout << "BIG9 = " << big9 << std::endl;
	big9 >>= 4;
	std::cout << "BIG9 = " << big9 << std::endl;
	//big9 >>= 68;
	//std::cout << "BIG9 = " << big9 << std::endl;
	std::cout << std::endl;

	Bint big0;
	big0.setDecimal("64534000000000000000000000000");
	std::cout << "BIG0 = " << big0 << std::endl;

	if (big0 > big9) {
		std::cout << "BIG0 is bigger than BIG9" << std::endl;
	} else {
		std::cout << "BIG0 isn't bigger than BIG9" << std::endl;
	} 
	
	if (big0 < big9) {
		std::cout << "BIG0 is lesser than BIG9" << std::endl;
	} else {
		std::cout << "BIG0 isn't lesser than BIG9" << std::endl;
	}

	Bint big10 = big0;
	big10 *= big9;
	big10 *= big9;

	std::cout << "BIG10 = " << big10 << std::endl;
	if (big9 == big10) {
		std::cout << "BIG9 is equal to BIG10" << std::endl;
	} else {
		std::cout << "BIG9 isn't equal to BIG10" << std::endl;
	}

	if (big9 != big10) {
		std::cout << "BIG9 isn't equal to BIG10" << std::endl;
	} else {
		std::cout << "BIG9 is equal to BIG10" << std::endl;
	}
	std::cout << std::endl;

	
	//*/
	Bint big11("44");
	Bint big14 = big11;
	Bint big12 = "2000000000000000000000000000000000000000000";

	/*
	std::cout << "BIG11 = " << big11 << std::endl;
	std::cout << "BIG11 = " << big11.toBinString() << std::endl;
	std::cout << "BIG12 = " << big12 << std::endl;
	std::cout << "BIG12 = " << big12.toBinString() << std::endl;
	big11 /= big12;
	std::cout << "BIG11 = " << big11 << std::endl;
	std::cout << "BIG11 = " << big11.toBinString() << std::endl;
	std::cout << std::endl;
	big14 %= big12;
	std::cout << "BIG14 = " << big14 << std::endl;
	std::cout << "BIG14 = " << big14.toBinString() << std::endl;
	std::cout << std::endl;
	//*/

	Bint big13 = big11;
	std::cout << "BIG13 = " << big13 << std::endl;
	std::cout << "BIG13 = " << big13.toBinString() << std::endl;
	std::cout << std::endl;
	//big13 = Math::pow(big13, 1000);
	std::cout << "BIG13 = " << big13 << std::endl;
	//std::cout << "BIG13 = " << big13.toBinString() << std::endl;
	std::cout << std::endl;
	//big13 = 2;
	big13 = "330546345634563456345634586304576937456729462638456284294858734563456345623452435234523452345";
	std::cout << "BIG13 = " << big13 << std::endl;
	//std::cout << "BIG13 = " << big13.toBinString() << std::endl;
	std::cout << std::endl;

	//*
	Bint exp = 2000;
	//Bint mod = "1243457934567934569399458639983009987";

	//Bint mod = "123456789012345678902223217";
	Bint mod = "123456789012345678901234567890";
	std::cout << "MOD = " << mod.toString() << std::endl;
	//big13 = Math::modPow(big13, exp, mod);
	std::cout << "BIG13 = " << big13 << std::endl;
	//std::cout << "BIG13 = " << big13.toBinString() << std::endl;
	std::cout << std::endl;
	//*/
	Bint d = "29508186119999999999999999993452345234987984576934597639456739458674053333333333333";
	std::cout << "d = " << d << std::endl;
	std::cout << "mod = " << mod << std::endl;
	d %= mod;
	std::cout << "d = " << d << std::endl;

}
