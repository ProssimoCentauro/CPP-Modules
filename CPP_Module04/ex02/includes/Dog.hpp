#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

	void makeSound( void ) const;
	std::string	getType( void ) const;
	Brain*	getBrain( void );
	void	setBrain(Brain *brain);
private:
	Brain	*brain;
};

#endif
