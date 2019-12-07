/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:31:34 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/07 20:19:33 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) {}

Enemy::Enemy(const Enemy &src)
{
	*this = src;
}

Enemy::Enemy(int hp, const std::string &type)
{
	this->_hp = hp;
	this->_type = type;
}

Enemy::~Enemy(void) {}

Enemy				&Enemy::operator= (const Enemy &rhs)
{
	if (this != &rhs)
	{
		this->_hp = rhs._hp;
		this->_type = rhs._type;
	}
	return (*this);
}

int					Enemy::getHP(void) const
{
	return (this->_hp);
}

const std::string	Enemy::getType(void) const
{
	return (this->_type);
}

void				Enemy::takeDamage(int damage)
{
	if (this->_hp - damage <= 0 && damage > 0)
		this->_hp = 0;
	else
		this->_hp -= damage;
}
