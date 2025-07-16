#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

	void	setType(std::string type);
	virtual std::string	getType( void ) const;
	virtual void	makeSound( void ) const  = 0;

protected:
	std::string	type;
};

#endif
