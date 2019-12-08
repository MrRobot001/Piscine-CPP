/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:11:51 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/08 23:03:32 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"

#include <ncurses.h>
Menu::Menu(void)
{
}

Menu::~Menu(void) {}

Menu::Menu(const Menu & copy)
{
*this = copy;
}

Menu&				Menu::operator=(Menu const &from){
	this->name = from.name;
	this->row = from.row;
	this->col = from.col;
	this->wrow = from.wrow;

	return *this;}

void	Menu::Run(void)
{
	initscr();
	this->displayMenu();
    char str[100];
    addstr("\n\n\nEnter name: ");
    getstr(str);
	this->name = str;
    curs_set(0);
	refresh();
}

void			Menu::displayMenu(void)
{
	int x, y;
	getmaxyx(stdscr, y, x);
	mvaddstr(y / 4, x / 3, "    #   #     # # #   #    #  #   #\n");
	mvaddstr(y / 4 + 1, x / 3, "   # # # #    #       ##   #  #   #\n");
	mvaddstr(y / 4 + 2, x / 3, "   # # # #    # # #   # #  #  #   #\n");
	mvaddstr(y / 4 + 3, x / 3, "  #   #   #   #       #  # #  #   #\n");
	mvaddstr(y / 4 + 4, x / 3, " #         #  # # #   #    #   ### \n");
}

std::string	Menu::Getname(void)
{
	return this->name;
}


