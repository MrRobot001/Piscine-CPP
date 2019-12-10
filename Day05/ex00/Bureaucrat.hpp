/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:07:27 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/10 17:37:35 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private:
        const   std::string name;
        int     grade;
    public:
        class GradeTooHighException : public std::exception
        {
        private:
            int     grade;
        public:
            GradeTooHighException(int _grade);
            GradeTooHighException(const GradeTooHighException &obj);
            ~GradeTooHighException(void) throw();

            GradeTooHighException &operator=(const GradeTooHighException &gthe);

            const char          *what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
        private:
            int     grade;
        public:
            GradeTooLowException(int _grade);
            GradeTooLowException(const GradeTooLowException &obj);
            ~GradeTooLowException(void) throw();

            GradeTooLowException &operator=(const GradeTooLowException &gtle);

            const char          *what(void) const throw();
        };

        Bureaucrat(const std::string _name, int _grade);
        Bureaucrat(const Bureaucrat &bureaucrat);

        Bureaucrat &operator=(const Bureaucrat &bureaucrat);

        const std::string   getName(void) const;
        int                 getGrade(void) const;

        void                setGrade(int _grade);

        void                incrementGrade(void);
        void                decrementGrade(void);

        ~Bureaucrat(void);
};

std::ostream &operator<< (std::ostream &os, Bureaucrat const &bureaucrat);

#endif
