/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:38:28 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/03 22:37:23 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string _name, std::string _color, int _len_of_horn, bool _shine) :
			name(_name), color(_color), len_of_horn(_len_of_horn), shine(_shine)
{
	std::cout << "You make your way through the thick of the forest and see your pony." << std::endl;
	std::cout << ">" << color << " " << name  << std::endl;;
}

Pony::~Pony(void)
{
	std::cout << color << " " << name << " attacked you with " << len_of_horn << \
	" centimeters horn... And You woke up in a cold sweat." << std::endl << std::endl;
}

bool			Pony::Shine_o_Notshine(void) const
{
	return this->shine;
}
