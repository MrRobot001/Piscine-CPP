/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:33:47 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 16:42:15 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {}
Brain::~Brain(void) {}

std::string		Brain::identify(void) const
{
	std::stringstream brains_address;
	brains_address << (void *)this;
	return brains_address.str();
}
