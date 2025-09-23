#include "Bureaucrat.hpp"
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
    std::cout << BOLDWHITE << "🏛️ Bureaucrat Arena 🏛️" << RESET << std::endl;
    printDivider();

    try {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 1);
        Bureaucrat charlie("Charlie", 150);

        std::cout << CYAN << "📝 Initial info:" << RESET << std::endl;
        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        printDivider();
        sleep(1);

        // Increment grade normale
        std::cout << YELLOW << "⬆️ Alice increments grade" << RESET << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;

        // Increment grade troppo alto
        std::cout << RED << "⬆️ Bob increments grade (should throw GradeTooHighException)" << RESET << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

    } catch (std::exception &e) {
        std::cout << RED << "⚠️ Exception caught: " << e.what() << RESET << std::endl;
    }

    printDivider();
    sleep(1);

    try {
        Bureaucrat charlie("Charlie", 150);
        std::cout << GREEN << "⬇️ Charlie decrements grade (should throw GradeTooLowException)" << RESET << std::endl;
        charlie.decrementGrade();
        std::cout << charlie << std::endl;

    } catch (std::exception &e) {
        std::cout << RED << "⚠️ Exception caught: " << e.what() << RESET << std::endl;
    }

    printDivider();
    std::cout << BOLDWHITE << "🏁 End of Bureaucrat Simulation 🏁" << RESET << std::endl;

    return 0;
}

