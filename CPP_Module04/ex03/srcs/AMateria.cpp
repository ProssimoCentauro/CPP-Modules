#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria constructor called" << std::endl;    
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
        std::cout << "AMateria copy constructor called" << std::endl;

}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria assignment operator called" << std::endl;
    (void)other;
    return *this;
}

AMateria::~AMateria() {
        std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}

