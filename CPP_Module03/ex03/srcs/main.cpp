#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <unistd.h> // sleep

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
	std::cout << BOLDWHITE << "💎 Diamond Arena 💎" << RESET << std::endl;
	printDivider();

	ClapTrap clap("🧢 Clap");
	ScavTrap scav("🛡️ Scav");
	FragTrap frag("🎉 Frag");
	DiamondTrap diamond("💎 Diamond");

	clap.printInfo();
	scav.printInfo();
	frag.printInfo();
	diamond.printInfo();

	printDivider();
	sleep(1);

	std::cout << CYAN << "💥 Diamond attacks Frag!" << RESET << std::endl;
	diamond.attack(frag.getName());
	frag.takeDamage(diamond.getAttackDamage());

	printDivider();
	sleep(1);

	std::cout << YELLOW << "🤔 Diamond wonders... who is he?" << RESET << std::endl;
	diamond.whoAmI();

	printDivider();
	sleep(1);

	std::cout << GREEN << "🔧 Diamond repairs himself!" << RESET << std::endl;
	diamond.beRepaired(15);

	printDivider();
	sleep(1);

	std::cout << MAGENTA << "📊 Final status:" << RESET << std::endl;
	clap.printInfo();
	scav.printInfo();
	frag.printInfo();
	diamond.printInfo();

	printDivider();
	std::cout << BOLDWHITE << "🏁 End of Simulation 🏁" << RESET << std::endl;
}
