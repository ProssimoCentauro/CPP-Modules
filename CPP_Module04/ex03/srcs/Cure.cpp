#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "AMateria constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "AMateria copy constructor called" << std::endl;

}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "AMateria assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Cure::~Cure() {
    std::cout << "AMateria destructor called" << std::endl;

}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

