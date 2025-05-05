/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:50:37 by rtodaro           #+#    #+#             */
/*   Updated: 2025/05/05 18:01:56 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "cstdlib"


#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

static int		check_number(std::string number);
static int		get_index(PhoneBook& phonebook);
static int		execute_command(std::string line, PhoneBook& phonebook);
static int		input_contact_field(const std::string str, std::string& info, int phone_number);
static int		create_info(std::string* info, PhoneBook& phonebook);

static int		check_number(std::string number)
{
	size_t	i = 0;

	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	get_index(PhoneBook& phonebook)
{
	std::string index;
	while (42)
	{
		std::cout << "SELECT THE CONTACT TO SEE DETAILS: ";
		std::getline(std::cin, index);
		if (!std::cin)
			exit (1);
		if (index.length() > 1 || index[0] < '0' || index[0] > '7' || index[0] >= phonebook.get_size() + '0')
		{
			std::cout << RED << "INVALID INDEX!" << RESET << std::endl;
			continue ;
		}
		break ;
	}
	return (index[0] - '0');
}

static int	execute_command(std::string line, PhoneBook& phonebook)
{
	std::string info[5];

	if (line == "ADD")
	{
		if (create_info(info, phonebook) == 1)
			return (1);
		phonebook.add_contact(info);
		std::cout << GREEN << "\nCONTACT ADDED SUCCESSFULLY!\n" << RESET << std::endl;
	}
	else if (line == "SEARCH")
	{
		if (phonebook.print_contacts() == false)
		{
			std::cout << RED << "NO CONTACTS IN YOUR PHONEBOOK!\n" << RESET << std::endl;
			return (0);
		}
		phonebook.print_contact(get_index(phonebook));
	}
	else if (line == "EXIT")
		return (1);
	else
		std::cout << RED << "INVALID COMMAND!\n" << RESET << std::endl;
	return (0);
}

static int	input_contact_field(const std::string str, std::string& info, int phone_number)
{
	while (42)
	{
		std::cout << str;
		std::getline(std::cin, info);
		if (!std::cin)
			return (1);
		if (info == "")
		{
			std::cout << RED << "A CONTACT CAN'T HAVE EMPTY FIELDS!" << RESET << std::endl;
			continue ;
		}
		if (phone_number == 1)
		{
			if (check_number(info))
			{
				std::cout << RED << "INVALID PHONE NUMBER!" << RESET << std::endl;
				continue;
			}
		}
		break ;
	}
	return (0);
}

static int	create_info(std::string* info, PhoneBook& phonebook)
{
	if (phonebook.is_full())
	{
		std::cout << YELLOW << "\n8 contacts limit reached." << std::endl;
		std::cout << "Adding another contact will overwrite the oldest added contact!\n" << RESET << std::endl;
	}
	if (input_contact_field("CONTACT FIRST NAME: ", info[0], 0) == 1)
		return (1);
	if (input_contact_field("CONTACT LAST NAME: ", info[1], 0) == 1)
		return (1);
	if (input_contact_field("CONTACT NICKNAME: ", info[2], 0) == 1)
		return (1);
	if (input_contact_field("CONTACT PHONE NUMBER: ", info[3], 1) == 1)
		return (1);
	if (input_contact_field("CONTACT DARKEST SECRET: ", info[4], 0) == 1)
		return (1);
	return (0);
}

int	main()
{
	PhoneBook phonebook;
	std::string info[5];
	std::string	line;
	
	std::cout << BLUE << "Hi, welcome to your PhoneBook!" << RESET << std::endl;
	while (42)
	{
		std::cout << "COMMANDS: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, line);
		if (!std::cin)
			return (1);
		std::cout << std::endl;
		if (execute_command(line, phonebook) == 1)
			break ;
	}
	return(EXIT_SUCCESS);
}
