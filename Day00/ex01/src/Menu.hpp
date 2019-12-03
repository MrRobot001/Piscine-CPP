/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 21:17:54 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/03 14:55:02 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warehouse.hpp"
#include <termios.h>

class Menu
{
protected:
	Warehouse	Phonebook;
	static		Menu* _self;
	Menu (void) {}
	virtual		~Menu() {}
public:
	static		Menu* Create_menu();
	void		Run(void);
	static bool	Delete_munu(void);
};
