/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:49:31 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/10 18:44:57 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string _name, int _sign, int _exec) :
			name(_name), gradeSign(_sign), gradeExec(_exec),sign_it(false)
{
	if (_sign < 1)
		throw GradeTooHighException(_sign);
	if (_sign > 150)
		throw GradeTooLowException(_sign);

	if (_exec < 1)
		throw GradeTooHighException(_exec);
	if (_exec > 150)
		throw GradeTooLowException(_exec);
}

Form::Form(Form const &obj) : name(obj.name), gradeSign(obj.gradeSign), gradeExec(obj.gradeExec), sign_it(obj.sign_it) {}

Form::~Form(void) {}

Form	&Form::operator=(Form const &)
{
	return *this;
}

std::ostream	&operator<<(std::ostream &os, const Form form)
{
	os << "Form: " << form.getName() << std::endl
		<< "\tsign: " << form.getGrateSign() << std::endl
		<< "\texec: " << form.getGrateExec();
	return os;
}

const std::string	Form::getName(void) const
{
	return this->name;
}

int					Form::getGrateSign(void) const
{
	return this->gradeSign;
}

int					Form::getGrateExec(void) const
{
	return this->gradeExec;
}

bool				Form::isSigned(void) const
{
	return this->sign_it;
}

void				Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeSign)
		throw GradeTooLowException(bureaucrat.getGrade());
	this->sign_it = true;
}

typedef		Form::GradeTooHighException GradeTooHighException;

GradeTooHighException::GradeTooHighException(const int _grade) : grade(_grade) {}
GradeTooHighException::GradeTooHighException(const GradeTooHighException &obj) : grade(obj.grade) {}

GradeTooHighException::~GradeTooHighException() throw(){}

GradeTooHighException		&GradeTooHighException::operator=(GradeTooHighException const &gthe)
{
	this->grade = gthe.grade;
	return *this;
}

int							GradeTooHighException::getGrade(void) const
{
	return this->grade;
}

const char 					*GradeTooHighException::what(void) const throw()
{
	return "Grade is too hight";
}

typedef		Form::GradeTooLowException GradeTooLowException;

GradeTooLowException::GradeTooLowException(const int _grade) : grade(_grade) {}
GradeTooLowException::GradeTooLowException(const GradeTooLowException &obj) : grade(obj.grade) {}

GradeTooLowException::~GradeTooLowException() throw(){}

GradeTooLowException		&GradeTooLowException::operator=(GradeTooLowException const &gtle)
{
	this->grade = gtle.grade;
	return *this;
}

int							GradeTooLowException::getGrade(void) const
{
	return this->grade;
}

const char 					*GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}
