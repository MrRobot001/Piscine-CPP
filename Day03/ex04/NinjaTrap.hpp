/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 22:26:42 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 23:32:35 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : ClapTrap
{
	public:
		NinjaTrap(std::string _name);
		NinjaTrap(const NinjaTrap &_NinjaTrap);

		NinjaTrap			&operator= (const NinjaTrap &_Claptrap);

		virtual void		rangedAttack(std::string const &target);
		virtual void		meleeAttack(std::string const &target);
		virtual void		takeDamage(unsigned int amount);
		virtual void		beRepaired(unsigned int amount);

		void				ninjaShoebox(NinjaTrap &target);
		void				ninjaShoebox(ClapTrap &target);
		void				ninjaShoebox(FragTrap &target);
		void				ninjaShoebox(ScavTrap &target);

		~NinjaTrap(void);
};

#endif
