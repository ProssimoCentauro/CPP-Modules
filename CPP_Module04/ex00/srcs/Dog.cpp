#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	this->type = "Dog";
    std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog copied" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assigned" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "Woof!" << std::endl;
}

std::string	Dog::getType( void ) const
{
	return (this->type);
}
