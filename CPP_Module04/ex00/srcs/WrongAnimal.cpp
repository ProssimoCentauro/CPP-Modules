#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
    std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "WrongAnimal copied" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assigned" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructed" << std::endl;
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "*General WrongAnimal Sound*" << std::endl;
}
