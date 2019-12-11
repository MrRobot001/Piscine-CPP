/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:27:34 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:37:38 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "__________ BUREAUCRAT __________" << std::endl;
	std::cout << " * Creation" << std::endl;
	Bureaucrat b("Bob", 42);
	std::cout << b << std::endl;

	std::cout << " * Set grade" << std::endl;
	b.setGrade(100);
	std::cout << b << std::endl;

	std::cout << " * Too low grade" << std::endl;
	try {
		Bureaucrat bLow("Alice", 420);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << ": " << e.getGrade() << std::endl;
	}

	std::cout << " * Too high" << std::endl;
	try { Bureaucrat bHigh("Peter", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << ": " << e.getGrade() << std::endl;
	}

	std::cout << " * Increment" << std::endl;
	try {
		while (true)
		{
			b.incrementGrade();
			std::cout << b.getGrade() << ", ";
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b << std::endl;

	std::cout << " * Decrement" << std::endl;
	try {
		while (true)
		{
			b.decrementGrade();
			std::cout << b.getGrade() << ", ";
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b << std::endl;

	std::cout << "__________ FORM __________" << std::endl;

	std::cout << " * Creation" << std::endl;
	Form f("Bob", 42, 42);
	std::cout << f << std::endl;

	std::cout << " * Too low grade" << std::endl;
	try {
		Form fLow("Alice", 420, 42);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << ": " << e.getGrade() << std::endl;
	}
	try {
		Form fLow("Alice", 42, 420);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << ": " << e.getGrade() << std::endl;
	}

	std::cout << " * Too high" << std::endl;
	try {
		Form fHigh("Peter", 0, 42);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << ": " << e.getGrade() << std::endl;
	}
	try {
		Form fHigh("Peter", 42, 0);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << ": " << e.getGrade() << std::endl;
	}

	std::cout << "__________ SIGN __________" << std::endl;
	{
		Bureaucrat signer("Signer", 20);
		Form form("Form", 10, 10);

		std::cout << signer << std::endl;
		std::cout << form << std::endl;

		try {
			form.beSigned(signer);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
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
}
