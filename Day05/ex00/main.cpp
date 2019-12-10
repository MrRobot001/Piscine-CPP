/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:07:25 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/10 17:36:44 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main(void)
{

	Bureaucrat people1("person1", 69);
	std::cout << people1 << std::endl;

	std::cout << "- set grade" << std::endl;
	people1.setGrade(121);

	std::cout << "- too low grade" << std::endl;
	try
	{
		Bureaucrat people2("person2", 151);
	}
	catch (Bureaucrat::GradeTooLowException &event)
	{
		std::cout << event.what() << std::endl;
	}

	std::cout << "- too high grade" << std::endl;
	try
	{
		Bureaucrat people3("person3", 0);
	}
	catch (Bureaucrat::GradeTooHighException &event)
	{
		std::cout << event.what() << std::endl;
	}

	std::cout << "- increment" << std::endl;
	try
	{
		while (true)
		{
			people1.incrementGrade();
			std::cout << people1.getGrade() << " ";
		}
	}
	catch (std::exception &event)
	{
		std::cout << event.what() << std::endl;
	}
	std::cout << people1 << std::endl;
	std::cout << "- decrement" << std::endl;
	try
	{
		while (true)
		{
			people1.decrementGrade();
			std::cout << people1.getGrade() << " ";
		}
	}
	catch (std::exception &event)
	{
		std::cout << event.what() << std::endl;
	}
	std::cout << people1 << std::endl;
	return (0);
}
