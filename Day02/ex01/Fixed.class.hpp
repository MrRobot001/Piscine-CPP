/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:55:58 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/05 21:55:58 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>
class Fixed
{
private:
	int					fixed_pv;
	static const int	fract_b;
public:
	Fixed(void);
	Fixed(int const _fix_pv);
	Fixed(float const _fix_pv);
	Fixed(const Fixed &fix);
	Fixed	&operator= (const Fixed &fix);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	~Fixed(void);
};

std::ostream &operator<< (std::ostream &os, Fixed const &fix);

#endif
