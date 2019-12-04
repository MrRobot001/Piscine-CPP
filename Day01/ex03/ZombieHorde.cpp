/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:50:04 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 16:19:00 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : zomb_count(N)
{
	this->zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(ZombieHorde::names[std::rand() % NUMB_OF_NAMES]);
		zombies[i].setType(ZombieHorde::types[std::rand() % NUMB_OF_TYPES]);
	}
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->zombies;
}

std::string		ZombieHorde::names[NUMB_OF_NAMES] =
{
	"Luiza", "Dag", "Sammer", "Hanna", "Wayn", "Erin", "Nick", "Tony", "Carla",\
	"Delli", "Jo", "Bill", "Winston", "Richy", "Callway", "Eddy"
};

std::string		ZombieHorde::types[NUMB_OF_TYPES] =
{
	"Biter", "Bruiser", "Viral", "Goon", "Toad", "Demolisher", "Boomber", \
	"Screamer", "Volatile", "Bolter", "Night Walker", "Night Humter"
};

void	ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->zomb_count; i++)
		zombies[i].announce();

}
