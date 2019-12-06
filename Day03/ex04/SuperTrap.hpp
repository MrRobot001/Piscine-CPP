/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:06:41 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/06 23:28:11 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public virtual FragTrap, public virtual NinjaTrap
{
	public:
		SuperTrap(const std::string name);
		SuperTrap(const SuperTrap &obj);
		~SuperTrap(void);

		SuperTrap &	operator=(const SuperTrap &rhs);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
};

#endif
