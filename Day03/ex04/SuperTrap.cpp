/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:06:44 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 23:32:47 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

SuperTrap::SuperTrap(const std::string name) :
	ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5),
	FragTrap(name), NinjaTrap(name)
{
	std::cout << "SUP3-TP Hello, it's me!" << std::endl;
}

void SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::meleeAttack(target);
}

void SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}


SuperTrap::SuperTrap(const SuperTrap &rhs) :
	FragTrap(rhs), NinjaTrap(rhs)
{
	std::cout << "SUP3-TP Hello, it's me!" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SUP3-TP I'm dead!" << std::endl;
}
