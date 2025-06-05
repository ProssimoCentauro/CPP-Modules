#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)// : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int number)
{	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = number << _fractionalBits; 
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(number * (1 << _fractionalBits)); 
}

float Fixed::toFloat(void) const
{
    return ((float)_rawBits / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (_rawBits >> _fractionalBits);
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits method called" << std::endl;
    return (this->_rawBits);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits method called" << std::endl;
    this->_rawBits = raw;
}


std::ostream	&operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->toFloat() > other.toFloat());
}
bool	Fixed::operator<(const Fixed& other) const
{
	return (this->toFloat() < other.toFloat());
}
bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->toFloat() >= other.toFloat());
}
bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->toFloat() <= other.toFloat());
}
bool	Fixed::operator==(const Fixed& other) const
{
	return (this->toFloat() == other.toFloat());
}
bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->_rawBits + other.getRawBits()));
}
Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->_rawBits - other.getRawBits()));
}
Fixed	Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->_rawBits * other.getRawBits()));
}
Fixed	Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->_rawBits / other.getRawBits()));
}

Fixed&	Fixed::operator++( void )
{
	++this->_rawBits;
	return (*this);
}
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++this->_rawBits;
    return (temp);
}
Fixed&	Fixed::operator--( void )
{
	++this->_rawBits;
	return (*this);
}
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --this->_rawBits;
    return (temp);
}

Fixed&	Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}
const Fixed&	Fixed::min(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 < fixed2)
		return (fixed1);
	return (fixed2);
}
Fixed&	Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}
const Fixed&	Fixed::max(const Fixed& fixed1, const Fixed& fixed2)
{
	if (fixed1 > fixed2)
		return (fixed1);
	return (fixed2);
}
