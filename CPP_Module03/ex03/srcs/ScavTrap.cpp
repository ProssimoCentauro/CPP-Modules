#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap("Unnamed_Scav")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	setType("ScavTrap");
	setMaxHitPoints(100);
	std::cout << "🔧 ScavTrap default constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	setType("ScavTrap");
	setMaxHitPoints(100);
	std::cout << "🔧 ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "📋 ScavTrap copy constructor called for " << other._name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "📄 ScavTrap assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "💥 ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "🛡️ ScavTrap " << _name << " brutally attacks " << target
		          << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "🛑 ScavTrap " << _name << " is too tired or dead to attack." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "🚪 ScavTrap " << _name << " has entered Gate keeper mode." << std::endl;
}

