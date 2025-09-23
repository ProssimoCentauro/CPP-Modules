#ifndef BUREAUCRATEXCEPTIONS_HPP
#define BUREAUCRATEXCEPTIONS_HPP

#include <exceptions>


class GradeTooHighException : public std::exception
{
	public:
		const char *what() const noexcept override
		{
			return "Grade is too high!";
		}
};

class GradeTooLowException : public std::exception
{
	public:
		const char* what() const noexcept override
		{
			return "Grade is too low!";
		}
};

#endif
