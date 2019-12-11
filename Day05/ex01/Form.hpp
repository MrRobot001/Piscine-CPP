/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:27:29 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:36:15 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FORM_CLASS_H
# define FORM_CLASS_H

# include <stdexcept>
# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	public:
		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(int grade);
				GradeTooHighException(GradeTooHighException const &obj);
				~GradeTooHighException(void) throw();

				GradeTooHighException &operator=(GradeTooHighException const &rhs);

				const char *what(void) const throw();

				int getGrade(void) const;
			private:
				int _grade;
		};

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException(int grade);
				GradeTooLowException(GradeTooLowException const &obj);
				~GradeTooLowException(void) throw();

				GradeTooLowException &operator=(GradeTooLowException const &rhs);

				const char *what(void) const throw();

				int getGrade(void) const;
			private:
				int _grade;
		};

		Form(const std::string name, const int sign, int exec);
		Form(Form const &obj);
		~Form(void);

		Form &operator=(Form const &rhs);

		const std::string getName(void) const;
		int getGradeSign(void) const;
		int getGradeExec(void) const;
		bool isSigned(void) const;

		void beSigned(Bureaucrat &b);
	private:
		const std::string _name;
		const int _gradeSign;
		const int _gradeExec;
		bool _signed;
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
