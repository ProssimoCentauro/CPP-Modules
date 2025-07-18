#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure constructed" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "Cure copied" << std::endl;
    *this = other;
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "Cure assigned" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destructed" << std::endl;
}

AMateria* cure::clone() const
{
	Cure *newCure = new Cure();
	return (newCure);
}

void cure::use(ICharacter& target)
{
	std::cout << "Cure: \"* heals " << target << "’s wounds *\"" << std::endl;
}
