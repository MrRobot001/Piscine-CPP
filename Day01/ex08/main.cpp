/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:34:14 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 21:14:53 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main(void)
{
	Human human;

	std::string target = "Jonny: the fastest hand in the wild west.";

	human.action("mellee", target);
	human.action("ranged", target);
	human.action("shout", target);
	human.action("HP", target);
}
