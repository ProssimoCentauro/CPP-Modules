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

void	get_info(std::string* info)
{
	info[0] = "ciao";
	info[1] = "ciao";
	info[2] = "ciao";
	info[3] = "ciao";
	info[4] = "ciao";
}

int	main()
{
	PhoneBook phonebook;
	std::string info[5];
	std::cout << "Hi, welcome to your PhoneBook!" << std::endl;
	std::cout << "COMMANDS: ADD, SEARCH, EXIT" << std::endl;

	get_info(info);
	phonebook.add_contact(info);

	return(EXIT_SUCCESS);
}
