/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:30:19 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 15:47:04 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int		main(void)
{
	ZombieEvent newEvent;

	newEvent.setZombieType("Bruiser");
	Zombie	*walking_dead_1 = newEvent.newZombie("Hershel");
	Zombie	*walking_dead_2 = newEvent.newZombie("The Governor");
	Zombie	*walking_dead_3 = newEvent.newZombie("Beth");
	newEvent.setZombieType("Biter");
	for (int i = 0; i < 8; i++)
		newEvent.randomChump();
	newEvent.setZombieType("Viral");
	for (int i = 0; i < 8; i++)
		newEvent.randomChump();

	delete walking_dead_1;
	delete walking_dead_2;
	delete walking_dead_3;
}
