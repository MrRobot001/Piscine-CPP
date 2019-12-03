/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:17:59 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/03 21:26:51 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"
#include <stdio.h>
Menu*	Menu::_self(0);

Menu*	Menu::Create_menu(void)
{
	if (!_self)
		_self = new Menu();
	return (_self);
}

void	Menu::Run(void)
{
	int			i;
	std::string	comand;

	do
	{
		i = 0;
		std::system("clear");
		std::cout <<  std::endl << "--------------- MENU ---------------" << std::endl;
		std::cout << "<1>.ADD Contact in Phonebook" << std::endl;
		std::cout << "<2>.SEARCH in Phonebook" << std::endl;
		std::cout << "<3>.EXIT and close program" << std::endl;
		std::cout << std::endl << "Input : ";
		std::getline(std::cin, comand, '\n');
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::system("clear");
			std::cout << "\x1b[32mClose the programm\x1b[0m" << std::endl;
			exit(EXIT_SUCCESS);
		}
		else if (comand == "ADD")
			i = 1;
		else if (comand == "SEARCH")
			i = 2;
		else if (comand == "EXIT")
			i = 3;
		switch (i)
		{
		case 1:
		{
			std::system("clear");
			PhoneContact contact;

			if (Phonebook.getCount() < 8)
				contact = contact.createContact();
			Phonebook.addContact(contact);
			std::cout << std::endl << "Press enter to continue ...";
			std::cin.get();
			break ;
		}
		case 2:
		{
			std::system("clear");
			Phonebook.displayPhonebook();
			std::cout << std::endl << "Press enter to continue ...";
			std::cin.get();
			break ;
		}
		case 3:
		{
			std::system("clear");
			std::cout << "\x1b[32mClose the programm\x1b[0m" << std::endl;
			break ;
		}
		default:
			std::system("clear");
			std::cout << "\x1b[31mYour choise is not correct...\x1b[0m" << std::endl;
			std::cout << std::endl << "Press enter to continue ...";
			std::cin.get();
		}
	} while (i != 3);
}

bool	Menu::Delete_munu(void)
{
	if (_self)
	{
		delete _self;
		_self = 0;
		return (true);
	}
	return (false);
}
