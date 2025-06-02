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
{
	std::cout << "Int constructor called" << std::endl;
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

