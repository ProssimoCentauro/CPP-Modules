#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
	std::cout << BOLDWHITE << "🤖 Robot Battle Arena 🤖" << RESET << std::endl;
	printDivider();

	ClapTrap clap("🧢 Clap");
	ScavTrap scav("🛡️ Scav");
	FragTrap frag("🎉 Frag");

	clap.setAttackDamage(2);
	scav.setAttackDamage(5);
	frag.setAttackDamage(7);

	clap.printInfo();
	scav.printInfo();
	frag.printInfo();

	printDivider();
	sleep(1);

	std::cout << CYAN << "Round 1: Scav attacks Clap!" << RESET << std::endl;
	scav.attack(clap.getName());
	clap.takeDamage(scav.getAttackDamage());

	printDivider();
	sleep(1);

	std::cout << YELLOW << "Round 2: Frag attacks Scav!" << RESET << std::endl;
	frag.attack(scav.getName());
	scav.takeDamage(frag.getAttackDamage());

	printDivider();
	sleep(1);

	std::cout << GREEN << "Round 3: Clap repairs himself 🔧" << RESET << std::endl;
	clap.beRepaired(3);

	printDivider();
	sleep(1);

	std::cout << MAGENTA << "🛡️ Scav activates Gatekeeper mode!" << RESET << std::endl;
	scav.guardGate();

	printDivider();
	sleep(1);

	std::cout << CYAN << "🎉 Frag calls for high fives!" << RESET << std::endl;
	frag.highFivesGuys();

	printDivider();
	sleep(1);

	std::cout << GREEN << "📊 Final status:" << RESET << std::endl;
	clap.printInfo();
	scav.printInfo();
	frag.printInfo();

	printDivider();
	std::cout << BOLDWHITE << "🏁 End of Simulation 🏁" << RESET << std::endl;
}
