/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:46:29 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(const std::string &type)
{
	this->xp_ = 0;
	this->_type = type;
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria::~AMateria(void) {}

AMateria				&AMateria::operator= (const AMateria &rhs)
{
	if (this != &rhs)
	{
		this->xp_ = rhs.xp_;
		this->_type = rhs._type;
	}
	return (*this);
}

const std::string		&AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int  AMateria::getXP(void) const
{
	return (this->xp_);
}
