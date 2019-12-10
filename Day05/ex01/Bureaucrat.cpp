/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:07:26 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/10 18:47:20 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name)
{
    this->setGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    this->grade = bureaucrat.getGrade();
    return *this;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (os);
}

const std::string   Bureaucrat::getName(void) const
{
    return this->name;
}

int                 Bureaucrat::getGrade(void) const
{
    return this->grade;
}

void               Bureaucrat::setGrade(int _grade)
{
    if (_grade < 1)
        throw GradeTooHighException(grade);
    if (_grade > 150)
        throw GradeTooLowException(grade);

    this->grade = _grade;
}

void			Bureaucrat::incrementGrade(void)
{
    this->setGrade(this->grade - 1);
}

void                Bureaucrat::decrementGrade(void)
{
    this->setGrade(this->grade + 1);
}

void        Bureaucrat::signForm(Form &f)
{
    if (f.isSigned())
    {
        std::cout << this->name << " connot sign " << f.getName() << " because it is already signed." << std::endl;
        return;
    }
    try
    {
        f.beSigned(*this);
        std::cout << this->name << " signs " << f.getName() << std::endl;
    }
    catch(Form::GradeTooLowException &)
    {
        std::cout << this->name << " connot sign " << f.getName() << " because the grade was too low." << std::endl;
    }

}

typedef     Bureaucrat::GradeTooHighException GradeTooHighException;

GradeTooHighException::GradeTooHighException(const int _grade) : grade(_grade) {}

GradeTooHighException::GradeTooHighException(const GradeTooHighException &obj) : grade(obj.grade) {}

GradeTooHighException::~GradeTooHighException(void) throw() {}

GradeTooHighException   &GradeTooHighException::operator=(const GradeTooHighException &gthe)
{
    this->grade = gthe.grade;
    return *this;
}

const char          *GradeTooHighException::what(void) const throw()
{
    return "Grade is too hight";
}


typedef     Bureaucrat::GradeTooLowException GradeTooLowException;

GradeTooLowException::GradeTooLowException(const int _grade) : grade(_grade) {}

GradeTooLowException::GradeTooLowException(const GradeTooLowException &obj) : grade(obj.grade) {}

GradeTooLowException::~GradeTooLowException(void) throw() {}

GradeTooLowException   &GradeTooLowException::operator=(const GradeTooLowException &gtle)
{
    this->grade = gtle.grade;
    return *this;
}

const char          *GradeTooLowException::what(void) const throw()
{
    return "Grade is too low";
}
