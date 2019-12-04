/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:21:46 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 18:38:39 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type) {}
Weapon::~Weapon(void) {}

const std::string	Weapon::getType(void)
{
	return this->type;
}

void				Weapon::setType(std::string _type)
{
	this->type = _type;
}


