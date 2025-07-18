#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice constructed" << std::endl;
}

Ice::Ice(const Ice& other) :AMateria(other) {
    std::cout << "Ice copied" << std::endl;
    *this = other;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "Ice assigned" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice destructed" << std::endl;
}

AMateria* Ice::clone() const
{
	Ice *newIce = new Ice();
	return (newIce);
}

void Ice::use(ICharacter& target)
{
	std::cout << "Ice: \"shoots an ice bolt at " << target << " *\"" << std::endl;
}
