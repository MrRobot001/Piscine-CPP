/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thing.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:43:36 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 14:43:37 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THING_CLASS_H
#define THING_CLASS_H

#include <ncurses.h>
#include <iostream>
class Thing
{
public:
	Thing(void);
	Thing(const Thing & copy);
	Thing(std::string name);
	Thing(std::string name, int x, int y);
	Thing(std::string name, int x, int y, int w, int h);
	Thing(std::string name, int x, int y, int w, int h, const std::string map);
	Thing(std::string name, int x, int y, int w, int h, const std::string map, char fill);
	virtual ~Thing(void);
	Thing & operator=(const Thing & from);

	std::string		getName(void) const;
	std::string		getMap(void) const;
	void			setMap(std::string map);
	void			setPair(short pair);
	char			getFill(void) const;
	void			getPos(int & x, int & y) const;
	void			getSize(int & w, int & h) const;
	int				getPosX(void) const;
	int				getPosY(void) const;
	int				getSizeW(void) const;
	int				getSizeH(void) const;
	void			setPos(const int x, const int y);
	void			setFill(char fill);
	void			setSize(const int w, const int h);
	void			move(int x, int y);
	void			move(int x, int y, int maxx, int maxy);
	void			draw(void) const;
	void			doEveryFrame(void);
	void			spawn(int minx, int maxx, int miny, int maxy);
	void			respawn(void);

	int				_maxx;
	int				_maxy;
	int				_minx;
	int				_miny;
protected:
	std::string		_name;
	int				_x;
	int				_y;

	int				_w;
	int				_h;
	std::string		_map;
	char			_fill;
	short			_pair;
};


#endif
