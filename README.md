# Bint

An implementation of BigInteger library in C++

```cpp
Bint a = "-10934534535345288343";
std::cout << "a = " << a << std::endl;
std::cout << "a bin = " << a.bin() << std::endl;
std::cout << "a hex = " << a.hex() << std::endl;
std::cout << "a oct = " << a.oct() << std::endl;
std::cout << "a b12 = " << a.base(12) << std::endl;
std::cout << "a b16 = " << a.base(16) << std::endl;
std::cout << "a b62 = " << a.base(62) << std::endl;
std::cout << "-a hex= " << (-a).hex() << std::endl;
```

Output:
```
a = -10934534535345288343
a bin = 0b11111111111111111111111111111111111111111111111111111111111111110110100001000000101110101100011000010100100000001100101101101001
a hex = 0xffffffffffffffff6840bac61480cb69
a oct = 03777777777777777777776641005654302440145551
a b12 = -4b1864994618b07247_b12
a b16 = -97bf4539eb7f3497_b16
a b62 = -d1KhCnN5DsH_b62
-a hex= 0x000000000000000097bf4539eb7f3497
```
