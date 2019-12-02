/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:17:59 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/02 23:00:51 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"

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
	std::string	ch;

	do
	{
		std::cout <<  std::endl << "--------------- MENU ---------------" << std::endl;
		std::cout << "<1>.ADD Contact in Phonebook" << std::endl;
		std::cout << "<2>.SEARCH in Phonebook" << std::endl;
		std::cout << "<3>.EXIT and close program" << std::endl;
		std::cout << std::endl << "Input : ";
		std::getline(std::cin, ch, '\n');
		i = atoi(ch.c_str());

		switch (i)
		{
		case 1:
		{
			PhoneContact contact;

			Phonebook.addContact(contact.createContact());
			break ;
		}
		case 2:
		{
			Phonebook.displayPhonebook();
			break ;
		}
		case 3:
		{
			std::cout << "Close the programm" << std::endl;
			break ;
		}
		default:
			std::cout << "Your choise is not correct..." << std::endl << std::endl;
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
