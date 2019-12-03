/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:32:42 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/03 21:25:02 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneContact.hpp"

PhoneContact::PhoneContact(std::string _first_name, std::string _last_name,
	std::string _nickname, std::string _login, std::string _postal_address,
	std::string _email_address, std::string _phone_number,
	std::string _birthday_date, std::string _favorite_meal,
	std::string _underwear_color, std::string _darkest_secret) :
		first_name(_first_name), last_name(_last_name), nickname(_nickname),
		login(_login), postal_address(_postal_address), email_address(_email_address),
		phone_number(_phone_number), birthday_date(_birthday_date),
		favorite_meal(_favorite_meal), underwear_color(_underwear_color),
		darkest_secret(_darkest_secret) {}

PhoneContact::PhoneContact(void) {}

void		PhoneContact::displayField(std::string _field) const
{
	if (_field.size() > 10)
	{
		_field.resize(9);
		std::cout << std::setw(9) << std::setfill(' ') << _field << '.';
	}
	else
		std::cout << std::setw(10) << std::setfill(' ') << std::right << _field;
	std::cout << '|';
}

void		PhoneContact::displayContact(int index) const
{
	displayField(std::to_string(index));
	displayField(this->first_name);
	displayField(this->last_name);
	displayField(this->nickname);
	std::cout << std::endl;
}

PhoneContact	PhoneContact::createContact(void) const
{
	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_login;
	std::string		_postal_address;
	std::string		_email_address;
	std::string		_phone_number;
	std::string		_birthday_date;
	std::string		_favorite_meal;
	std::string		_underwear_color;
	std::string		_darkest_secret;

	std::cout << std::endl << "Created new Contact" << std::endl;
	std::cout << "Input First name : ";
	std::getline(std::cin, _first_name, '\n');
	std::cout << "Input Last name : ";
	std::getline(std::cin, _last_name, '\n');
	std::cout << "Input Nickname : ";
	std::getline(std::cin, _nickname, '\n');
	std::cout << "Input Login : ";
	std::getline(std::cin, _login, '\n');
	std::cout << "Input Postal address: ";
	std::getline(std::cin, _postal_address, '\n');
	std::cout << "Input Email address: ";
	std::getline(std::cin, _email_address, '\n');
	std::cout << "Input Phone number : ";
	std::getline(std::cin, _phone_number, '\n');
	std::cout << "Input Birthday date : ";
	std::getline(std::cin, _birthday_date, '\n');
	std::cout << "Input Favorite meal : ";
	std::getline(std::cin, _favorite_meal, '\n');
	std::cout << "Input Underwear color: ";
	std::getline(std::cin, _underwear_color, '\n');
	std::cout << "Input Darkest secret: ";
	std::getline(std::cin, _postal_address, '\n');
	std::cout << std::endl;
	if (std::cin.eof())
	{
		std::system("clear");
		std::cout << "\x1b[32mClose the programm\x1b[0m" << std::endl;
		exit(EXIT_SUCCESS);
	}
	return (PhoneContact(_first_name, _last_name, _nickname, _login, _postal_address, _email_address,
			_phone_number, _birthday_date, _favorite_meal, _underwear_color, _darkest_secret));
}

PhoneContact::~PhoneContact(void) {}
