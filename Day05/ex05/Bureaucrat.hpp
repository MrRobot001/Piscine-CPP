/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:30:40 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:30:40 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include <stdexcept>
# include <string>
# include <iostream>

# include "Form.hpp"

class Bureaucrat
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

		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &obj);
		~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &rhs);

		const std::string getName(void) const;
		int getGrade(void) const;

		void setGrade(int grade);

		void signForm(Form &f);
		void executeForm(Form const &f);

		void incrementGrade(void);
		void decrementGrade(void);
	private:
		const std::string _name;
		int	_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
