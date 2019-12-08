/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:11:40 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/08 22:43:27 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
#define MENU_H

#include "retro.hpp"
#include <string>
#include <iostream>
class Menu
{
protected:
	std::string	name;
public:
	Menu(void);
	Menu(const Menu & copy);

	virtual ~Menu(void);
	Menu & operator=(const Menu & from);
	void		Run(void);
	void		displayMenu(void);
	std::string	Getname(void);
	int				row;
	int				col;
	int				wrow;
};

#endif
