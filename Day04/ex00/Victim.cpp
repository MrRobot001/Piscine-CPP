/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:28:48 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(void)
{
	this->_name = "Joe";
	std::cout << "Some random victim called " << this->_name \
			  << " just popped !" << std::endl;
	return ;
}

Victim::Victim(std::string name)
{
	this->_name = name;
	std::cout << "Some random victim called " << this->_name \
			  << " just popped !" << std::endl;
	return ;
}

Victim::Victim(const Victim &src)
{
	*this = src;
	return ;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->_name \
			  << " just died for no apparent reason !" << std::endl;
	return ;
}

Victim			&Victim::operator= (const Victim &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return (*this);
}

std::ostream	&operator<< (std::ostream &out, const Victim &rhs)
{
	out << "I am " << rhs.getName() << ", and I like otters ! " \
		<< std::endl;
	return (out);
}

std::string		Victim::getName(void) const
{
	return (this->_name);
}

void			Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" \
			  << std::endl;
	return ;
}

void			Victim::setName(std::string name)
{
	this->_name = name;
	return ;
}
