#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
    std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->brain = new Brain(*other.brain);
    std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assigned" << std::endl;
    if (this != &other) {
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
	delete this->brain;
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

void	Cat::setBrain(Brain *brain)
{
	if (brain)
		delete this->brain;
	this->brain = brain;
}

Brain*	Cat::getBrain( void )
{
	return (this->brain);
}
