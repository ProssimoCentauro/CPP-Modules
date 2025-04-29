/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:49:37 by rtodaro           #+#    #+#             */
/*   Updated: 2025/04/29 15:27:07 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <sting>

class PhoneBook
{
	private:
		Contact contacts[8];
		int	size = 0;

	public:
		PhoneBook();
		~PhoneBook();
		//getters
		int	get_size(void);
		//setters
		void	add_contact(std::string info[5]);

}

#endif
