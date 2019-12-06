/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 22:27:25 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 23:32:31 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string _name) : ClapTrap(60, 60, 120, 120, 1, _name, 60, 5, 0)
{
	std::cout << "NIJAA... QUUUAAAAA" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &_Claptrap) : ClapTrap(_Claptrap)
{
	std::cout << "NIJAA... QUUUAAAAA" << std::endl;
}

NinjaTrap		&NinjaTrap::operator= (const NinjaTrap &Scaptrap)
{
	std::cout << "QUUUAAAAA JAAAAA..." << std::endl;
	this->hit_points = Scaptrap.hit_points;
	this->max_hit_points = Scaptrap.max_hit_points;
	this->energy_points = Scaptrap.energy_points;
	this->max_energy_points = Scaptrap.max_energy_points;
	this->level = Scaptrap.level;
	this->name = Scaptrap.name;
	this->melee_attack_damage = Scaptrap.melee_attack_damage;
	this->ranged_attack_damage = Scaptrap.ranged_attack_damage;
	this->armor_damage_reduction = Scaptrap.armor_damage_reduction;
	return *this;
}

void			NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << "I'm on a roll!" << std::endl;
	std::cout << "**N1NJ-TP ";
	ClapTrap::rangedAttack(target);
}

void			NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << "Meet professor punch!" << std::endl;
	std::cout << "**N1NJ-TP ";
	ClapTrap::meleeAttack(target);
}

void			NinjaTrap::takeDamage(unsigned int amount)
{
	/*if (amount > this->armor_damage_reduction)
		amount -= this->armor_damage_reduction;
	else
		amount = 0;
	amount = std::min(amount, this->hit_points);*/
	std::cout << "Aww! Come on!" << std::endl;
	std::cout << "**N1NJ-TP ";
	ClapTrap::takeDamage(amount);
	//this->hit_points -= amount;
}

void			NinjaTrap::beRepaired(unsigned int amount)
{
	//amount = std::min(amount, this->max_hit_points - this->hit_points);
	std::cout << "Holy crap, that worked?" << std::endl;
	std::cout << "**N1NJ-TP ";
	ClapTrap::beRepaired(amount);
	//this->hit_points += amount;
}

void NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
	std::cout << "Oh! Another ninja!" << std::endl;
	std::cout << "**Shoeboxing " << target.getName() << "**" << std::endl;
}
void NinjaTrap::ninjaShoebox(ClapTrap & target)
{
	std::cout << "Mmmm... CL4P-TP, we meet again..." << std::endl;
	std::cout << "**Shoeboxing " << target.getName() << "**" << std::endl;
}
void NinjaTrap::ninjaShoebox(FragTrap & target)
{
	std::cout << "Ah, you must be the famous FR4G-TP!" << std::endl;
	std::cout << "**Shoeboxing " << target.getName() << "**" << std::endl;
}
void NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	std::cout << "Can you even fight? You're a glorified butler."
		<< std::endl;
	std::cout << "**Shoeboxing " << target.getName() << "**" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "Badamtsss...." << std::endl;
}
