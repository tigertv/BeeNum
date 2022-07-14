#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <BeeNum/Bint.h>

using namespace BeeNum;


int main() {
	Bint a;
	Bint b;
	Bint c;

	std::vector<std::vector<std::string>> data = {
		{"54", "24", "16", "62", "46", "-55"},
		{"546345634563456346534563456345634554", "645634563967877275645748456834856475", "540488919652592388619687676516300314", "651491278878741233560624236664190715", "111002359226148844940936560147890401", "-546345634563456346534563456345634555"},
		{"543", "0", "0", "543", "543", "-544"},
		{"0", "34534534", "0", "34534534", "34534534", "-1"},
		{"0", "0", "0", "0", "0", "-1"},
		{"5634563456345624562456435634563456345636574567456763434536745247235423452345234523451234355634563456345664", "245635675674678567856785678545674568", "209274063275951493981402799900074048", "5634563456345624562456435634563456345636574567456763434536745247235423488706846922178308231017442101946184", "5634563456345624562456435634563456345636574567456763434536745247235423279432783646226814249614642201872136", "-5634563456345624562456435634563456345636574567456763434536745247235423452345234523451234355634563456345665"},
		{"8345383455657547867846978956789567854653456345563456345634562456245634563456345634566163675675674674567456", "245345345345345345345345674678678567856785678567856730584300921369395234456456456454456", "74326086151754002906920882714427839311485329518267565116821366681537180868657107173664", "8345383455657547868017998215983159197091881137527707074179862805295223728923825189254021729263474023848248", "8345383455657547867943672129831405194184960254813279234868377475776956163807003822572484548394816916674584", "-8345383455657547867846978956789567854653456345563456345634562456245634563456345634566163675675674674567457"},
	};

	///////////////////////////////////////////////////////////

	std::cout << "Bit operations:" << std::endl;

	std::cout << "Bit AND:" << std::endl;
	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = a & b;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(c.toString()==s[2]);
		std::cout << std::endl;
	}

	std::cout << "Bit OR:" << std::endl;
	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = a | b;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		std::cout << "s = " << s[3] << std::endl;
		assert(c.toString()==s[3]);
		std::cout << std::endl;
	}

	std::cout << "Bit XOR:" << std::endl;
	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = a ^ b;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		std::cout << "s = " << s[4] << std::endl;
		assert(c.toString()==s[4]);
		std::cout << std::endl;
	}

	std::cout << "Bit NOT(COMPLEMENT):" << std::endl;
	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		c = ~a;
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		std::cout << "s = " << s[5] << std::endl;
		assert(c.toString()==s[5]);
		std::cout << std::endl;
	}

}
