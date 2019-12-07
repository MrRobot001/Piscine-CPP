/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:28:53 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <string>
# include <iostream>

class Victim
{
	private:
		std::string		_name;
	public:
						Victim(void);
						Victim(const Victim &src);
						Victim(std::string name);
						~Victim(void);
		Victim			&operator= (const Victim &rhs);
		void			setName(std::string name);
		std::string		getName(void) const;
		void			getPolymorphed(void) const;
};

std::ostream		  &operator<< (std::ostream &out, const Victim &rhs);

#endif
