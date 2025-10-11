#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete _materias[i];
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (!_materias[i]) {
            _materias[i] = m->clone();
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return 0;
}

