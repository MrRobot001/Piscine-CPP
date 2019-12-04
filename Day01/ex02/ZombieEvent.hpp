/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:30:21 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 15:39:45 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string		type;
	static			std::string names[16];
public:
	ZombieEvent(void);
	~ZombieEvent(void);

	void			setZombieType(std::string _type);
	Zombie*			newZombie(std::string name) const;
	void			randomChump(void) const;
};


#endif
