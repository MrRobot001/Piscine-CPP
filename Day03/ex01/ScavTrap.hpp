/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:36:43 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 18:28:25 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>

class ScavTrap
{
	private:
		unsigned int		hit_points;
		unsigned int		max_hit_points;
		unsigned int		energy_points;
		unsigned int		max_energy_points;
		unsigned int		level;
		std::string			name;
		unsigned int		melee_attack_damage;
		unsigned int		ranged_attack_damage;
		unsigned int		armor_damage_reduction;
		static std::string	challenges[5];

	public:
						ScavTrap(std::string	_name);
						ScavTrap(const ScavTrap &Bot);

	ScavTrap			&operator= (const ScavTrap &Claptrap);

	void				rangedAttack(std::string const &target);
	void				meleeAttack(std::string const &target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	void				challengeNewcomer(std::string const & target);

						~ScavTrap(void);
};

#endif
