/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:31:38 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{
	protected:
		int					_hp;
		std::string			_type;
	public:
		Enemy(void);
		Enemy(const Enemy &src);
		Enemy(int hp, const std::string &type);

		virtual				~Enemy(void);

		Enemy				&operator= (const Enemy &rhs);

		int					getHP(void) const;
		const std::string	getType(void) const;

		virtual void		takeDamage(int damage);
};

#endif
