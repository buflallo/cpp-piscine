#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointValue (0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const raw)
{
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = raw << fractionalBits;
}

Fixed::Fixed(float const raw)
{
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(raw * (1 << fractionalBits)); // 1 << fractionalBits = 2^fractionalBits
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    this->fixedPointValue = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

int Fixed::toInt(void) const
{
    return fixedPointValue >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
    out << c.toFloat();
    return out;
}

float Fixed::toFloat(void) const
{
    return (float)fixedPointValue / (float)(1 << fractionalBits);
}
