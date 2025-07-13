#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Constructed!" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal Copied!" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

Animal::~Animal() 
{
	std::cout << "Animal Destructed!" << std::endl;
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

std::string Animal::getType( void ) const
{
	return (this->_type);
}

void Animal::makeSound( void ) const
{
	std::cout << "The base class animal doesn't make a sound!" << std::endl;
}
