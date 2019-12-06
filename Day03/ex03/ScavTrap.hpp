/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:36:43 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 22:26:36 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		static std::string	challenges[5];

	public:
						ScavTrap(std::string	_name);
						ScavTrap(const ScavTrap &Claptrap);

	ScavTrap			&operator= (const ScavTrap &Claptrap);

	virtual void		rangedAttack(std::string const &target);
	virtual void		meleeAttack(std::string const &target);
	virtual void		takeDamage(unsigned int amount);
	virtual void		beRepaired(unsigned int amount);
	void				challengeNewcomer(std::string const & target);

	virtual				~ScavTrap(void);
};

#endif
