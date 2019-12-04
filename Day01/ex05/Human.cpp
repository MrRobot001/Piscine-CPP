/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:33:51 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 16:50:20 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) {}
Human::~Human(void) {}

const Brain		&Human::getBrain(void) const
{
	return this->brain;
}

std::string		Human::identify(void) const
{
	return this->brain.identify();
}
