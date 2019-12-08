/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:51:28 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 14:51:30 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"
#include "retro.hpp"
#include <math.h>

Character::Character(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Default Character";
	this->_maxLives = 1;
	this->_lives = this->_maxLives;
	this->_shootDir = 0;
	this->_shootCount = 0;
	this->nextBulletIndex = 0;
}

Character::Character(const Character & copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;}

Character::Character(std::string name){
	std::cout << "Parametric constructor called" << std::endl;
	this->_name = name;
	this->_maxLives = 1;
	this->_lives = this->_maxLives;
	this->_shootDir = 0;
	this->_shootCount = 0;
this->nextBulletIndex = 0;}

Character::~Character(void){
	std::cout << "Destructor called" << std::endl;}

Character&				Character::operator=(Character const &from)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name = from.getName();
	this->_maxLives = from.getMaxLives();
	this->_lives = from.getLives();
	this->_shootDir = from.getShootDir();
	this->_shootCount = from.getShootCount();
this->nextBulletIndex = from.nextBulletIndex;

	return *this;
}

void					Character::shoot(void){

	// std::cout << "Shoot called" << std::endl;
	this->bullet[this->nextBulletIndex].active = true;
	int a(0);
	if (this->getShootDir() == 1)
		a = this->getSizeH();
	this->bullet[this->nextBulletIndex].setPos(this->getPosX() + floor((float)(this->_w -1) / 2), this->getPosY() + a + this->getShootDir() * 2);

	this->nextBullet();
	

}

int						Character::getLives(void) const{
	return this->_lives;}

int						Character::getMaxLives(void) const{
	return this->_maxLives;}

int						Character::getShootDir(void) const{
return this->_shootDir;
}

void					Character::takeHit(void)
{
	this->_lives--;
	if (this->_lives < 0)
		this->_lives = 0;
}

bool					Character::collisionCheck(void) const
{
	int	c[4] = { 'P', 'E', '|', '#' };
	int	current = mvinch(this->getPosY(), this->getPosX()) & A_CHARTEXT;
	for(int i = 0; i < 4; i++)
	{
		if (current == c[i])
			return true;
	}
	if (this->getSizeW() == 1 && this->getSizeH() == 1)
	{
		current = mvinch(this->getPosY(), this->getPosX()) & A_CHARTEXT;
		for(int i = 0; i < 4; i++)
		{
			if (current == c[i])
				return true;
		}
		return false;
	}
	else
	{
		for (int y = this->getPosY(); y < this->getPosY() + this->getSizeH(); y++)
		{
			for (int x = this->getPosX(); x < this->getPosX() + this->getSizeW(); x++)
			{
				current = mvinch(y, x) & A_CHARTEXT;
				for(int i = 0; i < 4; i++)
				{
					if (current == c[i])
						return true;
				}
			}
		}
	}
	return false;
}

void				Character::respawn(void)
{
	this->spawn(this->_minx, this->_maxx, this->_miny, this->_maxy);
	this->_lives = this->_maxLives;
}

void				Character::nextBullet(void)
{
	this->nextBulletIndex++;
	this->nextBulletIndex %= n_bullets;
}

void				Character::draw(void) const
{
	Thing::draw();

	for(int i = 0; i < n_bullets; i++)
	{
		this->bullet[i].draw();
	}

}

void		Character::setShootCount(int n)
{this->_shootCount = n;}
int			Character::getShootCount(void) const
{return this->_shootCount;}

const int Character::n_bullets = 20;









