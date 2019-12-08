/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:51:22 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 14:51:24 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H

#include "Thing.class.hpp"
#include "Bullet.class.hpp"
#include <iostream>

class Character : virtual public Thing
{
public:
	Character(void);
	Character(const Character & copy);
	Character(std::string name);
	virtual ~Character(void);
	Character & operator=(const Character & from);

	void		shoot(void);
	int			getLives(void) const;
	int			getMaxLives(void) const;
	int			getShootDir(void) const;
	void		takeHit(void);
	bool		collisionCheck(void) const;
	void		respawn(void);
	void		draw(void) const;
	void		nextBullet(void);

	void		setShootCount(int n);
	int			getShootCount(void) const;

	Bullet		bullet[20];
	int			nextBulletIndex;


protected:
	int			_lives;
	int			_maxLives;
	int			_shootDir;
	int			_shootCount;
	static const int	n_bullets;
};


#endif
