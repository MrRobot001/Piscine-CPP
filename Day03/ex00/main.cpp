/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:44:22 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 17:05:55 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
}
