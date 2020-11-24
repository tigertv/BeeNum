#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include "../Bint.h"
#include <chrono>

using namespace TigerTV;


int main() {
	Bint a;
	Bint b;
	Bint c;

	std::vector<std::vector<std::string>> data = {
		{"563456345634562456245643563456345634563657456745676345634563456345661", "245635675674678567856785678545674567", "2293870155818927461038824163537040", "194671830340138360905494231965883981"},
		{"83453834556575478678469789567895678546534563455634563456345624562456345634563456345661", "2305843009213693952", "36192331491393999030911367620299278682605219448051027508900256529311", "361706202184918589"},
		{"345345997282345246457356724523465356745677423452345245656736562452452346456245", "4611686018427387904", "74884976102538365282049165625998607397784258852309259060588","1168204170632128693"}, 
		{"9223372036854775810", "9223372036854775808", "1", "2"},
		{"64435345345345223423", "18446744073709551616", "3", "9095113124216568575"}, 
		{"653453453453453453443333333333333333333333333333333333333333333333333", "36893488147419103232", "17711891346309742104832430041142880365138504809389", "18880027887859488085"},
		{"64435345345", "18446744073709551616", "0", "64435345345"}, 
	};

	///////////////////////////////////////////////////////////

	std::cout << "division:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = a / b;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(c.toString()==s[2]);
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-"+s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = a / b;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		if (s[2] == "0") {
			std::cout << "s = " << (s[2]) << std::endl;
			assert(c.toString()==s[2]);
		} else {
			std::cout << "s = " << ("-"+s[2]) << std::endl;
			assert(c.toString()=="-"+s[2]);
		}
		std::cout << std::endl;
	}

	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = "-"+s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = a / b;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		if (s[2] == "0") {
			std::cout << "s = " << (s[2]) << std::endl;
			assert(c.toString()==s[2]);
		} else {
			std::cout << "s = " << ("-"+s[2]) << std::endl;
			assert(c.toString()=="-"+s[2]);
		}
		std::cout << std::endl;
	}

	///////////////////////////////////////////////////////////
	std::cout << "reminder:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = a % b;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		std::cout << "s = " << s[3] << std::endl;
		assert(c.toString()==s[3]);
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = "-"+s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = a % b;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		if (s[3] == "0") {
			std::cout << "s = " << s[3] << std::endl;
			assert(c.toString()==s[3]);
		} else {
			std::cout << "s = " << ("-"+s[3]) << std::endl;
			assert(c.toString()=="-"+s[3]);
		}
		std::cout << std::endl;
	}

	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = "-"+s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = a % b;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		if (s[3] == "0") {
			std::cout << "s = " << s[3] << std::endl;
			assert(c.toString()==s[3]);
		} else {
			std::cout << "s = " << ("-"+s[3]) << std::endl;
			assert(c.toString()=="-"+s[3]);
		}
		std::cout << std::endl;
	}

}
