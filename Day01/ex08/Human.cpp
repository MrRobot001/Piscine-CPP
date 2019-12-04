/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:34:16 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 21:15:46 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#define		COUNT_FIELD 3

void	Human::meleeAttack(std::string const &targen)
{
	std::cout << "Melee_Attack - " << targen << std::endl;
}

void	Human::rangedAttack(std::string const &targen)
{
	std::cout << "Range_Attack - " << targen << std::endl;
}

void	Human::intimidatingShout(std::string const &target)
{
	std::cout << "Intimidating_Shout - " << target << std::endl;
}

typedef void(Human:: *actionPtr) (std::string const &);

void	Human::action(std::string const &action, std::string const &target)
{
	std::string	field[COUNT_FIELD] = {"mellee", "ranged", "shout"};

	actionPtr actions[COUNT_FIELD] = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	for (int i = 0; i < COUNT_FIELD; i++)
	{
		if (field[i].compare(action) == 0)
			(this->*actions[i])(target);
	}
}
