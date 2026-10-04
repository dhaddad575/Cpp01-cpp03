#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << "a raw value: " << a.getRawBits() << std::endl;
    std::cout << "b raw value: " << b.getRawBits() << std::endl;
    std::cout << "c raw value: " << c.getRawBits() << std::endl;

    return 0;
}