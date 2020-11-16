#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include "Bint.h"

using namespace TigerTV;


int main() {
	Bint a;
	Bint b;
	Bint c;

	std::map<int, std::string> data;
	data = {
		{61, "2305843009213693952"}, {62, "4611686018427387904"}, {63, "9223372036854775808"},
		{64, "18446744073709551616"}, {65, "36893488147419103232"}
	};

	///////////////////////////////////////////////////////////
/*
	std::cout << "addition:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		c = a+a;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;

		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-" + s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		c = a+a;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;

		std::cout << std::endl;
	}
	//*/

	///////////////////////////////////////////////////////////
/*
	std::cout << "shift left:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		a = "1";
		a <<= s.first;
		assert(a.toString()==s.second);
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-" + s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		a = "-1";
		a <<= s.first;
		//assert(a.toString()==("-"+s.second));
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}
	//*/

	///////////////////////////////////////////////////////////
/*
	std::cout << "shift right:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		a = "1";
		a <<= s.first + 1;
		a >>= 1;
		assert(a.toString()==s.second);
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-" + s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		a = "-1";
		a <<= s.first + 1;
		a >>= 1;
		assert(a.toString()==("-"+s.second));
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}
	//*/

	///////////////////////////////////////////////////////////

/*
	std::cout << "subtruction:" << std::endl;
	std::string s = "5000000000000000000";

	a = "-" + s;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;

	b = "" + s;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;

	c = a - b;
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.bin() << std::endl;
	std::cout << std::endl;

	///////////////////////////////////////////////////////////

	s = "50000000000000000000";

	b = "" + s;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;

	a = "-" + s;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;

	c = b - a;
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.bin() << std::endl;
	std::cout << std::endl;
	//*/

	///////////////////////////////////////////////////////////

/*
	a = "5000000000000000000";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << std::endl;
	a <<= 2;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << std::endl;
	//*/

/*
	///////////////////////////////////////////////////////////

	a = "-500000000000000000000000000000000000000000000000";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;

	b = "-500000000000000000000000000000000000000000";
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;

	c = a * b;
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.bin() << std::endl;
	std::cout << std::endl;
//*/

	///////////////////////////////////////////////////////////
/*
	std::cout << "square:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		a *= a;
		//assert(a.toString()==s.second);
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-" + s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		a *= a;
		//assert(a.toString()==("-"+s.second));
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}
	//*/

	///////////////////////////////////////////////////////////
/*
	std::cout << "product:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		int i = -10;
		std::cout << "i = " << i << std::endl;
		a *= i;
		//assert(a.toString()==s.second);
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-" + s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		int i = 10;
		std::cout << "i = " << i << std::endl;
		a *= i;
		//assert(a.toString()==("-"+s.second));
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}
//*/
//*
	std::string s = "18446744073709551616";
	s = "1844674407370955160";
	//s = "10934534535345288343";
	s = "372542872459";
	a = s;
	b = "-29351077";
	a *= b;
	/*
	std::cout << "s = " << s << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a bin = " << a.bin() << std::endl;
	std::cout << "a hex = " << a.hex() << std::endl;
	std::cout << "a oct = " << a.oct() << std::endl;
	std::cout << "a b12 = " << a.base(12) << std::endl;
	std::cout << std::endl;
	//*/
	//a =	"36893488147419103232";
	std::cout << "a = " << a << std::endl;
	std::cout << "a bin = " << a.bin() << std::endl;
	std::cout << "a hex = " << a.hex() << std::endl;
	std::cout << "a oct = " << a.oct() << std::endl;
	std::cout << "a b12 = " << a.base(12) << std::endl;
	std::cout << "a b16 = " << a.base(16) << std::endl;
	std::cout << "a b62 = " << a.base(62) << std::endl;
	std::cout << "a b100 = " << a.base(100) << std::endl;
	std::cout << "a b101 = " << a.base(101) << std::endl;
	std::cout << "a b1000 = " << a.base(1000) << std::endl;
	std::cout << "a b1001 = " << a.base(1001) << std::endl;
	std::cout << "-a hex= " << (-a).hex() << std::endl;
	std::cout << std::endl;
	
//*/
/*
	int e = 9;
	std::cout << "e = " << e << std::endl;
	std::cout << "e = " << std::hex <<  e << std::endl;

	int f = -5;
	std::cout << "f = " << std::dec << f << std::endl;
	std::cout << "f = " << std::hex << f << std::endl;

	int h = e % f;

	std::cout << "h = " << std::dec << h << std::endl;
	std::cout << "h = " << std::hex << h << std::endl;
	std::cout << std::endl;
	//*/

}
