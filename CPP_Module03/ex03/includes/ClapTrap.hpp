#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <algorithm>

class ClapTrap {
public:
    ClapTrap();
    ClapTrap(std::string name);
	ClapTrap(const std::string &name, unsigned int hp, unsigned int ep, unsigned int ad);
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
	std::string	getType( void ) const;
	unsigned int	getMaxHitPoints( void ) const;
	
	void	setHitPoints(int amount);
	void	setEnergyPoints(int amount);
	void	setAttackDamage(int amount);
	void	setName(std::string name);
	void	setType(std::string type);
	void	setMaxHitPoints(unsigned int amount);
	
	void	printInfo( void );
protected:
	std::string _name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;

	int	checkStats( void );
	
	std::string _type;
	unsigned int	_maxHitPoints;
};

#endif
