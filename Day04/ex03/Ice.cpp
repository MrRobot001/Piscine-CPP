/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:47:08 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){}

Ice::Ice(const Ice &src)
{
	*this = src;
}

Ice::~Ice(void)
{
}

Ice
&Ice::operator= (const Ice &rhs)
{
	if (this != &rhs)
	{
		this->xp_ = rhs.xp_;
	}
	return (*this);
}

AMateria
*Ice::clone(void) const
{
	return (new Ice());
}

void
Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" \
			<< std::endl;
}
