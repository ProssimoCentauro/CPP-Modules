#include <iostream>
#include <vector>
#include <list>
#include <unistd.h> // sleep
#include "easyfind.hpp"

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

int main()
{
    std::cout << BOLDWHITE << "🔎 Easyfind Arena 🔎" << RESET << std::endl;
    printDivider();
    sleep(1);

    // ===== VECTOR TEST =====
    std::vector<int> v;
    for (int i = 1; i <= 5; ++i) v.push_back(i);

    std::cout << CYAN << "📝 Vector initial values: ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;

    printDivider();
    sleep(1);

    try {
        std::cout << YELLOW << "🔍 Searching for 3 in vector..." << RESET << std::endl;
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << GREEN << "✔ Found: " << *it << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "⚠️ Exception caught: " << e.what() << RESET << std::endl;
    }

    sleep(1);

    try {
        std::cout << YELLOW << "🔍 Searching for 42 in vector..." << RESET << std::endl;
        easyfind(v, 42);
        std::cout << RED << "✘ Error: should not reach here" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✔ Exception correctly caught: " << e.what() << RESET << std::endl;
    }

    printDivider();
    sleep(1);

    // ===== LIST TEST =====
    std::list<int> l;
    for (int i = 10; i <= 50; i += 10) l.push_back(i);

    std::cout << CYAN << "📝 List initial values: ";
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;

    printDivider();
    sleep(1);

    try {
        std::cout << YELLOW << "🔍 Searching for 50 in list..." << RESET << std::endl;
        std::list<int>::iterator it = easyfind(l, 50);
        std::cout << GREEN << "✔ Found: " << *it << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "⚠️ Exception caught: " << e.what() << RESET << std::endl;
    }

    sleep(1);

    try {
        std::cout << YELLOW << "🔍 Searching for -1 in list..." << RESET << std::endl;
        easyfind(l, -1);
        std::cout << RED << "✘ Error: should not reach here" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✔ Exception correctly caught: " << e.what() << RESET << std::endl;
    }

    printDivider();
    std::cout << BOLDWHITE << "🏁 End of Easyfind Simulation 🏁" << RESET << std::endl;

    return 0;
}
