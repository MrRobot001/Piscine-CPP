/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 20:46:54 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 22:16:41 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		unsigned int		hit_points;
		unsigned int		max_hit_points;
		unsigned int		energy_points;
		unsigned int		max_energy_points;
		unsigned int		level;
		std::string			name;
		unsigned int		melee_attack_damage;
		unsigned int		ranged_attack_damage;
		unsigned int		armor_damage_reduction;
	public:
		ClapTrap(unsigned int _hit_points, unsigned int _max_hit_points,
				unsigned int _energy_points, unsigned int _max_energy_points,
				unsigned int _level, std::string _name,
				unsigned int _melee_attack_damage, unsigned int _ranged_attack_damage,
				unsigned int _armor_damage_reduction);
							ClapTrap(const ClapTrap &Claptrap);

		virtual void		rangedAttack(std::string const &target);
		virtual void		meleeAttack(std::string const &target);
		virtual void		takeDamage(unsigned int amount);
		virtual void		beRepaired(unsigned int amount);
		virtual				~ClapTrap(void);
};

#endif
