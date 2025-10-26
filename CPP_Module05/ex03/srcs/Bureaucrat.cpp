#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(100) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) { *this = other; }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	(void)other;
    return *this;
}

Bureaucrat::~Bureaucrat() {}


std::string Bureaucrat::getName( void ) const
{
	return this->name;
}


int	Bureaucrat::getGrade( void ) const
{
	return this->grade;
}

void	Bureaucrat::incrementGrade( void )
{
	if (this->grade == 1)
	{
		throw GradeTooHighException();
	}
	else
	{
		this->grade -= 1;
	}
}


void	Bureaucrat::decrementGrade( void )
{
	if (this->grade == 150)
	{
		throw GradeTooLowException();
	}
	else
	{
		this->grade += 1;
	}
}

void Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->getName() << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->getName() << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
