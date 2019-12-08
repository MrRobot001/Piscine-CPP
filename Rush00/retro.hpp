/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retro.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 15:59:53 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/08 15:59:54 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RETRO_H
#define RETRO_H

#include "Bullet.class.hpp"
#include "Thing.class.hpp"
#include "Character.class.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"
#include "Level.class.hpp"
#include <ncurses.h>
#include <iostream>
#include <unistd.h>

#define PLAYER_PAIR 1
#define PLAYER_HURT_PAIR 2
#define ENEMY_PAIR 3
#define ENEMY_HURT_PAIR 4
#define VICTORY_PAIR 5
#define LOSS_PAIR 6
#define WALL_PAIR 7
#define WALL1_PAIR 8
#define BULLET_PAIR 9
#define BACK_PAIR 10
#define FIRE_PAIR 11
#define MENU0_PAIR 12
#define MENU1_PAIR 13
#define BULLET1_PAIR 13

void			writeWin(int x, int y, std::string s);
void			writeWin(int x, int y, std::string s, short colorpair);
void			writeWin(int x, int y, char c);
void			writeWin(int x, int y, char c, short colorpair);

#endif
