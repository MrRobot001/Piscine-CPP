/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:21:18 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 19:18:22 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon) :  weapon(_weapon), name(_name){}
HumanA::~HumanA(void) {}

void		HumanA::attack(void) const
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

