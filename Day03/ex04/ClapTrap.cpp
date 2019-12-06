/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:57:47 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 23:32:50 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(unsigned int _hit_points, unsigned int _max_hit_points,
						unsigned int _energy_points, unsigned int _max_energy_points,
						unsigned int _level, std::string _name,
						unsigned int _melee_attack_damage, unsigned int _ranged_attack_damage,
						unsigned int _armor_damage_reduction) : hit_points(_hit_points),
						max_hit_points(_max_hit_points),
						energy_points(_energy_points),
						max_energy_points(_max_energy_points),
						level(_level),
						name(_name),
						melee_attack_damage(_melee_attack_damage),
						ranged_attack_damage(_ranged_attack_damage),
						armor_damage_reduction(_armor_damage_reduction) {}

ClapTrap::ClapTrap(const ClapTrap &Claptrap) : hit_points(Claptrap.hit_points),
						max_hit_points(Claptrap.max_hit_points),
						energy_points(Claptrap.energy_points),
						max_energy_points(Claptrap.max_energy_points),
						level(Claptrap.level),
						name(Claptrap.name),
						melee_attack_damage(Claptrap.melee_attack_damage),
						ranged_attack_damage(Claptrap.ranged_attack_damage),
						armor_damage_reduction(Claptrap.armor_damage_reduction) {}

void					ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << this->name << " attacks " << target
	<< " at range, causing " << this->ranged_attack_damage
	<< " points of damage**" << std::endl;
}

void					ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << this->name << " attacks " << target
	<< " at melee, causing " << this->melee_attack_damage
	<< " points of damage**" << std::endl;
}

void					ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->armor_damage_reduction)
		amount -= this->armor_damage_reduction;
	else
		amount = 0;
	amount = std::min(amount, this->hit_points);
	std::cout  << this->name << " take " << amount
	<< " points of damage**" << std::endl;
	this->hit_points -= amount;
}

void					ClapTrap::beRepaired(unsigned int amount)
{
	amount = std::min(amount, this->max_hit_points - this->hit_points);
	this->hit_points += amount;
	std::cout << this->name << " was repaired! Restored "
	<< amount << " hit points**" << std::endl;
}

std::string				ClapTrap::getName(void)
{
	return (this->name);
}

ClapTrap::~ClapTrap(void){}
