/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:38:27 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/03 22:36:02 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	std::cout << "Pony in the Heap" << std::endl;

	Pony	*mlp = new Pony("Michail", "Blue", 20, true);

	if (mlp->Shine_o_Notshine())
		std::cout << "Ooo... Pony is shining" << std::endl;
	delete mlp;
}

void	ponyOnTheStack(void)
{
	std::cout << "Pony in the Stack" << std::endl;

	Pony	mlp = Pony("Artur", "Pink", 20, true);

	if (mlp.Shine_o_Notshine())
		std::cout << "Ooo... Pony is shining" << std::endl;
}

int		main(void)
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return (0);
}
