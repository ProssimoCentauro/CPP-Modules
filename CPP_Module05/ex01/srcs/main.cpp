#include "Bureaucrat.hpp"
#include "Form.hpp"
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
    std::cout << BOLDWHITE << "🏛️ Bureaucrat & Form Arena 🏛️" << RESET << std::endl;
    printDivider();

    try {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 1);
        Bureaucrat charlie("Charlie", 150);

        std::cout << CYAN << "🧾 Initial Bureaucrats:" << RESET << std::endl;
        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;

        printDivider();
        sleep(1);

        // --- Test creazione Form validi ---
        std::cout << CYAN << "📄 Creating valid Forms..." << RESET << std::endl;
        Form taxForm("Tax Declaration", 40, 20);
        Form holidayForm("Holiday Request", 100, 80);
        Form impossibleForm("Impossible Form", 1, 1);

        std::cout << taxForm << std::endl;
        std::cout << holidayForm << std::endl;
        std::cout << impossibleForm << std::endl;

        printDivider();
        sleep(1);

        // --- Test eccezioni di costruzione ---
        std::cout << YELLOW << "⚠️ Testing invalid Form creation:" << RESET << std::endl;
        try {
            std::cout << "Creating Form with gradeToSign = 0 (too high)" << std::endl;
            Form badForm1("BadFormHigh", 0, 50);
        } catch (std::exception &e) {
            std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
        }

        try {
            std::cout << "Creating Form with gradeToExecute = 151 (too low)" << std::endl;
            Form badForm2("BadFormLow", 50, 151);
        } catch (std::exception &e) {
            std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
        }

        printDivider();
        sleep(1);

        // --- Tentativi di firma ---
        std::cout << YELLOW << "🖋️  Signing attempts:" << RESET << std::endl;

        std::cout << GREEN << "➡️  Alice tries to sign Tax Declaration" << RESET << std::endl;
        alice.signForm(taxForm);

        std::cout << GREEN << "➡️  Charlie tries to sign Holiday Request" << RESET << std::endl;
        charlie.signForm(holidayForm);

        std::cout << GREEN << "➡️  Bob tries to sign Impossible Form" << RESET << std::endl;
        bob.signForm(impossibleForm);

        printDivider();
        sleep(1);

        // --- Mostra stato finale dei moduli ---
        std::cout << CYAN << "📜 Final Form States:" << RESET << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << holidayForm << std::endl;
        std::cout << impossibleForm << std::endl;

        printDivider();
        sleep(1);

        // --- Test eccezioni dei gradi Bureaucrat ---
        std::cout << YELLOW << "⬆️ Bob increments grade (should throw)" << RESET << std::endl;
        bob.incrementGrade(); // dovrebbe lanciare eccezione

    } catch (std::exception &e) {
        std::cout << RED << "⚠️ Exception caught: " << e.what() << RESET << std::endl;
    }

    printDivider();
    sleep(1);

    try {
        Bureaucrat charlie("Charlie", 150);
        std::cout << GREEN << "⬇️ Charlie decrements grade (should throw)" << RESET << std::endl;
        charlie.decrementGrade();
        std::cout << charlie << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "⚠️ Exception caught: " << e.what() << RESET << std::endl;
    }

    printDivider();
    std::cout << BOLDWHITE << "🏁 End of Bureaucrat & Form Simulation 🏁" << RESET << std::endl;

    return 0;
}

