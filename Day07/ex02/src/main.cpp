/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:15:35 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/13 18:36:58 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int		main(void)
{
	Array<int>a(20);

	std::cout << "A -> ";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	std::cout << "A -> ";
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = static_cast<int>(i);
		std::cout << a[i] << " ";
	}

	std::cout << std::endl;

	Array<int> b(a);

	std::cout << "B -> ";
	for (size_t i = 0; i < b.size(); i++)
	{
		b[i] = static_cast<int>(i + 1);
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "A -> ";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	Array<int> c;

	c = b;
	std::cout << "C -> ";
	for (size_t i = 0; i < c.size(); i++)
	{
		c[i]++;
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "B -> ";
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;
	return 0;
}
