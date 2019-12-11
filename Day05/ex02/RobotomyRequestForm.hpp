/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:28:14 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:33:19 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ROBOTOMYREQUESTFORM_CLASS_H
# define ROBOTOMYREQUESTFORM_CLASS_H

# include <string>

# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &obj);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		void _execute(Bureaucrat const & executor) const;
	private:
};

#endif
