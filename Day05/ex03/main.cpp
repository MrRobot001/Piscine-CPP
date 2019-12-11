/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:29:01 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:37:38 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
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
	}

	Bureaucrat high("high", 1);
	Bureaucrat low("low", 150);

	std::cout << "__________ SHRUBBERY __________" << std::endl;
	{
		ShrubberyCreationForm f("lolol");

		low.executeForm(f);

		low.signForm(f);
		high.signForm(f);

		low.executeForm(f);
		high.executeForm(f);
	}

	std::cout << "__________ ROBOTOMY __________" << std::endl;
	{
		RobotomyRequestForm f("lolol");

		low.executeForm(f);

		low.signForm(f);
		high.signForm(f);

		low.executeForm(f);
		high.executeForm(f);
	}

	std::cout << "__________ PARDON __________" << std::endl;
	{
		PresidentialPardonForm f("lolol");

		low.executeForm(f);

		low.signForm(f);
		high.signForm(f);

		low.executeForm(f);
		high.executeForm(f);
	}

	std::cout << "__________ INTERN __________" << std::endl;
	{
		Intern i;

		delete i.makeForm("shrubbery creation", "bob");
		delete i.makeForm("robotomy request", "bob");
		delete i.makeForm("presidential pardon", "bob");

		i.makeForm("unicorn riding", "bob");
	}
}
