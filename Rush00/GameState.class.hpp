/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshpakov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:01:58 by mshpakov          #+#    #+#             */
/*   Updated: 2019/12/07 16:01:59 by mshpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMESTATE_CLASS_H
#define GAMESTATE_CLASS_H

#include <iostream>

class GameState
{
public:
	GameState(void);
	GameState(const GameState & copy);
	virtual ~GameState(void);
	GameState & operator=(const GameState & from);
};


#endif
