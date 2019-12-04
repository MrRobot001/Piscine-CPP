/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:30:22 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 15:59:58 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {}
ZombieEvent::~ZombieEvent(void) {}

std::string	ZombieEvent::names[16] =
{
	"Luiza", "Dag", "Sammer", "Hanna", "Wayn", "Erin", "Nick", "Tony", "Carla",\
	"Delli", "Jo", "Bill", "Winston", "Richy", "Callway", "Eddy"
};

void		ZombieEvent::setZombieType(std::string _type)
{
	this->type = _type;
}

Zombie		*ZombieEvent::newZombie(std::string name) const
{
	return new Zombie(name, this->type);
}

void		ZombieEvent::randomChump(void) const
{
	Zombie zombie = Zombie(names[std::rand() % 16], type);
}
