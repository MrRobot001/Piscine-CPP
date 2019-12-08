/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 15:55:02 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/08 15:55:04 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_CLASS_H
#define LEVEL_CLASS_H

#include <ncurses.h>
#include <iostream>
#include "Player.class.hpp"

class Level
{

public:
	Level();
	Level(const Level & copy);
	~Level();
	Level & operator=(const Level & from);
	void			draw();
	void			displayPlayerInfo(Player &player);
	void			displayLoss(void);
	void			displayVictory(void);
	int				row;
	int				col;
	int				wrow;
	char			wall;

	clock_t			start_t;

	static int frames;
	static int current;


};

#endif




