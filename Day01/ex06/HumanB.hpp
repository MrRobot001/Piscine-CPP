/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:21:44 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 19:15:25 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
#define HUMANB_CLASS_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon			*weapon;
		std::string		name;
	public:
		HumanB(std::string _name);
		~HumanB(void);

		void			attack(void) const;
		void			setWeapon(Weapon &_weapon);
};


#endif
