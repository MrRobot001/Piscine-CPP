/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:42:20 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 18:42:22 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"
#include "retro.hpp"

Bullet::Bullet(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Default Bullet";
	this->_dir = 1;
	this->_fill = '|';
	this->active = false;
	this->_pair = BULLET_PAIR;
	this->pause = 1;
}

Bullet::Bullet(const Bullet & copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;}

Bullet::Bullet(std::string name){
	std::cout << "Parametric constructor called" << std::endl;
	this->_name = name;
	this->_dir = 1;
	this->_fill = '|';
	this->active = false;
	this->_pair = BULLET_PAIR;
}

Bullet::Bullet(int dir) : _dir(dir){
	std::cout << "Parametric constructor called" << std::endl;
	this->_name = "Default Bullet";
}

Bullet::~Bullet(void){
	std::cout << "Destructor called" << std::endl;}

Bullet&				Bullet::operator=(Bullet const &from)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name = from.getName();
	this->_dir = from.getDir();
	this->active = from.active;
	return *this;
}

void				Bullet::doEveryFrame(void){
	
	if (Level::frames % pause == 0)
	{
		if (this->active == true)
		this->move(0, this->_dir * 1);
	}
	if (this->getPosY() > LINES || this->getPosY() < 0)
		this->active = false;
	}

void				Bullet::setDir(int dir){
	this->_dir = dir;
}
int					Bullet::getDir(void) const{
	return this->_dir;
}









