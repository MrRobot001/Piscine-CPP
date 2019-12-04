/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:50:05 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 16:17:47 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int		main(void)
{
	ZombieHorde myArmy = ZombieHorde(69);
	myArmy.announce();

	return (0);
}
