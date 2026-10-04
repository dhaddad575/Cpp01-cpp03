#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed           a;
    Fixed const     b(Fixed(5.05f) * Fixed(2));

    std::cout << "Subject tests:" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "\nComparison tests:" << std::endl;

    Fixed first(10);
    Fixed second(5);

    std::cout << "10 > 5:  " << (first > second) << std::endl;
    std::cout << "10 < 5:  " << (first < second) << std::endl;
    std::cout << "10 >= 5: " << (first >= second) << std::endl;
    std::cout << "10 <= 5: " << (first <= second) << std::endl;
    std::cout << "10 == 5: " << (first == second) << std::endl;
    std::cout << "10 != 5: " << (first != second) << std::endl;

    std::cout << "\nArithmetic tests:" << std::endl;
    std::cout << "10 + 5 = " << first + second << std::endl;
    std::cout << "10 - 5 = " << first - second << std::endl;
    std::cout << "10 * 5 = " << first * second << std::endl;
    std::cout << "10 / 5 = " << first / second << std::endl;

    std::cout << "\nIncrement/decrement tests:" << std::endl;

    Fixed number(1);

    std::cout << "Initial: " << number << std::endl;
    std::cout << "Prefix ++: " << ++number << std::endl;
    std::cout << "After prefix: " << number << std::endl;
    std::cout << "Postfix ++: " << number++ << std::endl;
    std::cout << "After postfix: " << number << std::endl;
    std::cout << "Prefix --: " << --number << std::endl;
    std::cout << "After prefix: " << number << std::endl;
    std::cout << "Postfix --: " << number-- << std::endl;
    std::cout << "After postfix: " << number << std::endl;

    std::cout << "\nMin/max tests:" << std::endl;
    std::cout << "Min: " << Fixed::min(first, second) << std::endl;
    std::cout << "Max: " << Fixed::max(first, second) << std::endl;

    Fixed const constFirst(20);
    Fixed const constSecond(30);

    std::cout << "Const min: " << Fixed::min(constFirst, constSecond) << std::endl;
    std::cout << "Const max: " << Fixed::max(constFirst, constSecond) << std::endl;

    return (0);
}