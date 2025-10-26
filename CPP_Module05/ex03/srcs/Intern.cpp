#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

static AForm* makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* makePresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // function pointers array
    AForm* (*formCreators[3])(const std::string&) = {
        &makeShrubbery,
        &makeRobotomy,
        &makePresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Intern couldn’t find form \"" << formName << "\"" << std::endl;
    return NULL;
}
