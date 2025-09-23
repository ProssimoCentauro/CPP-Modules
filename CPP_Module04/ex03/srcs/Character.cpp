#include "Character.hpp"

Character::Character() {
    std::cout << "Character constructed" << std::endl;
}

Character::Character(std::string name) : _name(name) {
    std::cout << "Character constructed with name " << name << std::endl;
}

Character::Character(const Character& other) {
    std::cout << "Character copied" << std::endl;
    *this = other;
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assigned" << std::endl;
    if (this != &other) {
        // copy fields here
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructed" << std::endl;
}


std::string const & getName() const
{
	return (this->_name);
}

void equip(AMateria* m)
{
	int	i = 0;
	
	while (_inventory[i])
	{
		if (_invetory[i] == NULL)
		{
			_invetory[i] = m;
			return;
		}
	}
	std::cout << "NO MORE SPACE IN THE INVETORY!" << std::endl;
}

void unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "INVALID INDEX FOR UNEQUIP!" << std::endl;
		return;
	}
	if (_invetory[idx] == NULL)
	{
		std::cout << "THERE IS NO MATERIA IN THE INDEX " << idx << std:endl;
		return:
	}
	std::string	type = _invetory[idx]->getType();
	_invetory[idx] =  NULL;
	std::cout << "SUCCESSFULLY UNEQUIPPED " << type << " MATERIA AT INDEX " << idx << std::endl;
}

void use(int idx, ICharacter& target);
