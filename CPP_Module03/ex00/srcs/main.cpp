#include "ClapTrap.hpp"
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
	std::cout << BOLDWHITE << "🤖 ClapTrap Arena 🤖" << RESET << std::endl;
	printDivider();

	ClapTrap bob("🧔 Bob");
	ClapTrap alice("👩 Alice");

	bob.setAttackDamage(3);
	alice.setAttackDamage(4);

	bob.printInfo();
	alice.printInfo();

	printDivider();

	std::cout << CYAN << "Round 1: Bob attacks Alice!" << RESET << std::endl;
	bob.attack(alice.getName());
	alice.takeDamage(bob.getAttackDamage());

	printDivider();
	sleep(1);

	std::cout << YELLOW << "Round 2: Alice repairs herself 🔧" << RESET << std::endl;
	//alice.setEnergyPoints(0);
	alice.beRepaired(2);

	printDivider();
	sleep(1);

	std::cout << RED << "Round 3: Alice retaliates!" << RESET << std::endl;
	alice.attack(bob.getName());
	bob.takeDamage(alice.getAttackDamage());

	printDivider();
	sleep(1);

	std::cout << GREEN << "Status after the battle:" << RESET << std::endl;
	bob.printInfo();
	alice.printInfo();

	printDivider();
	std::cout << BOLDWHITE << "🏁 End of Simulation 🏁" << RESET << std::endl;
}

