#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    const std::string target;

public:
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    std::string getTarget() const;

    void beSigned(const Bureaucrat& b);
    void checkExecution(const Bureaucrat& executor) const;

    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
        const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
