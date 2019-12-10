/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:49:33 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/10 18:44:36 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_H
#define FORM_CLASS_H

#include <stdexcept>
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			gradeSign;
		const int			gradeExec;
		bool				sign_it;
	public:

		class GradeTooHighException : public std::exception
		{
			private:
				int grade;
			public:
				GradeTooHighException(int _grade);
				GradeTooHighException(const GradeTooHighException &obj);
				~GradeTooHighException(void) throw();

				GradeTooHighException &operator=(const GradeTooHighException &gthe);

				const char *what(void) const throw();

				int getGrade(void) const;
		};

		class GradeTooLowException : public std::exception
		{
			private:
				int grade;
			public:
				GradeTooLowException(int _grade);
				GradeTooLowException(const GradeTooLowException &obj);
				~GradeTooLowException(void) throw();

				GradeTooLowException &operator=(const GradeTooLowException &gtle);

				const char *what(void) const throw();

				int getGrade(void) const;
		};

		Form(const std::string _name, const int _sign, int _exet);
		Form(Form const &obj);
		~Form(void);

		Form	&operator=(const Form &form);

		const std::string	getName(void) const;
		int					getGrateSign(void) const;
		int					getGrateExec(void) const;
		bool				isSigned(void) const;
		void				beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form form);

#endif
