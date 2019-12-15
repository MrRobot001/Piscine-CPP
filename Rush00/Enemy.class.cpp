/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:11:12 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 18:11:13 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

#include "Level.class.hpp"

Enemy::Enemy(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Default Enemy";
	this->_maxLives = 1;
	this->_lives = this->_maxLives;
	this->_shootDir = 1;
	this->_shootCount = rand() % 10;
	this->_fill = 'E';
	this->_pair = ENEMY_PAIR;
	for(int i = 0; i < n_bullets; i++)
	{
		this->bullet[i].setPair(BULLET1_PAIR);
		this->bullet[i].setFill('#');
		this->bullet[i].setDir(1);
	}
}

Enemy::Enemy(const Enemy & copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;}

Enemy::Enemy(std::string name){
	std::cout << "Parametric constructor called" << std::endl;
	this->_name = name;
	this->_maxLives = 1;
	this->_lives = this->_maxLives;
	this->_shootDir = 1;
	this->_shootCount = rand() % 10;
	this->_fill = 'E';
	this->_pair = ENEMY_PAIR;
	for(int i = 0; i < n_bullets; i++)
	{
		this->bullet[i].setPair(BULLET1_PAIR);
		this->bullet[i].setFill('#');
		this->bullet[i].setDir(1);
	}
}

Enemy::~Enemy(void){
	std::cout << "Destructor called" << std::endl;}

Enemy&				Enemy::operator=(Enemy const &from)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name = from.getName();
	this->_lives = from.getLives();
	this->_maxLives = from.getMaxLives();
	this->_shootDir = from.getShootDir();
	this->_pair = from._pair;
	for(int i = 0; i < n_bullets; i++)
	{
		this->bullet[i].setDir(from.bullet[i].getDir());
	}
	return *this;
}

void				Enemy::doEveryFrame(void){
	int diff;
	if (this->_w != 1)
		this->_pair = PLAYER_PAIR;
	if (Level::current == 1)
		diff = 10;
	if (Level::current == 2)
		diff = 8;
	if (Level::current == 3)
		diff = 6;
	if (Level::current >= 4)
		diff = 4;
	if (Level::frames % diff == 0)
	{
		int chance(rand() % n_bullets);
	if (chance == 1)
		this->move(((rand() % (1 - (-1) + 1)) + (-1)), 1);
	else 
		this->move(0, 1);
	}
	
	if (this->_shootCount == 1)
		this->shoot();
	this->_shootCount = (this->_shootCount + 1) % 200;
	for(int i = 0; i < n_bullets; i++)
	{
		this->bullet[i].pause = diff - 3;
		this->bullet[i].doEveryFrame();
	}

}

















