/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:32:44 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/02 21:14:53 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONECONTACT_HPP
#define PHONECONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class	PhoneContact
{
	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		login;
		std::string		postal_address;
		std::string		email_address;
		std::string		phone_number;
		std::string		birthday_date;
		std::string		favorite_meal;
		std::string		underwear_color;
		std::string		darkest_secret;
	public:
		PhoneContact(std::string _first_name, std::string _last_name,
			std::string _nickname, std::string _login, std::string _postal_address,
			std::string _email_address, std::string _phone_number,
			std::string _birthday_date, std::string _favorite_meal,
			std::string _underwear_color, std::string _darkest_secret);
		PhoneContact(void);

		void			displayField(std::string) const;
		PhoneContact	createContact(void) const;
		void			displayContact(int index) const;

		virtual			~PhoneContact(void);

};

#endif
