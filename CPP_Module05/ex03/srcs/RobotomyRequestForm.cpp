#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45, "undefined") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    (void)other;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor);
    std::cout << "🤖 *Drilling noises*..." << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy on " << getTarget() << " failed!" << std::endl;
}
