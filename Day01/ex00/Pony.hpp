/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:38:28 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/03 22:35:38 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POHY_HPP
#define POHY_HPP

#include <iostream>
#include <string>

class Pony
{
	private:
		std::string		name;
		std::string		color;
		int				len_of_horn;
		bool			shine;
	public:
		Pony(std::string _name, std::string _color, int _len_of_horn, bool _shine);
		~Pony(void);
		bool			Shine_o_Notshine(void) const;
};

#endif
