/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:21:49 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 18:38:11 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHEAPON_CLASS_HPP
#define WHEAPON_CLASS_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
	std::string			type;

public:
	Weapon(std::string _type);
	~Weapon(void);

	const std::string	getType(void);
	void				setType(std::string _type);
};


#endif
