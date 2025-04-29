/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:41:31 by rtodaro           #+#    #+#             */
/*   Updated: 2025/04/29 20:35:48 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		int	index;
		std::string	first_name;
		std::string	last_name;
		std::string nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:	
		Contact();
		~Contact();

		//getters
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);
		//setters
		void	set_index(int index);
		void	set_first_name(std::string str);
		void	set_last_name(std::string str);
		void	set_nickname(std::string str);
		void	set_phone_number(std::string str);
		void	set_darkest_secret(std::string str);
		//print functions
		void	print_info(void);
};
#endif
