/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:24:09 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/14 20:34:00 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <iostream>
#include "easyfind.hpp"
int		main(void)
{
	std::set<int> s;

	for(int i = 1; i <= 10; i++)
		s.insert(i);

	for (int i = -10; i <= 20; i++)
	{
		try
		{
			std::cout << easyfind(s, i) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "not found: "  << i << std::endl;
		}
	}
	return (0);
}
