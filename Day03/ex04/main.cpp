/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:44:22 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 23:32:01 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"


int		main(void)
{
	FragTrap	claptrap1("Gary");
	FragTrap	claptrap2("Lary");


	for(int i = 0; i < 5; i++)
		claptrap1.takeDamage(16);
	FragTrap	claptrap1_cp(claptrap1);
	claptrap1_cp.beRepaired(100);
	for(int i = 0; i < 3; i++)
		claptrap2.meleeAttack("Bandits");
	claptrap2.rangedAttack("Constructors");
	for (int i = 0; i < 5; i++)
		claptrap1_cp.vaulthunter_dot_exe("Goliaths");

	ScavTrap	claptrap3("Bary");
	ScavTrap	claptrap4("Mary");


	for(int i = 0; i < 5; i++)
		claptrap3.takeDamage(16);
	ScavTrap	claptrap3_cp(claptrap3);
	claptrap3_cp.beRepaired(100);
	for(int i = 0; i < 3; i++)
		claptrap4.meleeAttack("Bandits");
	claptrap4.rangedAttack("Constructors");
	for (int i = 0; i < 5; i++)
		claptrap3_cp.challengeNewcomer("Robert");

	NinjaTrap ninja("NINJA");

	for (int i = 0; i < 7; i++)
		ninja.takeDamage(20);

	for (int i = 0; i < 7; i++)
		ninja.beRepaired(20);

	ninja.ninjaShoebox(ninja);
	ninja.ninjaShoebox(claptrap1);
	ninja.ninjaShoebox(claptrap3);
}
