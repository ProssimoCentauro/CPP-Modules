/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:50:37 by rtodaro           #+#    #+#             */
/*   Updated: 2025/04/29 20:59:40 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "cstdlib"
static int		check_number(std::string number);
static int		execute_command(std::string line, PhoneBook phonebook);
static void		create_info(std::string* info, int size);

static int		check_number(std::string number)
{
	size_t	i = 0;

	while (number[i])
	{
		if (number[i] <= '0' || number[i] >= '9')
			return (1);
		i++;
	}
	return (0);
}

static int	execute_command(std::string line, PhoneBook phonebook)
{
	std::string info[5];

	if (line == "ADD")
	{
		create_info(info, phonebook.get_size());
		phonebook.add_contact(info);
	}
	else if (line == "EXIT")
		return (1);
	else
		std::cout << "INVALID COMMAND!" << std::endl;
	return (0);
}

static void	create_info(std::string* info, int size)
{
	if (size >= 8)
	{
		std::cout << "8 contacts limit reached." << std::endl;
		std::cout << "Adding another contact will overwrite the oldest added contact!" << std::endl;
	}
	std::cout << "CONTACT FIRST NAME: ";
	std::getline(std::cin, info[0]);
	std::cout << "CONTACT LAST NAME: ";
	std::getline(std::cin, info[1]);
	std::cout << "CONTACT NICKNAME: ";;
	std::getline(std::cin, info[2]);
	while (42)
	{
		std::cout << "CONTACT PHONE NUMBER: ";
		std::getline(std::cin, info[3]);
		if (check_number(info[3]))
		{
			std::cout << "INVALID PHONE NUMBER!" << std::endl;
			continue;
		}
		break;
	}
	std::cout << "CONTACT DARKEST SECRET: ";
	std::getline(std::cin, info[4]);
}

int	main()
{
	PhoneBook phonebook;
	std::string info[5];
	std::string	line;
	
	while (42)
	{
		std::cout << "Hi, welcome to your PhoneBook!" << std::endl;
		std::cout << "COMMANDS: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, line);
		if (execute_command(line, phonebook) == 1)
			break ;
	}
	return(EXIT_SUCCESS);
}
