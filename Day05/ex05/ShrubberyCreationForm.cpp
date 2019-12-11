/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:31:33 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:31:34 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	Form("shrubbery creation", 145, 137, target)
{}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &)
{}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
		ShrubberyCreationForm const &
	)
{ return *this; }

const std::string tree = "\
              v .   ._, |_  .,\n\
           `-._\\/  .  \\ /    |/_\n\
               \\\\  _\\, y | \\//\n\
         _\\_.___\\\\, \\\\/ -.\\||\n\
           `7-,--.`._||  / / ,\n\
           /'     `-. `./ / |/_.'\n\
                     |    |//\n\
                     |_    /\n\
                     |-   |\n\
                     |   =|\n\
                     |    |\n\
--------------------/ ,  . \\--------._\n\
";

void ShrubberyCreationForm::_execute(Bureaucrat const &) const
{
	std::ofstream of(this->getTarget() + "_shrubbery");
	of << tree << std::endl;
	of.close();
}
