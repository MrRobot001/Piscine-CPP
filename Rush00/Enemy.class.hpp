/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:11:04 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 18:11:05 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H

#include "Character.class.hpp"
#include "Thing.class.hpp"
#include "retro.hpp"
#include <iostream>

class Enemy : virtual public Character
{
public:
	Enemy(void);
	Enemy(const Enemy & copy);
	Enemy(std::string name);
	~Enemy(void);
	Enemy & operator=(const Enemy & from);

	void			doEveryFrame(void);
private:
	
};


#endif
