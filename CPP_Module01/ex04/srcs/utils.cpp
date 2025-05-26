#include "sed.hpp"
/*
std::ifstream	if_open_file(std::string filename)
{
	std::ifstream infile(filename);
	
	if (!infile)
	{
		std::cout << RED << "ERROR OPENING FILE!" << RESET << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return (infile);
}

std::ofstream	of_open_file(std::string filename)
{
	std::ofstream outfile(filename);
	
	if (!outfile)
	{
		std::cout << RED << "ERROR OPENING FILE!" << RESET << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return (outfile);
}*/

void	check_args(int ac)
{
	if (ac != 4)
	{
		std::cout << RED << "INVALID NUMBER OF ARGUMENTS!" << RESET << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
