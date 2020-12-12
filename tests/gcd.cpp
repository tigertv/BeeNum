#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <BeeNum/Bint.h>
#include <BeeNum/Math.h>

using namespace TigerTV;


int main() {
	Bint a;
	Bint b;
	Bint c;

	std::vector<std::vector<std::string>> data = {
		{"54", "24", "6"},
		{"54", "1", "1"},
		{"54", "0", "54"},
		{"0", "0", "0"},
		{"5634563456345624562456435634563456345636574567456763434536745247235423452345234523451234355634563456345664", "245635675674678567856785678545674568", "8"},
		{"8345383455657547867846978956789567854653456345563456345634562456245634563456345634566163675675674674567456", "245345345345345345345345674678678567856785678567856730584300921369395234456456456454456", "8"},
		{"6443534534546425624523462453567245728436724562456234563567456746734563456", "34245698729348249569258298624572785723745823845728452457824356", "4"}, 
		{"4213518165211821182155201879854514971797088", "9307999046194775203602390818721305202949035", "123"},
		{"54", "-3", "3"},
		{"-54", "3", "3"},
		{"-44", "99", "11"},
	};

	///////////////////////////////////////////////////////////

	std::cout << "Greatest Common Divisor:" << std::endl;

	std::cout << "positives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = Math::gcd(a, b);
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(c.toString()==s[2]);
		std::cout << std::endl;
	}

	std::cout << "negatives:" << std::endl;
	for (auto& s : data) {
		a = s[0];
		a = -a;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = s[1];
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = Math::gcd(a, b);
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(c.toString()==s[2]);
		std::cout << std::endl;
	}

	for (auto& s : data) {
		a = s[0];
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a.bin() << std::endl;
		b = s[1];
		b = -b;
		std::cout << "b = " << b << std::endl;
		std::cout << "b = " << b.bin() << std::endl;
		c = Math::gcd(a, b);
		std::cout << "c = " << c << std::endl;
		std::cout << "c = " << c.bin() << std::endl;
		std::cout << "s = " << s[2] << std::endl;
		assert(c.toString()==s[2]);
		std::cout << std::endl;
	}

}
