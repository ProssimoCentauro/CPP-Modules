#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Generic AForm"), isSigned(false), gradeToSign(150), gradeToExecute(150), target("undefined") {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute),
      target(other.target) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }
std::string AForm::getTarget() const { return target; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade too low!";
}
const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form \"" << f.getName() << "\" (target: " << f.getTarget() << "), signed: "
       << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to exec: " << f.getGradeToExecute();
    return os;
}
