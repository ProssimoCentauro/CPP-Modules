#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
    std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal copied" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assigned" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructed" << std::endl;
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}
