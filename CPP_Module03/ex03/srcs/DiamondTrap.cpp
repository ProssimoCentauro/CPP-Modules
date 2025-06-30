#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	this->_name = "Unnamed_Diamond";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	setType("DiamondTrap");
	setMaxHitPoints(100);
	std::cout << "🔧 DiamondTrap default constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) :
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	setType("DiamondTrap");
	setMaxHitPoints(100);
	std::cout << "🔧 DiamondTrap constructor called for " << _name << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	setType(other._type);
	setMaxHitPoints(other._hitPoints);
	std::cout << "📋 DiamondTrap copy constructor called for " << other._name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		setType("DiamondTrap");
		this->_maxHitPoints = other._hitPoints;
    }
	std::cout << "📄 DiamondTrap assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "💥 DiamondTrap destructor called for " << this->_name << std::endl;
}

void DiamondTrap::whoAmI( void )
{
    std::cout
		<< "I am " << this->_name
		<< " and my ClapTrap name is "
		<< ClapTrap::_name << std::endl;
}
