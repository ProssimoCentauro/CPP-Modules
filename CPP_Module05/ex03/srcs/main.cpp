#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
    std::cout << BOLDWHITE << "☕ Intern Arena ☕" << RESET << std::endl;
    printDivider();
    sleep(1);

    Intern intern;
    Bureaucrat boss("Bob", 1);
    Bureaucrat newbie("Alice", 140);

    std::cout << CYAN << "👔 Bureaucrats ready:" << RESET << std::endl;
    std::cout << boss << std::endl;
    std::cout << newbie << std::endl;

    printDivider();
    sleep(1);

    std::cout << YELLOW << "🧠 Intern is creating forms..." << RESET << std::endl;

    AForm* shrub = intern.makeForm("shrubbery creation", "Garden");
    AForm* robo = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Marvin");

    std::cout << RED << "🚫 Invalid form creation attempt:" << RESET << std::endl;
    AForm* fail = intern.makeForm("coffee request", "Office");

    printDivider();
    sleep(1);

    std::cout << GREEN << "✅ Forms created successfully:" << RESET << std::endl;
    if (shrub) std::cout << *shrub << std::endl;
    if (robo) std::cout << *robo << std::endl;
    if (pardon) std::cout << *pardon << std::endl;

    printDivider();
    sleep(1);

    std::cout << CYAN << "🖋️  Signing forms..." << RESET << std::endl;
    try {
        newbie.signForm(*robo);   // should fail
        boss.signForm(*robo);     // should succeed
    } catch (std::exception &e) {
        std::cout << RED << "⚠️  Exception: " << e.what() << RESET << std::endl;
    }

    printDivider();
    sleep(1);

    std::cout << YELLOW << "⚙️  Executing forms..." << RESET << std::endl;
    try {
        boss.executeForm(*robo);
        boss.executeForm(*pardon);
    } catch (std::exception &e) {
        std::cout << RED << "⚠️  Exception: " << e.what() << RESET << std::endl;
    }

    printDivider();
    sleep(1);

    std::cout << GREEN << "🧹 Cleaning up memory..." << RESET << std::endl;
    delete shrub;
    delete robo;
    delete pardon;
    delete fail; // safe, may be NULL

    printDivider();
    std::cout << BOLDWHITE << "🏁 End of Intern Arena 🏁" << RESET << std::endl;

    return 0;
}
