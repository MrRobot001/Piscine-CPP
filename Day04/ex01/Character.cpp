/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:31:09 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {}

Character::Character(const Character &src)
{
	*this = src;
}

Character::Character(const std::string &name)
{
	this->_ap = 40;
	this->_name = name;
	this->_weapon = NULL;
}

Character::~Character(void) {}

Character			&Character::operator= (const Character &rhs)
{
	if (this != &rhs)
	{
		this->_ap = rhs._ap;
		this->_name = rhs._name;
		this->_weapon = rhs._weapon;
	}
	return (*this);
}

std::ostream	&operator<< (std::ostream &out, const Character &rhs)
{
	if (rhs.getWeapon() != NULL)
	{
		out << rhs.getName() << " has " << rhs.getAP() \
			<< " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	}
	else
	{
		out << rhs.getName() << " has " << rhs.getAP() \
			<< " AP and is unarmend" << std::endl;
	}
	return (out);
}

void				Character::recoverAP(void)
{
	if (this->_ap <= 30)
		this->_ap += 10;
	else
		this->_ap = 40;
}

void				Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void				Character::attack(Enemy *enemy)
{
	int   ap_cost;

	if (this->_weapon != NULL && enemy != NULL)
	{
		ap_cost = this->_weapon->getAPCost();
		if (this->_ap - ap_cost >= 0)
		{
		  this->_weapon->attack();
		  enemy->takeDamage(this->_weapon->getDamage());
		  if (enemy->getHP() <= 0)
			  delete enemy;
		  this->_ap -= ap_cost;
		  std::cout << this->_name << " attacks " << enemy->getType() \
					<< "with a " << this->_weapon->getName() << std::endl;
		}
	}
}

int					Character::getAP(void) const
{
	return (this->_ap);
}

AWeapon				*Character::getWeapon(void) const
{
	return (this->_weapon);
}

const std::string	Character::getName(void) const
{
	return (this->_name);
}
