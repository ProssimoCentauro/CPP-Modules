#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	_type = "Cat";
    std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other) {
    std::cout << "Cat copied" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assigned" << std::endl;
    if (this != &other) {
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructed" << std::endl;
}
