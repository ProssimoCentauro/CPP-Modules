/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:22:18 by rtodaro           #+#    #+#             */
/*   Updated: 2025/04/29 15:44:39 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBokk::get_size(void)
{
	return (this->size);
}

void	PhoneBook::add_contact(std::string info[5])
{
	int	i;
	
	i == this->size;
	contacts[i % 8].set_index(i % 8);
	contacts[i % 8].set_first_name(info[0]);
	contacts[i % 8].set_last_name(info[1]);
	contacts[i % 8].set_nickname(info[2]);
	contacts[i % 8].set_phone_number(info[3]);
	contacts[i % 8].set_darkest_secret(info[4]);
	this->index++;
}
