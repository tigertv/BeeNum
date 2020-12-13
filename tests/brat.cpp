#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <chrono>
#include <BeeNum/Brat.h>
#include <BeeNum/Math.h>


using namespace BeeNum;


int main() {
	Brat a("15", "98724");
	Brat b("34", "33339");
	Brat c = a + b;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "a = " << a.point(10) << std::endl;
	std::cout << "b = " << b.point(10) << std::endl;
	std::cout << "c = " << c.point(50) << std::endl;
	std::cout << std::endl;

	Brat d("1", "3");
	std::cout << "d = " << d << std::endl;
	d = 7 / d;
	std::cout << "d = " << d << std::endl;
	//d = d / 5;
	//std::cout << "d = " << d << std::endl;
/*
	Bint a;
	Bint b;

	uint64_t d = 4000;
	std::cout << "a = " << d << std::endl;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	a = Math::fact(d);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	
	//assert(a.toString()=="6689502913449127057588118054090372586752746333138029810295671352301633557244962989366874165271984981308157637893214090552534408589408121859898481114389650005964960521256960000000000000000000000000000"); // 120!
	//assert(a.toString()==s);

	//std::cout << "a = " << a << std::endl;
	std::cout << "a b1000 = " << a.base(1000) << std::endl;
	//std::cout << "s = " << "6689502913449127057588118054090372586752746333138029810295671352301633557244962989366874165271984981308157637893214090552534408589408121859898481114389650005964960521256960000000000000000000000000000" << std::endl;
	/ *
	std::cout << "a bin = " << a.bin() << std::endl;
	std::cout << "a hex = " << a.hex() << std::endl;
	std::cout << "a oct = " << a.oct() << std::endl;
	std::cout << "a b12 = " << a.base(12) << std::endl;
	std::cout << "a b16 = " << a.base(16) << std::endl;
	std::cout << "a b62 = " << a.base(62) << std::endl;
	std::cout << "a b100 = " << a.base(100) << std::endl;
	std::cout << "a b101 = " << a.base(101) << std::endl;
	std::cout << "a b1001 = " << a.base(1001) << std::endl;
	
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
	std::cout << std::endl;

//*/



}
