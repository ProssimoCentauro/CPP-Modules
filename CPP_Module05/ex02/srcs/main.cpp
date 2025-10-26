#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <unistd.h> // sleep

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
    srand(time(NULL));

    std::cout << BOLDWHITE << "🏛️ Bureaucrat Arena: FORM EDITION 🏛️" << RESET << std::endl;
    printDivider();

    Bureaucrat alice("Alice", 50);
    Bureaucrat bob("Bob", 1);
    Bureaucrat charlie("Charlie", 150);

    std::cout << CYAN << "📜 Initial Bureaucrats:" << RESET << std::endl;
    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << charlie << std::endl;
    printDivider();
    sleep(1);

    try {
        std::cout << YELLOW << "🌿 Creating ShrubberyCreationForm (target: garden)" << RESET << std::endl;
        ShrubberyCreationForm shrub("garden");

        std::cout << shrub << std::endl;
        sleep(1);

        std::cout << RED << "❌ Charlie tries to sign (too low grade)" << RESET << std::endl;
        charlie.signAForm(shrub);

        std::cout << YELLOW << "✍️ Alice signs the form" << RESET << std::endl;
        alice.signAForm(shrub);

        std::cout << RED << "⚙️ Charlie tries to execute (too low grade)" << RESET << std::endl;
        charlie.executeAForm(shrub);

        std::cout << GREEN << "✅ Bob executes the Shrubbery form" << RESET << std::endl;
        bob.executeAForm(shrub);

    } catch (std::exception &e) {
        std::cout << RED << "⚠️ Exception: " << e.what() << RESET << std::endl;
    }

    printDivider();
    sleep(1);

    try {
        std::cout << YELLOW << "🤖 Creating RobotomyRequestForm (target: Marvin)" << RESET << std::endl;
        RobotomyRequestForm robo("Marvin");

        std::cout << robo << std::endl;
        sleep(1);

        std::cout << RED << "❌ Alice tries to execute unsigned form" << RESET << std::endl;
        alice.executeAForm(robo);

        std::cout << YELLOW << "✍️ Alice signs the form" << RESET << std::endl;
        alice.signAForm(robo);

        std::cout << GREEN << "⚙️ Bob executes the robotomy multiple times!" << RESET << std::endl;
        for (int i = 0; i < 4; i++) {
            bob.executeAForm(robo);
            sleep(1);
        }

    } catch (std::exception &e) {
        std::cout << RED << "⚠️ Exception: " << e.what() << RESET << std::endl;
    }

    printDivider();
    sleep(1);

    try {
        std::cout << YELLOW << "👑 Creating PresidentialPardonForm (target: Arthur Dent)" << RESET << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << pardon << std::endl;
        sleep(1);

        std::cout << RED << "❌ Alice tries to sign (too low grade)" << RESET << std::endl;
        alice.signAForm(pardon);

        std::cout << GREEN << "✍️ Bob signs and executes the form" << RESET << std::endl;
        bob.signAForm(pardon);
        bob.executeAForm(pardon);

    } catch (std::exception &e) {
        std::cout << RED << "⚠️ Exception: " << e.what() << RESET << std::endl;
    }

    printDivider();
    std::cout << BOLDWHITE << "🏁 End of FORM Simulation 🏁" << RESET << std::endl;
    return 0;
}
