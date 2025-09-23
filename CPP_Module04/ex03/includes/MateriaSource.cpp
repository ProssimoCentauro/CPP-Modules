#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource constructed" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copied" << std::endl;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assigned" << std::endl;
    if (this != &other) {
        // copy fields here
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructed" << std::endl;
}
