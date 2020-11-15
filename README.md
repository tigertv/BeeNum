# Bint

An implementation of BigInteger library in C++

```cpp
Bint a = "2000000045634563456345634563456345238888456884858566665544334";
Bint b = "8000000000000000040000000000000000000004444400000000000000000";
Bint c = a * b;
std::cout << "c= " << c << std::endl;
std::cout << "c= " << c.bin() << std::endl;
std::cout << "c= " << c.hex() << std::endl;
std::cout << "c= " << c.oct() << std::endl;
std::cout << "c= " << c.base(12) << std::endl;
```

