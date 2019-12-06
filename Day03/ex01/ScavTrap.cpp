/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:42:52 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 18:42:02 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

				ScavTrap::ScavTrap(std::string _name) :
					hit_points(100), max_hit_points(100),
					energy_points(50), max_energy_points(50),
					level(1), name(_name), melee_attack_damage(20),
					ranged_attack_damage(15), armor_damage_reduction(3)
{
	std::cout << "Hello minion! If you wonna enter you need a quest."
	<< "Oh, and I have something for you." << std::endl;
}

				ScavTrap::ScavTrap(const ScavTrap &Scaptrap) :
					hit_points(Scaptrap.hit_points),
					max_hit_points(Scaptrap.max_hit_points),
					energy_points(Scaptrap.energy_points),
					max_energy_points(Scaptrap.max_energy_points),
					level(1), name(Scaptrap.name),
					melee_attack_damage(Scaptrap.melee_attack_damage),
					ranged_attack_damage(Scaptrap.ranged_attack_damage),
					armor_damage_reduction(Scaptrap.armor_damage_reduction)
{
	std::cout << "Hello minion! If you wonna enter you need a quest."
	<< "Oh, and I have something for you." << std::endl;
}

ScavTrap		&ScavTrap::operator= (const ScavTrap &Scaptrap)
{
	std::cout << "Who else is there? Ohhh... it's you again... OK" << std::endl;
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

std::string		ScavTrap::challenges[5] =
{
	"Ok. I'm not have banana! And I'm wont have banana! So bring me banana!!!",
	"Do you want to go there with this? Oh no no no... You gotta have a bigger gun. \
Look at my... Chk-chk, BOOM!",
	"How does math work? Does this skin make me look fat? If a giraffe and a car had a \
baby, would it be called a caraffe? Life's big questions, man. You will answer them and you are inside!",
	"Oh. My. God. What if I'm like... a fish? And, if I'm not moving... I stop breathing? \
AND THEN I'LL DIE! HELP ME! HELP MEEEEE HEE HEE HEEE! HHHHHHHELP!",
	"So, this one time, I went to a party, and there was a beautiful subatomic particle \
accelerator there. Our circuits locked across the room and... I don't remember what happened next. \
I mean, I can't. We coulda gotten married and had gadgets together, but now, I'll never know. \
So bring me something that would cheer me up."
};

void			ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "Hehehehe, mwaa ha ha ha, MWAA HA HA HA!" << std::endl;
	std::cout << "**SC4G-TP " << this->name << " attacks " << target
	<< " at range, causing " << this->ranged_attack_damage
	<< " points of damage**" << std::endl;
}

void			ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << "Guess who?" << std::endl;
	std::cout << "**SC4G-TP " << this->name << " attacks " << target
	<< " at melee, causing " << this->melee_attack_damage
	<< " points of damage**" << std::endl;
}

void			ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "I'm too pretty to die!" << std::endl;
	if (amount > this->armor_damage_reduction)
		amount -= this->armor_damage_reduction;
	else
		amount = 0;
	amount = std::min(amount, this->hit_points);
	std::cout << "**SC4G-TP " << this->name << " take " << amount
	<< " points of damage**" << std::endl;

	this->hit_points -= amount;
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	amount = std::min(amount, this->max_hit_points - this->hit_points);
	std::cout << "You're the wub to my dub" << std::endl;
	std::cout << "**SC4G-TP " << this->name << " was repaired! Restored "
	<< amount << " hit points**" << std::endl;

	this->hit_points += amount;
}

void			ScavTrap::challengeNewcomer(std::string const & target)
{
	std::cout << ScavTrap::challenges[std::rand() % 5] << std::endl;
	std::cout << "**SC4G-TP " << this->name
	<< " give a new mission to " << target << "**" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Oh... WELL!!! Crap happens." << std::endl;
}
