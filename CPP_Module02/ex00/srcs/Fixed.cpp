#include "Fixed.hpp"

Fixed::Fixed() : value(0) bits(0)
{
	std::out << "Default constructor called" << std::endl;
}

Fixed::Fixed(consr Fixed& other) : valure(other.value) bits(other.bits)
{
	std::out << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::out << "Copy assignment operator called" << std::endl;
	if (this != other)
	{
		this.value = other.value;
		this.bits = other.bits;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::out << "Destructor called" << std::endl;
};
