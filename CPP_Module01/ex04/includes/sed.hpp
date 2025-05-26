#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"


std::ifstream	if_open_file(std::string filename);
std::ofstream	of_open_file(std::string filename);

void	check_args(int ac);

#endif
