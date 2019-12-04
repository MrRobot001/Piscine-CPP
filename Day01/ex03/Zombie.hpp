/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:30:19 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 16:06:09 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string		name;
	std::string		type;
public:
	Zombie(void);
	Zombie(std::string _name, std::string _type);
	~Zombie(void);

	void		announce(void);
	void		setName(std::string _name);
	void		setType(std::string _type);
};

#endif
