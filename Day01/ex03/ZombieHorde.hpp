/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:50:03 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 16:00:38 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_H
#define ZOMBIEHORDE_H

#include "Zombie.hpp"

#define NUMB_OF_NAMES 16
#define NUMB_OF_TYPES 12

class ZombieHorde
{
	private:
		int					zomb_count;
		Zombie				*zombies;
		static std::string	names[NUMB_OF_NAMES];
		static std::string	types[NUMB_OF_TYPES];
	public:
		ZombieHorde(int N);
		~ZombieHorde(void);

		void	announce(void) const;
};

#endif
