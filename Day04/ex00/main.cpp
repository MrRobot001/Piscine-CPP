/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:27:18 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:16:11 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Peon.hpp"
#include "Victim.hpp"
#include "Sorcerer.hpp"

int	main(void)
{
	Sorcerer	robert("Robert", "the Magnificent");
	Victim		jim("Jimmy");
	Peon		joe("Joe");

	std::cout << std::endl;

	std::cout << robert << std::endl << jim << std::endl << joe << std::endl;

	robert.polymorph(jim);
	std::cout << std::endl;
	robert.polymorph(joe);
	std::cout << std::endl;

	return (0);
}
