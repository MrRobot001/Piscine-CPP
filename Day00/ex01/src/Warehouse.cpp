/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warehouse.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:40:51 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/03 14:42:14 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Warehouse.hpp"

Warehouse::Warehouse(void) : count(0), contacts() {}

int				Warehouse::getCount(void) const
{
	return (this->count);
}

void			Warehouse::addContact(PhoneContact _contact)
{
	if (this->count > 7)
		std::cout << "\x1b[31mPhonebook is full. Contact not added\x1b[0m" << std::endl;
	else
	{
		this->contacts[this->count++] = _contact;
		std::cout << "\x1b[32mContact created\x1b[0m" << std::endl;
	}
}

void			Warehouse::displayPhonebook(void) const
{
	int		index;

	index = -1;
	if (this->count == 0)
	{
		std::cout << "\x1b[33mSorry... Phonebook is empty.\x1b[0m" <<  std::endl;
		return ;
	}
	std::cout << std::setw(44) << std::setfill('-') << '-';
	std::cout << std::endl;
	while (++index < this->count)
		this->contacts[index].displayContact(index);
	std::cout << std::setw(44) << std::setfill('-') << '-';
	std::cout << std::endl;
}

Warehouse::~Warehouse(void) {}
