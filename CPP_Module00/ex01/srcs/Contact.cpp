/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:11:31 by rtodaro           #+#    #+#             */
/*   Updated: 2025/05/05 14:48:52 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "Contact.hpp"


Contact::Contact() {};
Contact::~Contact() {};

void	Contact::set_index(int index)
{
	this->index = index;
}

void	Contact::set_first_name(std::string str)
{
	this->first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	this->last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	this->nickname = str;	
}

void	Contact::set_phone_number(std::string str)
{
	this->phone_number = str;
}

void	Contact::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}

int	Contact::get_index(void)
{
	return (this->index);
}

std::string Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string Contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string Contact::get_darkest_secret(void)
{
	return (this->darkest_secret);
}

void	Contact::print_info(void)
{
	std::cout << "first name: " << this->get_first_name() << std::endl;
	std::cout << "last name: " << this->get_last_name() << std::endl;
	std::cout << "nickname: " << this->get_nickname() << std::endl;
	std::cout << "phone number: " << this->get_phone_number() << std::endl;
	std::cout << "darkset secret: " << this->get_darkest_secret() << std::endl;
	std::cout << std::endl;
}
