# Bint

An implementation of BigInteger library in C++

```cpp
Bint a = "372542872459";
Bint b = "-29351077";
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
a b100 = -10:93:45:34:53:53:45:28:83:43_b100
a b101 = -9:100:79:38:16:3:35:72:76:15_b101
-a hex= 0x000000000000000097bf4539eb7f3497
```

Factorial of 4000 takes `Time difference = 137191[µs]`
