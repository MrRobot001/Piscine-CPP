/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:07:25 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/10 18:50:12 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	std::cout << "Bureaucrat" << std::endl;
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


	std::cout << std::endl << "Form" << std::endl;
	Form f("person1", 42, 42);
	std::cout << f << std::endl;

	std::cout << " - low grade" << std::endl;
	try {
		Form fLow("person2", 420, 42);
	}
	catch (Form::GradeTooLowException &event)
	{
		std::cout << event.what() << std::endl;
	}
	try {
		Form fLow("person2", 42, 420);
	}
	catch (Form::GradeTooLowException &event)
	{
		std::cout << event.what() << std::endl;
	}

	std::cout << " - too high" << std::endl;
	try {
		Form fHigh("person3", 0, 42);
	}
	catch (Form::GradeTooHighException &event)
	{
		std::cout << event.what() << std::endl;
	}
	try {
		Form fHigh("person3", 42, 0);
	}
	catch (Form::GradeTooHighException &event)
	{
		std::cout << event.what()  << std::endl;
	}

	std::cout << std::endl << "Sign" << std::endl;
	{
		Bureaucrat signer("Signer", 20);
		Form form("Form", 10, 10);

		std::cout << signer << std::endl;
		std::cout << form << std::endl;

		try {
			form.beSigned(signer);
		}
		catch (std::exception &event)
		{
			std::cout << event.what() << std::endl;
		}

		signer.setGrade(10);
		std::cout << signer << std::endl;

		form.beSigned(signer);
		std::cout << form << std::endl;
	}

	{
		Bureaucrat signer("Signer", 40);
		Form form("Form", 20, 20);

		signer.signForm(form);
		signer.setGrade(20);

		signer.signForm(form);
		signer.signForm(form);
	}


	return (0);
}
