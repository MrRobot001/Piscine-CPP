/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:31:03 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>
# include <string>

class AWeapon
{
	protected:
		int					_damage;
		int					_apcost;
		std::string			_name;
	public:
							AWeapon(void);
							AWeapon(const AWeapon &src);
							AWeapon(const std::string &name, int apcost, int damage);

		virtual				~AWeapon(void);

		AWeapon				&operator= (const AWeapon &rhs);

		virtual void		attack(void) const = 0;

		int					getAPCost(void) const;
		int					getDamage(void) const;
		const std::string	getName(void) const;
};

#endif
