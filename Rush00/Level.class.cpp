/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 15:55:08 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/08 15:55:09 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Level.class.hpp"
#include "retro.hpp"

Level::Level(void)  {
	std::cout << "Default constructor called" << std::endl;
	getmaxyx(stdscr, wrow, col);
	row = wrow - 14;
	wall = '*';
}

Level::Level(const Level & copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;}

Level::~Level(void)  {
	
}

Level&				Level::operator=(Level const &from){
	std::cout << "Assignation operator called" << std::endl;
	this->row = from.row;
		wall = from.wall;
	return *this;}

void			Level::draw()
	{
		for (int i = 0; i < this->row; i++) // 2 vertical borders
    	{
    	    writeWin(0, i, this->wall, WALL_PAIR);
    	    writeWin(this->col - 1, i, this->wall, WALL_PAIR);
    	}
    	for (int i = 1; i < this->col - 1; i++) // 2 horizontal borders
    	{
    	    // writeWin(i, 0, this->wall, WALL1_PAIR);
    	    writeWin(i, this->row - 1, this->wall, WALL_PAIR);
    	}

	}
void			Level::displayPlayerInfo(Player &player)
{
	int			y(row + 4);
	int			x(2);
	int			sec;
	int			min;

	min = 0;
	sec = (clock() - this->start_t) / CLOCKS_PER_SEC;
	if (sec >= 60)
	{
		min = sec / 60;
		sec %= 60;
	}
	
	writeWin(x, y, "Name:  ", MENU0_PAIR);
	writeWin(x + 10, y, player.getName(), MENU1_PAIR);

	writeWin(x, y + 2, "Score: ", MENU0_PAIR);
	writeWin(x + 10, y + 2, std::to_string(player.getScore()), MENU1_PAIR);

	writeWin(x, y + 4, "Lives: ", MENU0_PAIR);
	writeWin(x + 10, y + 4, std::to_string(player.getLives()), MENU1_PAIR);
	writeWin(x, y + 6, "Level: ", MENU0_PAIR);
	writeWin(x + 10, y + 6, std::to_string(Level::current), MENU1_PAIR);
	writeWin(x, y + 8, "Time:  ", MENU0_PAIR);
	writeWin(x + 10, y + 8, std::to_string(min), MENU1_PAIR);
	writeWin(x + 11, y + 8, ":", MENU1_PAIR);
	if (sec < 10)
	{
		writeWin(x + 12, y + 8, "0", MENU1_PAIR);
		writeWin(x + 13, y + 8, std::to_string(sec), MENU1_PAIR);
	}
	else 
		writeWin(x + 12, y + 8, std::to_string(sec), MENU1_PAIR);
}
void			Level::displayLoss(void)
{
	int			y(wrow / 2);
	int			x(col/3);
	attron(A_BOLD);
	writeWin(x, y++, "#   # #### #  #   #    #### #### #####  ##", 2);
	writeWin(x, y++, " # #  #  # #  #   #    #  # #      #    ##", 2);
	writeWin(x, y++, "  #   #  # #  #   #    #  # ####   #    ##", 2);
	writeWin(x, y++, "  #   #  # #  #   #    #  #    #   #      ", 2);
	writeWin(x, y++, "  #   #### ####   #### #### ####   #    ##", 2);
}
void			Level::displayVictory(void)
{
	int			y(wrow / 2);
	int			x(col/3);
	attron(A_BOLD);
	writeWin(x, y++, "#   # #### #  #   #         # #### #    #  ##", 2);
	writeWin(x, y++, " # #  #  # #  #    #   #   #  #  # ##   #  ##", 2);
	writeWin(x, y++, "  #   #  # #  #     # # # #   #  # # #  #  ##", 2);
	writeWin(x, y++, "  #   #  # #  #     # # # #   #  # #  # #    ", 2);
	writeWin(x, y++, "  #   #### ####      #   #    #### #    #  ##", 2);
}

int Level::frames;
int Level::current;

