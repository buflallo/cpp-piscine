#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointValue (0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const raw)
{
    // std::cout << "Int constructor called" << std::endl;
    fixedPointValue = raw << fractionalBits;
}

Fixed::Fixed(float const raw)
{
    // std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(raw * (1 << fractionalBits)); // 1 << fractionalBits = 2^fractionalBits
}

Fixed::Fixed(Fixed const &src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    // std::cout << "Assignation operator called" << std::endl;
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

Fixed &Fixed::operator++(void)
{
    this->fixedPointValue++;
    return *this;
}

Fixed &Fixed::operator--(void)
{
    this->fixedPointValue--;
    return *this;
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->fixedPointValue == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->fixedPointValue != rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->fixedPointValue < rhs.getRawBits());
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->fixedPointValue > rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->fixedPointValue >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->fixedPointValue <= rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed sm;
    sm.setRawBits(this->fixedPointValue + rhs.getRawBits());
    return sm;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed sm;
    sm.setRawBits(this->fixedPointValue - rhs.getRawBits());
    return sm;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    Fixed sm((float)(this->toFloat() * rhs.toFloat()));
    return sm;
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    if (rhs.toInt())
    {
        Fixed sm((float)(this->toFloat() / rhs.toFloat()));
        return sm;
    }
    else
    {
        std::cout << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    else
        return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    else
        return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    else
        return b;
}