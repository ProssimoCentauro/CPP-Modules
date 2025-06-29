#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <unistd.h> // per sleep

// ANSI escape codes for colors
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define CYAN        "\033[36m"
#define MAGENTA     "\033[35m"
#define BOLDWHITE   "\033[1m\033[37m"

void printDivider() {
	std::cout << MAGENTA << "==============================" << RESET << std::endl;
}

int main() {
	std::cout << BOLDWHITE << "⚔️  ClapTrap vs ScavTrap Arena ⚔️" << RESET << std::endl;
	printDivider();

	ClapTrap bob("🧔 Bob");
	ScavTrap kevin("🛡️ Kevin");

	bob.setAttackDamage(5);
	// kevin usa già attackDamage 20 di default

	bob.printInfo();
	kevin.printInfo();

	printDivider();
	sleep(1);

	std::cout << CYAN << "Round 1: Bob provokes the mighty Kevin!" << RESET << std::endl;
	bob.attack(kevin.getName());
	kevin.takeDamage(bob.getAttackDamage());

	printDivider();
	sleep(1);

	std::cout << YELLOW << "Round 2: Kevin retaliates with fury! 🔥" << RESET << std::endl;
	kevin.attack(bob.getName());
	bob.takeDamage(kevin.getAttackDamage());

	printDivider();
	sleep(1);

	std::cout << GREEN << "Round 3: Kevin enters Gate Keeper Mode 🚪" << RESET << std::endl;
	kevin.guardGate();

	printDivider();
	sleep(1);

	std::cout << RED << "Round 4: Bob tries a desperate repair attempt!" << RESET << std::endl;
	bob.beRepaired(3);

	printDivider();
	sleep(1);

	std::cout << GREEN << "📊 Final Status:" << RESET << std::endl;
	bob.printInfo();
	kevin.printInfo();

	printDivider();
	std::cout << BOLDWHITE << "🏁 Simulation Complete. Exiting... 🏁" << RESET << std::endl;
}

