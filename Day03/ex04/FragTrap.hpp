/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:44:23 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 19:26:34 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	static std::string	activating_vaulthunter[25];

public:
						FragTrap(std::string	_name);
						FragTrap(const FragTrap &_Claptrap);

	FragTrap			&operator= (const FragTrap &_Claptrap);

	virtual void		rangedAttack(std::string const &target);
	virtual void		meleeAttack(std::string const &target);
	virtual void		takeDamage(unsigned int amount);
	virtual void		beRepaired(unsigned int amount);
	void				vaulthunter_dot_exe(std::string const & target);

	virtual				~FragTrap(void);
};

#endif
