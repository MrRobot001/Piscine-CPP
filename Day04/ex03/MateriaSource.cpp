/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:47:44 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	this->_n_index = 0;
	for (int i = 0; i < 4; i += 1)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource::~MateriaSource(void) {}

MateriaSource	&MateriaSource::operator= (const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i += 1)
		{
			this->_inventory[i] = NULL;
			this->_inventory[i] = rhs._inventory[0]->clone();
		}
		this->_n_index = rhs._n_index;
	}
	return (*this);
}

void			MateriaSource::learnMateria(AMateria *m)
{
	if (this->_n_index < 3)
	{
		this->_inventory[this->_n_index] = m;
		this->_n_index += 1;
	}
}

AMateria		*MateriaSource::createMateria(const std::string &type)
{
	if (type == "ice")
		return (new Ice());
	else if (type == "cure")
		return (new Cure());
	return (NULL);
}
