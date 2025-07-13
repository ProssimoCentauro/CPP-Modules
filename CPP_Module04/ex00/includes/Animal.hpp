#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    ~Animal();

	void	setType(std::string type);
	std::string	getType( void ) const;

	virtual void makeSound() const; 
protected:
	std::string _type;

};

#endif
