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
//*
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
	a = s;
	std::cout << "s = " << s << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	a *= -10;
	//a =	"36893488147419103232";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	
//*/
/*
	b = 10;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;

	c = a * b;

	//assert(a.toString()==s.second);
	std::cout << "c = " << c << std::endl;
	std::cout << "c = " << c.bin() << std::endl;
	std::cout << std::endl;
	//*/
}
