/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:29:57 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:34:53 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main(void)
{
	Intern idiotOne;
	Bureaucrat high = Bureaucrat("Hermes Conrad", 1);
	Bureaucrat low = Bureaucrat("Bobby Bobson", 150);

	OfficeBlock ob;

	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	ob.setIntern(&idiotOne);
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	ob.setSigner(&low);
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	ob.setExecutor(&low);
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	ob.setSigner(&high);
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try {
		ob.doBureaucracy("lolol", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	try {
		ob.setExecutor(NULL);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	try {
		ob.setSigner(NULL);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	try {
		ob.setIntern(NULL);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	ob.setExecutor(&high);
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

}
