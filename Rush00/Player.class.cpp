/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:35:08 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 17:35:09 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"
#include "retro.hpp"

Player::Player(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Default Player";
	this->_maxLives = 3;
	this->_lives = this->_maxLives;
	this->_shootDir = -1;
	this->_score = 0;
	this->_fill = 'P';
	this->_pair = PLAYER_PAIR;
	this->_w = 1;
	this->_h = 1;

	for(int i = 0; i < n_bullets; i++)
	{
		this->bullet[i].setDir(this->_shootDir);
	}
}

Player::Player(const Player & copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;}

Player::Player(std::string name){
	std::cout << "Parametric constructor called" << std::endl;
	this->_name = name;
	this->_maxLives = 3;
	this->_lives = this->_maxLives;
	this->_shootDir = -1;
	this->_score = 0;
	this->_pair = PLAYER_PAIR;
this->_fill = 'P';
this->_w = 1;
	this->_h = 1;
for(int i = 0; i < n_bullets; i++)
	{
		this->bullet[i].setDir(this->_shootDir);
	}
	}

Player::~Player(void){
	std::cout << "Destructor called" << std::endl;}

Player&				Player::operator=(Player const &from)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name = from.getName();
	this->_lives = from.getLives();
	this->_maxLives = from.getMaxLives();
	this->_shootDir = from.getShootDir();
	this->_score = from.getScore();
	this->_pair = from._pair;
	for(int i = 0; i < n_bullets; i++)
	{
		this->bullet[i].setDir(from.bullet[i].getDir());
	}
	return *this;
}

void				Player::doEveryFrame(void){
	
	if (this->_shootCount == 1)
		this->shoot();
	this->_shootCount = (this->_shootCount + 1) % 6;

	for(int i = 0; i < n_bullets; i++)
		this->bullet[i].doEveryFrame();
	}

int					Player::getScore(void) const{
	return this->_score;}

void				Player::addScore(unsigned int amount){
	this->_score += amount;
}

void				Player::draw(int i) const
{

	std::string s0 = "###   ###";
	std::string s1 = " #     # ";

	if (i == 1)
		{
			Thing::draw();
			if (Level::frames % 3)
				{
					writeWin(this->_x, this->_y + this->_h, s0, FIRE_PAIR);
					writeWin(this->_x, this->_y + this->_h + 1, s1, FIRE_PAIR);
				}
			else if (Level::frames % 2)
				{
					writeWin(this->_x, this->_y + this->_h, s1, FIRE_PAIR);
					writeWin(this->_x, this->_y + this->_h + 1, s1, FIRE_PAIR);
				}
			else
				writeWin(this->_x, this->_y + this->_h, s1, FIRE_PAIR);
		}
	else
	{
		attroff(COLOR_PAIR(1));
	for(int i = 0; i < n_bullets; i++)
	{
		this->bullet[i].draw();
	}
	attron(COLOR_PAIR(1));
	}
	
}











