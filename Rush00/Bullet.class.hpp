/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:42:28 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 18:42:29 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_H
#define BULLET_CLASS_H

#include "Thing.class.hpp"
#include <iostream>

class Bullet : virtual public Thing
{
public:
	Bullet(void);
	Bullet(const Bullet & copy);
	Bullet(std::string name);
	Bullet(int dir);
	virtual ~Bullet(void);
	Bullet & operator=(const Bullet & from);
	void			doEveryFrame(void);
	int				getDir(void) const;
	void			setDir(int dir);

	bool			active;
	int				pause;

private:
	int				_dir;
};


#endif
