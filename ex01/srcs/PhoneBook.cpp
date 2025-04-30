/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:22:18 by rtodaro           #+#    #+#             */
/*   Updated: 2025/04/30 17:39:06 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook() : size(0) {};
PhoneBook::~PhoneBook() {};


int	PhoneBook::get_size(void)
{
	return (this->size);
}

void	PhoneBook::print_contact(int index)
{
	this->contacts[index].print_info();
}

void	PhoneBook::add_contact(std::string info[5])
{
	int	i;
	
	i = this->size;
	contacts[i % 8].set_index(i % 8);
	contacts[i % 8].set_first_name(info[0]);
	contacts[i % 8].set_last_name(info[1]);
	contacts[i % 8].set_nickname(info[2]);
	contacts[i % 8].set_phone_number(info[3]);
	contacts[i % 8].set_darkest_secret(info[4]);
	this->size++;
}

static void print_column(std::string str) {
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::string(10 - str.length(), ' ') << str;
}

void PhoneBook::print_contacts(void) {
    int i = 0;

    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;

	while (i < this->size && i < 8)
	{
		std::cout << "|";
		std::cout << "         " << i << "|";
		print_column(contacts[i].get_first_name());
		std::cout << "|";
		print_column(contacts[i].get_last_name());
		std::cout << "|";
		print_column(contacts[i].get_nickname());
		std::cout << "|" << std::endl;
		i++;
		std::cout << "+----------+----------+----------+----------+" << std::endl;
	}
}

