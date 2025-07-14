#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
	this->type = "WrongCat";
    std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "WrongCat copied" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assigned" << std::endl;
    if (this != &other) {
		this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructed" << std::endl;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "Wrong Meow!" << std::endl;
}

std::string	WrongCat::getType( void ) const
{
	return (this->type);
}
