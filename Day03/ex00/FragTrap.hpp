/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:44:23 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 17:56:17 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>

class FragTrap
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

	static std::string	activating_vaulthunter[25];

public:
						FragTrap(std::string	_name);
						FragTrap(const FragTrap &Claptrap);

	FragTrap			&operator= (const FragTrap &Claptrap);

	void				rangedAttack(std::string const &target);
	void				meleeAttack(std::string const &target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	void				vaulthunter_dot_exe(std::string const & target);

	~					FragTrap(void);
};

#endif
