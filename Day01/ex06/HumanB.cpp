/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:21:43 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 19:15:46 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name) {}
HumanB::~HumanB(void) {}

void		HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}

void		HumanB::attack(void) const
{
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
