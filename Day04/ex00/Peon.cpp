/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:28:19 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(void)
{
	this->_name = "Edward";
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::Peon(std::string name)
{
	this->_name = name;
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::Peon(const Peon &src)
{
	*this = src;
	return ;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
	return ;
}

Peon		&Peon::operator= (const Peon &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return (*this);
}

void		Peon::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a pink pony !" \
			<< std::endl;
	return ;
}
