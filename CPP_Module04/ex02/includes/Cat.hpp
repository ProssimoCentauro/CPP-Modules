#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

	void makeSound( void ) const;
	std::string	getType( void ) const;
	Brain*	getBrain( void );
	void	setBrain(Brain *brain);
private:
	Brain *brain;
};

#endif
