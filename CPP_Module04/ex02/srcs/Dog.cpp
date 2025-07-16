#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain();
    std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->brain = new Brain(*other.brain);
    std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assigned" << std::endl;
    if (this != &other) {
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
	delete this->brain;
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

void	Dog::setBrain(Brain *brain)
{
	if (brain)
		delete this->brain;
	this->brain = brain;
}

Brain*	Dog::getBrain( void )
{
	return (this->brain);
}
