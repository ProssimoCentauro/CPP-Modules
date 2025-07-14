#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	this->type = "Cat";
    std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other) {
    std::cout << "Cat copied" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assigned" << std::endl;
    if (this != &other) {
		this->type = other.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "Meow!" << std::endl;
}

std::string	Cat::getType( void ) const
{
	return (this->type);
}
