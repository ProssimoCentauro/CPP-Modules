#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed_Frag")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "🔧 FragTrap default constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "🔧 FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "📋 FragTrap copy constructor called for " << other._name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "📄 FragTrap assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "💥 FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
		std::cout << "🙌 FragTrap " << _name << " says: High fives, guys!!" << std::endl;
}
