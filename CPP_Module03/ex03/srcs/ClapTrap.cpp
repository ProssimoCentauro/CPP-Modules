#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	_name("claptrap"),
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0),
	_type("ClapTrap"),
	_maxHitPoints(10)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name),	
	_hitPoints(10), 
	_energyPoints(10), 
	_attackDamage(0),
	_type("ClapTrap"),
	_maxHitPoints(10)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Calling copy assignment operator..." << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
		this->_type = other.getType();
		this->_maxHitPoints = other.getMaxHitPoints();
    }
	std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}


int	ClapTrap::getHitPoints( void ) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints( void ) const
{
	return (this->_energyPoints);
}
int	ClapTrap::getAttackDamage( void ) const
{
	return (this->_attackDamage);
}
std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

void	ClapTrap::setHitPoints(int amount)
{
	this->_hitPoints = amount;
}
void	ClapTrap::setEnergyPoints(int amount)
{
	this->_energyPoints = amount;
}
void	ClapTrap::setAttackDamage(int amount)
{
	this->_attackDamage = amount;
}
void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setType(std::string type)
{
	this->_type = type;
}
std::string	ClapTrap::getType( void ) const
{
	return (this->_type);
}

void	ClapTrap::setMaxHitPoints(unsigned int amount)
{
	this->_maxHitPoints = amount;
}
unsigned int	ClapTrap::getMaxHitPoints( void ) const
{
	return (this->_maxHitPoints);
}


int	ClapTrap::checkStats( void )
{
	if (!this->_hitPoints && !this->_energyPoints)
	{
		std::cout
			<< _type << " "
		   	<< this->_name
			<< " can't act because he's dead and has no energy points"
			<< std::endl;
		return (1);
	}
	if (!this->_hitPoints)
	{
		std::cout
			<< _type << " "
		   	<< this->_name
			<< " can't act because he's dead"
			<< std::endl;
		return (2);
	}
	if (!this->_energyPoints)
	{
		std::cout
			<< _type << " "
		   	<< this->_name
			<< " can't act because he has no energy points"
			<< std::endl;
		return (3);
	}
	return (0);
}

void ClapTrap::attack(const std::string& target)
{
	if (checkStats())
		return ;
	std::cout
		<< _type << " "
		<< this->_name
		<< " attacks "
	   	<< target
		<< ", causing "
		<< this->_attackDamage
		<< " points of damage!"
		<< std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (checkStats())
		return ;
	this->_hitPoints = std::max(0u, this->_hitPoints - amount);
	std::cout
		<< _type << " "
	    << this->_name
		<< " takes "
	   	<< amount
		<< " points of damage. His health is now "
		<< _hitPoints
		<< std::endl;
	this->_energyPoints--;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (checkStats())
		return ;
	this->_hitPoints = std::min(_maxHitPoints, this->_hitPoints + amount);
	std::cout
		<< _type << " "
	    << this->_name
		<< " get repaired by "
	   	<< amount
		<< " points. His health is now "
		<< _hitPoints
		<< std::endl;
	this->_energyPoints--;
}

void	ClapTrap::printInfo( void )
{
	std::cout
		<< _type << " "
		<< this->_name
		<< " info: "
		<< std::endl;
	std::cout << this->_hitPoints << " Health" << std::endl;
	std::cout << this->_energyPoints << " Energy Points" << std::endl;
	std::cout << this->_attackDamage << " Attack Damage" << std::endl;
}



