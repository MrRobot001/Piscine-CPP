/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:28:35 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)
{
	this->_name = "Bella";
	this->_title = "la Sopla Vela";
	std::cout << this->_name << ", " << this->_title << ", is born !" \
			  << std::endl;
	return ;
}

Sorcerer::Sorcerer(const Sorcerer &src)
{
	*this = src;
	return ;
}

Sorcerer::Sorcerer(std::string name, std::string title)
{
	this->_name = name;
	this->_title = title;
	std::cout << this->_name << ", " << this->_title << ", is born !" \
			  << std::endl;
	return ;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title \
			  << ", is dead. Consequences will never be the same !" \
			  << std::endl;
	return ;
}

Sorcerer		&Sorcerer::operator= (const Sorcerer &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_title = rhs._title;
	}
	return (*this);
}

std::ostream	&operator<< (std::ostream &out, const Sorcerer &rhs)
{
	out << "I am " << rhs.getName() << ", " << rhs.getTitle() \
		<< ", and I like ponies ! " << std::endl;
	return (out);
}

void		Sorcerer::setName(std::string name)
{
	this->_name = name;
	return ;
}

void		Sorcerer::setTitle(std::string title)
{
	this->_title = title;
	return ;
}

void		Sorcerer::polymorph(const Victim &victim) const
{
	return (victim.getPolymorphed());
}

std::string		Sorcerer::getName(void) const
{
	return (this->_name);
}

std::string		Sorcerer::getTitle(void) const
{
	return (this->_title);
}
