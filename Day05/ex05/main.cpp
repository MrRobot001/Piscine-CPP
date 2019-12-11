/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:31:06 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:31:07 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int main(void)
{
	CentralBureaucracy c;

	for (int i = 0; i < 20; i++)
	{
		c.hire(new Bureaucrat("Bob", 1));
	}
	for (int i = 0; i < 20; i++)
	{
		c.queueUp("Peter");
	}
	c.doBureaucracy();
}
