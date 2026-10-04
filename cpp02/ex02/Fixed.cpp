#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawValue;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _rawValue = raw;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _rawValue = other.getRawBits();
    }
    return *this;
}

Fixed::Fixed(const Fixed &other) : _rawValue(0)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(int const value) : _rawValue(value * (1 << _fractionalBits))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _rawValue(static_cast<int>(roundf(value * (1 << _fractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_rawValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _rawValue / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &output, const Fixed &value)
{
    output << value.toFloat();
    return output;
}

bool Fixed::operator>(const Fixed &other) const
{
    return _rawValue > other._rawValue;
}

bool Fixed::operator<(const Fixed &other) const
{
    return _rawValue < other._rawValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return _rawValue >= other._rawValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return _rawValue <= other._rawValue;
}

bool Fixed::operator==(const Fixed &other) const
{
    return _rawValue == other._rawValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return _rawValue != other._rawValue;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    _rawValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _rawValue++;
    return temp;
}

Fixed& Fixed::operator--()
{
    _rawValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _rawValue--;
    return temp;
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
    if (first < second)
        return first;
    return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
    if (first < second)
        return first;
    return second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
    if (first > second)
        return first;
    return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
    if (first > second)
        return first;
    return second;
}