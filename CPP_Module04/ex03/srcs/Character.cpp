#include "Character.hpp"

Character::Character(std::string const & name) : _name(name) {
        std::cout << "Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
}

Character::Character(const Character& other) : _name(other._name) {
        std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other) {
        std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character() {
        std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            std::cout << "Materia equipped" << std::endl;
            return;
        }
    }
    std::cout << "Inventory full, deleting materia" << std::endl;
    delete m;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
    {
        delete _inventory[idx];
        _inventory[idx] = 0;
    }

    std::cout << "Materia unequipped" << std::endl;

}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}

