#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <algorithm>

class ClapTrap {
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);


	int	getHitPoints( void ) const;
	int	getEnergyPoints( void ) const;
	int	getAttackDamage( void ) const;
	std::string	getName( void ) const;
	
	void	setHitPoints(int amount);
	void	setEnergyPoints(int amount);
	void	setAttackDamage(int amount);
	void	setName(std::string name);

	void	printInfo( void );
protected:
	std::string _name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;

	int	checkStats( void );
};

#endif
