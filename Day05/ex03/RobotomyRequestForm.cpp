/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:29:13 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:29:14 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	Form("robotomy request", 72, 45, target)
{}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &)
{}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
		RobotomyRequestForm const &
	)
{ return *this; }

void RobotomyRequestForm::_execute(Bureaucrat const &) const
{
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized";
	else
		std::cout << this->getTarget() << " could not be robotomized";
}
