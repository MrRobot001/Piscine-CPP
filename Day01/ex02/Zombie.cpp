/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:30:20 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 15:48:14 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name, std::string _type) : name(_name), type(_type)
{
	this->announce();
}

Zombie::~Zombie(void) {}

void		Zombie::announce(void)
{
	std::cout << "<" << name << " (" << type << ")> Braiiiiiiinnnssss..." << std::endl;
}
