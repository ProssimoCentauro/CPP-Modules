/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:49:37 by rtodaro           #+#    #+#             */
/*   Updated: 2025/05/05 14:02:28 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
	private:
		Contact contacts[8];
		int	size;
		int	index;

	public:
		PhoneBook();
		~PhoneBook();
		//getters
		int	get_size(void);
		//setters
		void	add_contact(std::string info[5]);
		//print funcs
		void	print_contact(int index);
		bool	print_contacts(void);
		bool	is_full(void);
};

#endif
