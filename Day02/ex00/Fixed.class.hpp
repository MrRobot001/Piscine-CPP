/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:55:49 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/05 21:55:49 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>

class Fixed
{
private:
	int					fixed_pv;
	static const int	fract_b;
public:
	Fixed(void);
	Fixed(const Fixed &fix);
	Fixed	&operator= (const Fixed &fix);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	~Fixed(void);

};

#endif
