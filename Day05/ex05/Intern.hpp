/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:31:02 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/11 20:31:03 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

# include <string>

# include "Form.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &obj);
		~Intern(void);

		Intern &operator=(Intern const &rhs);

		Form *makeForm(std::string type, std::string target);
};

struct FormType
{
	std::string type;
	Form *(*make)(std::string);
};

#endif
