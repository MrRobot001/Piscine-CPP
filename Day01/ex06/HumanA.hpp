/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:21:41 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 19:15:40 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
#define HUMANA_CLASS_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon			&weapon;
		std::string		name;
	public:
		HumanA(std::string _name, Weapon &_weapon);
		~HumanA(void);

		void			attack(void) const;
};


#endif
