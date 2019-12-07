/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:34:04 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Squad.hpp"
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int	main(void)
{
	ISquad* squad = new Squad;
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	squad->push(bob);
	squad->push(jim);

	for (int i = 0; i < squad->getCount(); ++i)
	{
		ISpaceMarine* mar = squad->getUnit(i);
		mar->battleCry();
		mar->rangedAttack();
		mar->meleeAttack();
	}

	squad->getUnit(0)->battleCry();
	squad->getUnit(1)->battleCry();
	squad->getUnit(0)->rangedAttack();
	squad->getUnit(1)->rangedAttack();
	squad->getUnit(0)->meleeAttack();
	squad->getUnit(1)->meleeAttack();

	delete squad;

	return (0);
}
