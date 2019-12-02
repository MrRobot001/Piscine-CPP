/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warehouse.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:40:51 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/02 23:00:42 by bdeomin          ###   ########.fr       */
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
	{
		std::cout << "Phonebook is full" << std::endl;
		return ;
	}
	this->contacts[this->count++] = _contact;
}

PhoneContact	Warehouse::getContact(int number) const
{
	return (this->contacts[number]);
}

void			Warehouse::displayPhonebook(void) const
{
	int		index;

	index = -1;
	if (this->count == 0)
	{
		std::cout << "Sorry... Phonebook is empty. Contact not added" << std::endl << std::endl;
		return ;
	}
	while (++index < this->count)
		this->contacts[index].displayContact(index);
}

Warehouse::~Warehouse(void) {}
