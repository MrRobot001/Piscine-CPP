/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:30:09 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:30:10 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	Form("presidential pardon", 25, 5, target)
{}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &)
{}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
		PresidentialPardonForm const &
	)
{ return *this; }

void PresidentialPardonForm::_execute(Bureaucrat const &) const
{
	std::cout << this->getTarget() << " has been pardonned by Zaphod Beeblebrox";
}
