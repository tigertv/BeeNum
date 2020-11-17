#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include "Bint.h"
#include "Math.h"

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
		assert(a.toString()==("-" + s.second + "0"));
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-" + s.second;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;

		std::string t = "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		std::cout << "t = " << t << std::endl;
		a *= t;
		assert(a.toString()==("-" + s.second + "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		std::cout << std::endl;
	}
//*/
/*
	std::string s = "372542872459";
	a = s;
	b = "-29351077";
	a *= b;
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
	///////////////////////////////////////////////////////////
	//  COMPARISON
	///////////////////////////////////////////////////////////
/*
	std::cout << "comparison operators:" << std::endl;
	a = "-3235345345345";
	b = "-2935107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a > b) {
		std::cout << "a > b" << std::endl;
	} else {
		std::cout << "a !> b" << std::endl;
	}
	assert((a > b)==false);
	std::cout << std::endl;

	a = "-2135107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a > b) {
		std::cout << "a > b" << std::endl;
	} else {
		std::cout << "a !> b" << std::endl;
	}
	assert((a > b)==true);
	std::cout << std::endl;
	///
	a = "3235345345345";
	b = "2935107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a > b) {
		std::cout << "a > b" << std::endl;
	} else {
		std::cout << "a !> b" << std::endl;
	}
	assert((a > b)==true);
	std::cout << std::endl;

	a = "2135107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a > b) {
		std::cout << "a > b" << std::endl;
	} else {
		std::cout << "a !> b" << std::endl;
	}
	assert((a > b)==false);
	std::cout << std::endl;

	///////////////////////////////////////////////////////////

	a = "-3235345345345";
	b = "-2935107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a < b) {
		std::cout << "a < b" << std::endl;
	} else {
		std::cout << "a !< b" << std::endl;
	}
	assert((a < b)==true);
	std::cout << std::endl;

	a = "-2135107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a < b) {
		std::cout << "a < b" << std::endl;
	} else {
		std::cout << "a !< b" << std::endl;
	}
	assert((a < b)==false);
	std::cout << std::endl;
	///
	a = "3235345345345";
	b = "2935107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a < b) {
		std::cout << "a < b" << std::endl;
	} else {
		std::cout << "a !< b" << std::endl;
	}
	assert((a < b)==false);
	std::cout << std::endl;

	a = "2135107723423";
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a.bin() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b = " << b.bin() << std::endl;
	if (a < b) {
		std::cout << "a < b" << std::endl;
	} else {
		std::cout << "a !< b" << std::endl;
	}
	assert((a < b)==true);
	std::cout << std::endl;
//*/
	///////////////////////////////////////////////////////////
	//  COMPARISON END
	///////////////////////////////////////////////////////////

	a = "120";
	std::cout << "a = " << a << std::endl;
	a = Math::fact(a);
	assert(a.toString()=="6689502913449127057588118054090372586752746333138029810295671352301633557244962989366874165271984981308157637893214090552534408589408121859898481114389650005964960521256960000000000000000000000000000");
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
	//std::cout << "-a hex= " << (-a).hex() << std::endl;
	std::cout << std::endl;

}
