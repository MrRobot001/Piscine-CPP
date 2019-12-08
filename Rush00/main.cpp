/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:24:13 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/08 23:00:04 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "retro.hpp"
#include "Menu.hpp"
#include "Bullet.class.hpp"
#include "Thing.class.hpp"
#include "Character.class.hpp"
#include "Player.class.hpp"
#include "Enemy.class.hpp"
#include "Level.class.hpp"
#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <ctime>

#define DELAY 30000

void			writeWin(int x, int y, std::string s)
{
	std::string t(s);
	mvprintw(y, x, t.c_str());
}

void			writeWin(int x, int y, std::string s, short colorpair)
{

	// if (colorpair == BACK_PAIR)
	// 	attron(A_DIM);
	// else
		attron(COLOR_PAIR(colorpair));
	writeWin(x, y, s);
	
	// if (colorpair == BACK_PAIR)
	// 	attroff(A_DIM);
	// else
		attroff(COLOR_PAIR(colorpair));
}

void			writeWin(int x, int y, char c)
{
	mvaddch(y, x, c);
}

void			writeWin(int x, int y, char c, short colorpair)
{
	// if (colorpair == BACK_PAIR)
	// 	attron(A_DIM);
	// else
		attron(COLOR_PAIR(colorpair));
	writeWin(x, y, c);
	// if (colorpair == BACK_PAIR)
	// 	attroff(A_DIM);
	// else
		attroff(COLOR_PAIR(colorpair));
}

bool			winLossCheck(Player &player, Level &level)
{
	if (player.getLives() < 1)
	{
		clear();
		level.displayLoss();
		refresh();
		timeout(-1);
		getch();
		return true;
	}
	else if (player.getScore() > 400)
	{
		clear();
		level.displayVictory();
		refresh();
		timeout(-1);
		getch();
		return true;
	}
	Level::current = player.getScore() / 100 + 1;
	return false;
}

void			getInput(char c, Player &player, Level &level)
{
	switch(c)
	{
		case	'd':
			player.move(1, 0, level.col - player.getSizeW(), level.row);
			break;
		case	'a':
			player.move(-1, 0, level.col - player.getSizeW(), level.row);
			break;
        case	'q':
        	std::system("clear");
        	std::system("reset");
        	exit (0);
    }
}

void			init_game(void)
{
	Level::frames = 0;
	Level::current = 1;
	initscr();
	start_color();
	noecho();
	cbreak();
	noraw();
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	init_pair(BACK_PAIR, COLOR_YELLOW, 0);
	init_pair(PLAYER_PAIR		, COLOR_WHITE, 		COLOR_BLACK);
	init_pair(PLAYER_HURT_PAIR	, COLOR_GREEN, 		COLOR_RED);
	init_pair(ENEMY_PAIR		, COLOR_BLACK, 		COLOR_CYAN);
	init_pair(ENEMY_HURT_PAIR	, COLOR_GREEN, 		COLOR_RED);
	init_pair(VICTORY_PAIR		, COLOR_BLACK, 		COLOR_GREEN);
	init_pair(LOSS_PAIR			, COLOR_BLACK, 		COLOR_RED);
	init_pair(WALL_PAIR			, COLOR_BLACK, 		0);
	init_pair(WALL1_PAIR		, COLOR_GREEN, 		COLOR_GREEN);
	init_pair(BULLET_PAIR		, COLOR_WHITE, 		0);
	init_pair(FIRE_PAIR			, COLOR_RED, 		0);
	init_pair(MENU0_PAIR		, COLOR_WHITE, 		COLOR_BLUE);
	init_pair(MENU1_PAIR		, COLOR_WHITE, 		0);
	init_pair(BULLET1_PAIR		, COLOR_MAGENTA, 		0);
	if (has_colors() == FALSE)
	{
    	endwin();
    	std::cout << "Your terminal does not support color\n" << std::endl;
    	exit(1);
	}
}

void			game_loop(void)
{
	Menu menu;
	menu.Run();
	init_game();

	Level			level;

	std::string p0 = "                                    " ;
	std::string p1 = "                                    " ;
	std::string p2 = "                                    " ;
	std::string p3 = "                                    " ;
	std::string p4 = "             .-.,=\"``\"=.            " ;
	std::string p5 = "             '=/_       \\           " ;
	std::string p6 = "              !  '=._    !.         " ;
	std::string p7 = "               \\     `=./`,        '" ;
	std::string p8 = "                '=.__.=' `='        " ;
	std::string p9 = "                                    " ;
	std::string p10 = "                                    ";
	std::string p = p0 + p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 + p10;

	int n_pl = 2;
	Thing			planet1[2];
	for (int i = 0; i < 2; i++)
	{
		planet1[i].setSize(36, 11);
		planet1[i]._minx = 0;
		planet1[i]._maxx = level.col - 3;
		planet1[i]._miny = -80;
		planet1[i]._maxy = -12;
		planet1[i].spawn(0, level.col - 1, 0, level.row - 1);
		planet1[i].setPair(BACK_PAIR);
		planet1[i].setMap(p);
	}

	int				n_stars = 60;
	Thing			star[60];
	char			starchar[10] = { '*' , '+', '.', '`', '.', ',', '^', '*', '~', '.' };
	for (int i = 0; i < n_stars; i++)
	{
		star[i].setFill(starchar[rand() % 10]);
		star[i]._minx = 0;
		star[i]._maxx = level.col - 3;
		star[i]._miny = -10;
		star[i]._maxy = 0;
		star[i].spawn(0, level.col - 1, 0, level.row - 1);
		star[i].setPair(BACK_PAIR);
	}

	Player			player(menu.Getname());
	std::string s0 = "   /^\\   ";
	std::string s1 = "  /   \\  ";
	std::string s2 = " /|/ \\|\\ ";
	std::string s3 = "/_|| ||_\\";
	std::string s = s0 + s1 + s2 + s3 ;
	player.setMap(s);
	player.setSize(9, 4);



	int 			nb_enemies = 10;
	Enemy			enemy[10];
	std::string g0 = "#######";
	std::string g1 = " #   # ";
	std::string g2 = "  ###  ";
	std::string g3 = "   #   ";
	std::string g = g0 + g1 + g2 + g3 ;
	for(int i = 0; i < nb_enemies; i++)
	{
		enemy[i]._maxx = level.col - 4;
		enemy[i]._maxy = 1;
		enemy[i]._minx = 4;
		enemy[i]._miny = -30;
		enemy[i].respawn();

		if (i % 3)
		{
			enemy[i].setMap(g);
			enemy[i].setSize(7, 4);
		}
		
	}
	level.draw();
	player.setPos(level.col / 2, level.row - 2);
	player.draw(1);
	for(int i = 0; i < nb_enemies; i++)
	{
		if (enemy[i].collisionCheck() == true)
			enemy[i].takeHit();
		enemy[i].draw();
	}
	refresh();
	level.start_t = clock();
	while (1)
	{
		clock_t begin = clock();
		getInput(getch(), player, level);
		cbreak();
		clear();
		level.draw();
		for(int i = 0; i < n_pl; i++)
		{
			if (Level::frames % 6 == 0)
				planet1[i].move(0,1);	
			if (planet1[i].getPosY() >= level.row)
				planet1[i].respawn();
			planet1[i].draw();
		}
		for(int i = 0; i < n_stars; i++)
		{
			if (Level::frames % 6 == 0)
				star[i].move(0,1);	
			if (star[i].getPosY() >= level.row)
				star[i].respawn();
			star[i].draw();
		}
		refresh();
		player.doEveryFrame();	
		player.draw(0);
		refresh();
		for(int i = 0; i < nb_enemies; i++)
		{
			enemy[i].doEveryFrame();
			if (enemy[i].collisionCheck() == true)
			{
				enemy[i].takeHit();
				if (enemy[i].getLives() < 1)
					{
						player.addScore(10);
						enemy[i].respawn();
					}

			}
			else if (enemy[i].getPosY() >= level.row || enemy[i].getPosX() >= level.col)
				enemy[i].respawn();
			enemy[i].draw();
			refresh();
		}
		
		if (player.collisionCheck() == true)
			{
				player.takeHit();
				for(int i = 0; i < nb_enemies; i++)
				{
					if (enemy[i].getPosY() + enemy[i].getSizeH() >= player.getPosY() && enemy[i].getPosY() + enemy[i].getSizeH() <= player.getPosY() + player.getSizeH()
						&& ((enemy[i].getPosX() >= player.getPosX() && enemy[i].getPosX() <= player.getPosX() + player.getSizeW()) ||
							(enemy[i].getPosX()+ enemy[i].getSizeW() >= player.getPosX() && enemy[i].getPosX() + enemy[i].getSizeH()<= player.getPosX() + player.getSizeW())
							))
					{
						enemy[i].respawn();
					}
					for(int j = 0; j < 20; j++)
					{
						if (enemy[i].bullet[j].getPosY() >= player.getPosY() && enemy[i].bullet[j].getPosY() <= player.getPosY() + player.getSizeH()
							&& enemy[i].bullet[j].getPosX() >= player.getPosX() && enemy[i].bullet[j].getPosX() <= player.getPosX() + player.getSizeW())
						{
							enemy[i].bullet[j].respawn();
						}
					}
				}
			}
		if (winLossCheck(player, level) == true)
			break ;
		player.draw(1);
		level.displayPlayerInfo(player);
		refresh();
		 clock_t end = clock();
		 double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		while (elapsed_secs < 0.07f)
		{
			end = clock();
			elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			continue ;
		}
		Level::frames = (Level::frames + 1) % 1000;
	}
	endwin();
}

int				main(void)
{
	srand(time(NULL));
	game_loop();
	std::system("clear");
    std::system("reset");
	return 0;
}
