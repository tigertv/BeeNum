#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <string>
#include <vector>

class BigInteger {
private:
	std::vector<uint32_t> number;
	void addBinary(const std::vector<uint32_t>&bin); 
	void shiftLeftBinary(std::vector<uint32_t>&bin, int places);
	void mult10();
	void addDigit(char c);

public:
	BigInteger();
	void setDecimal(std::string& s);
	std::string toString();
	BigInteger& addition(BigInteger& a);
};

#endif
