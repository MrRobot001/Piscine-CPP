/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:44:24 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 23:32:53 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name) : ClapTrap(100, 100, 100, 100, 1, _name, 30, 20, 5)
{
	std::cout << "Hello servant! Welcome to the Vault!"
	<< " So, will the parade in honor of my return be later?" << std::endl;
}

FragTrap::FragTrap(const FragTrap &_Claptrap) : ClapTrap(_Claptrap)
{
	std::cout << "Hello servant! Welcome to the Vault!"
	<< " So, will the parade in honor of my return be later?" << std::endl;
}

FragTrap		&FragTrap::operator= (const FragTrap &Claptrap)
{
	std::cout << "Ohhh ... It's me, again." << std::endl;
	this->hit_points = Claptrap.hit_points;
	this->max_hit_points = Claptrap.max_hit_points;
	this->energy_points = Claptrap.energy_points;
	this->max_energy_points = Claptrap.max_energy_points;
	this->level = Claptrap.level;
	this->name = Claptrap.name;
	this->melee_attack_damage = Claptrap.melee_attack_damage;
	this->ranged_attack_damage = Claptrap.ranged_attack_damage;
	this->armor_damage_reduction = Claptrap.armor_damage_reduction;
	return *this;
}

std::string		FragTrap::activating_vaulthunter[25] =
{
	"This time it'll be awesome, I promise!",
	"Hey everybody, check out my package!",
	"Place your bets!",
	"Defragmenting!",
	"Recompiling my combat code!",
	"Running the sequencer!",
	"It's happening... it's happening!",
	"It's about to get magical!",
	"I'm pulling tricks outta my hat!",
	"You can't just program this level of excitement!",
	"What will he do next?",
	"Things are about to get awesome!",
	"Let's get this party started!",
	"Glitchy weirdness is term of endearment, right?",
	"Push this button, flip this dongle, voila! Help me!",
	"square the I, carry the 1... YES!",
	"Resequencing combat protocols!",
	"Look out everybody, things are about to get awesome!",
	"I have an IDEA!",
	"Round and around and around she goes!",
	"It's like a box of chocolates...",
	"Step right up to the sequence of Trapping!",
	"Hey everybody, check out my package!",
	"Loading combat packages!",
	"F to the R to the 4 to the G to the WHAAT!"
};

void			FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "I'm a tornado of death and bullets!" << std::endl;
	std::cout << "**FR4G-TP ";
	ClapTrap::rangedAttack(target);
}

void			FragTrap::meleeAttack(std::string const &target)
{
	std::cout << "Ready for the PUNCHline?!" << std::endl;
	std::cout << "**FR4G-TP ";
	ClapTrap::meleeAttack(target);
}

void			FragTrap::takeDamage(unsigned int amount)
{
	/*if (amount > this->armor_damage_reduction)
		amount -= this->armor_damage_reduction;
	else
		amount = 0;
	amount = std::min(amount, this->hit_points);*/
	std::cout << "I bet your mom could do better!" << std::endl;
	std::cout << "**FR4G-TP ";
	ClapTrap::takeDamage(amount);
	//this->hit_points -= amount;
}

void			FragTrap::beRepaired(unsigned int amount)
{
	//amount = std::min(amount, this->max_hit_points - this->hit_points);
	std::cout << "Can I just say... yeehaw." << std::endl;
	std::cout << "**FR4G-TP ";
	ClapTrap::beRepaired(amount);
	//this->hit_points += amount;
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->energy_points < 25)
	{
		std::cout << "Dangit, I'm out!" << std::endl;
		std::cout << "**FR4G-TP " << this->name << " have "
		<< this->energy_points << " energy points**" << std::endl;
	}
	else
	{
		this->energy_points -= 25;
		std::cout << FragTrap::activating_vaulthunter[std::rand() % 25] << std::endl;
		std::cout << "**FR4G-TP " << this->name
		<< " activated vaulthunter.exe on the" << target << "**" << std::endl;
	}
}

FragTrap::~FragTrap(void)
{
	std::cout << "Oh my God, I'm leaking! I think I'm leaking! Ahhhh, I'm leaking!"
	<< "There's oil everywhere ! EVERYWHE..." << std::endl;
}
