/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:35:00 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 17:35:01 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "Character.class.hpp"
#include "Thing.class.hpp"

#include <iostream>

class Player : virtual public Character
{
public:
	Player(void);
	Player(const Player & copy);
	Player(std::string name);
	~Player(void);
	Player & operator=(const Player & from);

	void			doEveryFrame(void);
	void			addScore(unsigned int amount);
	int				getScore(void) const;
	void			draw(int i) const;
private:
	int				_score;
};


#endif
