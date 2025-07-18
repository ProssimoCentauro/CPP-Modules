#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter {
public:
    Character();
    Character(std::string name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();
	
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMaterial	_invetory[4];
};

#endif
