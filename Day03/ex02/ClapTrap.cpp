/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:57:47 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 22:16:42 by bdeomin          ###   ########.fr       */
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

ClapTrap::ClapTrap(const ClapTrap &_Claptrap) : hit_points(_Claptrap.hit_points),
						max_hit_points(_Claptrap.max_hit_points),
						energy_points(_Claptrap.energy_points),
						max_energy_points(_Claptrap.max_energy_points),
						level(_Claptrap.level),
						name(_Claptrap.name),
						melee_attack_damage(_Claptrap.melee_attack_damage),
						ranged_attack_damage(_Claptrap.ranged_attack_damage),
						armor_damage_reduction(_Claptrap.armor_damage_reduction) {}

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
	std::cout  << this->name << " take " << amount
	<< " points of damage**" << std::endl;
}

void					ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->name << " was repaired! Restored "
	<< amount << " hit points**" << std::endl;
}

ClapTrap::~ClapTrap(void){}
