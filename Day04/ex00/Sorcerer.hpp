/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:28:41 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
	private:
		std::string		_name;
		std::string		_title;
	public:
						Sorcerer(void);
						Sorcerer(const Sorcerer &src);
						Sorcerer(std::string name, std::string title);
						~Sorcerer(void);
		Sorcerer		&operator= (const Sorcerer &rhs);
		void			setName(std::string name);
		void			setTitle(std::string title);
		void			polymorph(Victim const &victim) const;
		std::string		getName(void) const;
		std::string		getTitle(void) const;
};

std::ostream		 	&operator<< (std::ostream &out, const Sorcerer &rhs);

#endif
