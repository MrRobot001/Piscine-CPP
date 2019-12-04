/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:33:49 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/04 16:52:04 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human
{
private:
	const Brain brain;
public:
	Human(void);
	~Human(void);

	const Brain		&getBrain() const;
	std::string		identify() const;

};

#endif
