#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


std::ifstream	if_open_file(std::string filename)
{
	std::ifstream infile(filename);
	
	if (!infile)
	{
		std::cout << "ERROR OPENING FILE!" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (infile);
}

std::ofstream	of_open_file(std::string filename)
{
	std::ofstream outfile(filename);
	
	if (!outfile)
	{
		std::cout << "ERROR OPENING FILE!" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (outfile);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "INVALID NUMBER OF ARGUMENTS!" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string		line;
	std::string		filename = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		new_file;
	std::ifstream	infile;
	std::ofstream	outfile;
	size_t			pos;


	new_file = filename + ".replace";
	infile = if_open_file(av[1]);
	outfile = of_open_file(new_file);
	
	while (std::getline(infile, line))
	{
		size_t	i = 0;
		while (line[i])
		{
			pos = line.substr(i).find(s1);
			if (pos != std::string::npos)
			{
				//while (i < pos)
				std::cout << line.substr(i, pos);//[i++];
				std::cout << s2;
				i += pos + s1.length();
			}
			else
			{
				std::cout << line.substr(i);
				break ;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
