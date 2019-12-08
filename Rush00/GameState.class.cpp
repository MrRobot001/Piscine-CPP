/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:02:04 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 16:02:05 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameState.class.hpp"

GameState::GameState(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Default GameState";
}

GameState::GameState(const GameState & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

GameState::GameState(std::string name)
{
	std::cout << "Parametric constructor called" << std::endl;
	this->_name = name;
}

GameState::~GameState(void)
{
	std::cout << "Destructor called" << std::endl;
}

GameState&				GameState::operator=(GameState const &from)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name = from.getName();
	return *this;
}
