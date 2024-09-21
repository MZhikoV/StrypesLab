#include <iostream>

//  <unsigned> [char]  short  int  long  longlong
// float double long double
// bool (1bit/1byte) 0 - false everything else true
// + - * / %
// a = a + b; => a += b;
// a++ / a += 1;
// a-- / a -= 1;

// && || !
// true false
//  a      b       &&
// false false -> false
// false true -> false
// true false -> false
// true ture -> true
//                 ||
// false false -> false
// false true -> true
// true false -> true
// true ture -> true
//          !
// false -> true
// true -> false
//                 ^ XOR
// false false -> false
// false true -> true
// true false -> true
// true ture -> false
//                 NAND
// false false -> true
// false true -> true
// true false -> true
// true ture -> false
//                XNOR
// false false -> true
// false true -> false
// true false -> false
// true ture -> true

// & | ~ ^
// 0001b => 1d
// 0010b => 2
//  
// a = 3   (0011)
// b = 5   (0101)
// a & b = (0001) => 1d
// a | b = (0111) => 7d
// ~a = (1100) => 12d
// ~b = (1010) => 10d
// a ^ b = (0110) => 6d
// ~(a & b) = ~(0001) = (1110) => 14d
// ~(a ^ b) = ~(0110) = (1001) => 9d

// short
// 0000 0000 0000 0000 -> 0
// 0111 1111 1111 1111 -> 32_767 -> (2 ^ 15) - 1
// 1000 0000 0000 0000 -> -32_768 -> -(2 ^ 15) 
// 1000 0000 0000 0001 -> -32_767
// 1111 1111 1111 1111 -> -1 


// unisigne short
// 1000 0000 0000 0000 -> 32_768 
// 0000 0000 0000 0000
// 1111 1111 1111 1111
// 0000 0000 0000 0101 -> p (5)
// 0000 0000 0000 0011 -> q (3)
// 1111 1111 1111 1010 -> p (-6)
// p & q = 2
// 
// << >>
// 0000 0000 0000 0101 = a(5) 
// a << 1 = 0000 0000 0000 1010 = a(10)
// a << 1 = 0000 0000 0001 0100 = a(20) 
// a << 3 = 0000 0000 1010 0000 = a(160)
// 0000 0000 0000 0101 = a(5) \
// a >> 2 = 0000 0000 0000 0001 = a(1)
// a >> 1 = 0000 0000 0000 0010 = a(2)
// a >> 1 = 0000 0000 0000 0001 = a(1)

// 1111 1111 1111 1010 -> p (-6)
// p << 1 = 1111 1111 1111 0100
// p >> 1 = 1111 1111 1111 1110

// unsigned 
// 1111 1111 1111 1111
// p << 1 = 1111 1111 1111 1110
// p >> 1 = 0111 1111 1111 1111

int main() {
    // Arithmetic operations with integer types
    // int a = 10, b = 3;
    // long c = 1000000L, d = 500000L;
    // long long e = 10000000000LL, f = 3000000000LL;
    // SHRT_MAX;
    // SHRT_MIN;
    // UINT32_MAX;
    // std::cout << "Arithmetic with int: " << std::endl;
    // std::cout << "a + b = " << (a + b) << std::endl;
    // std::cout << "a - b = " << (a - b) << std::endl;
    // std::cout << "a * b = " << (a * b) << std::endl;
    // std::cout << "a / b = " << (a / b) << std::endl;
    // std::cout << "a % b = " << (a % b) << std::endl;

    // std::cout << "\nArithmetic with long: " << std::endl;
    // std::cout << "c + d = " << (c + d) << std::endl;
    // std::cout << "c - d = " << (c - d) << std::endl;
    // std::cout << "c * d = " << (c * d) << std::endl;
    // std::cout << "c / d = " << (c / d) << std::endl;
    // std::cout << "c % d = " << (c % d) << std::endl;


    // std::cout << "\nArithmetic with long long: " << std::endl;
    // std::cout << "e + f = " << (e + f) << std::endl;
    // std::cout << "e - f = " << (e - f) << std::endl;
    // std::cout << "e * f = " << (e * f) << std::endl;
    // std::cout << "e / f = " << (e / f) << std::endl;
    // std::cout << "e % f = " << (e % f) << std::endl;


    // std::cout << "\nAssignment with int: " << std::endl;
    // a += b; // a = 13
    // std::cout << "a += b -> a = " << a << std::endl;
    // a -= b; // a = 10
    // std::cout << "a -= b -> a = " << a << std::endl;
    // a *= b; // a = 30
    // std::cout << "a *= b -> a = " << a << std::endl;
    // a /= b; // a = 10
    // std::cout << "a /= b -> a = " << a << std::endl;
    // a %= b; // a = 1
    // std::cout << "a %= b -> a = " << a << std::endl;
 

    // std::cout << "\nIncrement and Decrement with int: " << std::endl;
    // a = 10;
    // std::cout << "a = " << a << std::endl;
    // std::cout << "a++ = " << a++ << std::endl; // Post-increment
    // std::cout << "Now, a = " << a << std::endl;
    // std::cout << "++a = " << ++a << std::endl; // Pre-increment
    // std::cout << "Now, a = " << a << std::endl;
    // std::cout << "a-- = " << a-- << std::endl; // Post-decrement
    // std::cout << "Now, a = " << a << std::endl;
    // std::cout << "--a = " << --a << std::endl; // Pre-decrement
    // std::cout << "Now, a = " << a << std::endl;

    // // Arithmetic operations with floating-point types
    // float g = 5.5f, h = 2.2f;
    // double i = 10.5, j = 3.2;
    // long double k = 100.55L, l = 50.25L;

    // std::cout << "\nArithmetic with float: " << std::endl;
    // std::cout << "g + h = " << (g + h) << std::endl;
    // std::cout << "g - h = " << (g - h) << std::endl;
    // std::cout << "g * h = " << (g * h) << std::endl;
    // std::cout << "g / h = " << (g / h) << std::endl;

    // std::cout << "\nArithmetic with double: " << std::endl;
    // std::cout << "i + j = " << (i + j) << std::endl;
    // std::cout << "i - j = " << (i - j) << std::endl;
    // std::cout << "i * j = " << (i * j) << std::endl;
    // std::cout << "i / j = " << (i / j) << std::endl;

    // std::cout << "\nArithmetic with long double: " << std::endl;
    // std::cout << "k + l = " << (k + l) << std::endl;
    // std::cout << "k - l = " << (k - l) << std::endl;
    // std::cout << "k * l = " << (k * l) << std::endl;
    // std::cout << "k / l = " << (k / l) << std::endl;


    // // Logical operators
    // bool m = true, n = false;
    // std::cout << "\nLogical operators: " << std::endl;
    // std::cout << "true && false = " << (m && n) << std::endl;
    // std::cout << "m || n = " << (m || n) << std::endl;
    // std::cout << "!m = " << (!m) << std::endl;

    // Bitwise operators
    int p = 6, q = 3; // 5 = 0101, 3 = 0011 in binary
    std::cout << "\nBitwise operators: " << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "p & q = " << (p & q) << std::endl;   // AND
    std::cout << "p | q = " << (p | q) << std::endl;   // OR
    std::cout << "p ^ q = " << (p ^ q) << std::endl;   // XOR
    std::cout << "~p = " << ~(~p) << std::endl;         // NOT
    std::cout << "p << 1 = " << (p << 1) << std::endl; // Left Shift
    std::cout << "p >> 1 = " << (p >> 1) << std::endl; // Right Shift

    std::cout << "\nAssignment with bitwise operators: " << std::endl;
    p &= q;
    std::cout << "p &= q -> p = " << p << std::endl;
    p = 6; p |= q;
    std::cout << "p |= q -> p = " << p << std::endl;
    p = 6; p ^= q;
    std::cout << "p ^= q -> p = " << p << std::endl;
    p = 6; p <<= 1;
    std::cout << "p <<= 1 -> p = " << p << std::endl;
    p = 6; p >>= 1;
    std::cout << "p >>= 1 -> p = " << p << std::endl;

    int z = (p << 6);
    std::cout << z << std::endl;
    //std::cout << (z << 1) << std::endl;

    system("pause");

    return 0;
}
