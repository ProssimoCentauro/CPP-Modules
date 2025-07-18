#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "AMateria constructed" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria constructed with type: " << type << std::endl;
}

AMateria::AMateria(const AMateria& other) {
    std::cout << "AMateria copied" << std::endl;
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria assigned" << std::endl;
    (void)other;
	return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructed" << std::endl;
}


std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << this->_type << ": \"* Has been used to " << target << "\"" << std::endl;
}
