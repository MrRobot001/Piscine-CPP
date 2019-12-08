/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thing.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:43:18 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 14:43:31 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Thing.class.hpp"
#include "Level.class.hpp"
#include "retro.hpp"
#include <fstream>
#include <string>

Thing::Thing(void) : _name("Default Thing"){
	
	this->_x = 0;
	this->_y = 0;
	this->_maxx = 0;
	this->_maxy = 0;
	this->_minx = 0;
	this->_miny = 0;
	this->_w = 1;
	this->_h = 1;
	this->_map = "o";
	this->_fill = '+';
	this->_pair = 1;
}

Thing::Thing(const Thing & copy){
	
	*this = copy;}

Thing::Thing(std::string name) :  _name(name), _x(0), _y(0), _w(1), _h(1), _map("o"), _fill('+'){
	}

Thing::Thing(std::string name, int x, int y) : _name(name), _x(x), _y(y), _w(1), _h(1), _map("o"), _fill('+'){
	}

Thing::Thing(std::string name, int x, int y, int w, int h) : _name(name), _x(x), _y(y), _w(w), _h(h), _map("o"), _fill('+'){
	
	this->_map.resize(w * h);
	// this->_map.assign(w * h, 'o');
	this->_pair = 1;
}

Thing::Thing(std::string name, int x, int y, int w, int h, const std::string map) : _name(name), _x(x), _y(y), _w(w), _h(h), _map(map), _fill('+'){
	std::cout << "Parametric3 constructor called" << std::endl;}

Thing::Thing(std::string name, int x, int y, int w, int h, const std::string map, char fill) : _name(name), _x(x), _y(y), _w(w), _h(h), _map(map), _fill(fill){
	std::cout << "Parametric4 constructor called" << std::endl;}

Thing::~Thing(void){
	std::cout << "Destructor called" << std::endl;}

Thing&				Thing::operator=(Thing const &from){
	std::cout << "Assignation operator called" << std::endl;
	this->_name = from.getName();
	this->_x = from.getPosX();
	this->_y = from.getPosY();
	this->_w = from.getSizeW();
	this->_h = from.getSizeH();
	this->_map = from.getMap();
	this->_fill = from.getFill();
	this->_pair = from._pair;
	return *this;}

std::string			Thing::getName(void) const{
	return this->_name;}

std::string			Thing::getMap(void) const{
	return this->_map;}

void				Thing::setMap(std::string map) {
	this->_map = map;
// this->_map.resize(_w * _h);
}

void				Thing::setFill(char fill) {
	this->_fill = fill;

}

void				Thing::getPos(int & x, int &y) const{
	x = this->_x; y = this->_y;}

int					Thing::getPosX(void) const{
	return this->_x;}
int					Thing::getPosY(void) const{
	return this->_y;}

char				Thing::getFill(void) const{
	return this->_fill;}

void				Thing::getSize(int & w, int &h) const{
	w = this->_w; h = this->_h;}

int					Thing::getSizeW(void) const{
	return this->_w;}
int					Thing::getSizeH(void) const{
	return this->_h;}

void				Thing::setPos(const int x, const int y) {
	this->_x = x; this->_y = y;}

void				Thing::setPair(short pair) {
	this->_pair = pair;}


void				Thing::setSize(const int w, const int h) {
	this->_w = w; this->_h = h;}

void				Thing::move(int x, int y) {
	this->_x += x; this->_y += y;}

void				Thing::move(int x, int y, int maxx, int maxy) {
	if (this->_x + x > 2 && this->_x + x < maxx - 2)
		this->_x += x;
	if (this->_y + y > 2 && this->_y + y < maxy - 2)
		this->_y += y;}

void				Thing::draw(void) const
{
	if (this->getSizeH() == 1 && this->getSizeW() == 1)
		writeWin(this->_x, this->_y, this->_fill, this->_pair);
	else
	{
		for (int y = this->getPosY(); y < this->getPosY() + this->getSizeH(); y++)
		{
			for (int x = this->getPosX(); x < this->getPosX() + this->getSizeW(); x++)
			{
				size_t a(x - this->getPosX() + this->getSizeW() * (y - this->getPosY()));
				if (a < this->_map.length())
					writeWin(x, y, this->_map.at(a), this->_pair);
			}
		}
	}
}

void				Thing::doEveryFrame(void)
{
	return;
}

void				Thing::spawn(int minx, int maxx, int miny, int maxy)
{
	int x(((rand() % (maxx - minx + 1)) + minx));
	int y(((rand() % (maxy - miny + 1)) + miny));
	this->setPos(x, y);
}

void				Thing::respawn(void)
{
	this->spawn(this->_minx, this->_maxx, this->_miny, this->_maxy);
}
























