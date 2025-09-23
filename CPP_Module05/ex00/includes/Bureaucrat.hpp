#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "BureaucratExceptions.hpp"

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

	std::string	getName( void ) const;
	int	getGrade( void ) const;

	void	incrementGrade( void );
	void	decrementGrade( void );

private:
	const std::string	name;
	int					grade;
};

#endif
