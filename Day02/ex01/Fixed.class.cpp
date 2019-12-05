/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:55:55 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/05 21:55:55 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void) : fixed_pv(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const _fix_pv)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_pv = _fix_pv << Fixed::fract_b;
}

Fixed::Fixed(float const _fix_pv)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_pv = (int)roundf(_fix_pv * (1 << Fixed::fract_b));
}

Fixed::Fixed(const Fixed &fix) : fixed_pv(fix.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

const int Fixed::fract_b = 8;

Fixed	&Fixed::operator= (const Fixed &fix)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixed_pv = fix.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_pv;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_pv = raw;
}

int		Fixed::toInt(void) const
{
	return this->fixed_pv >> Fixed::fract_b;
}

float	Fixed::toFloat(void) const
{
	return this->fixed_pv / (float)(1 << Fixed::fract_b);
}

std::ostream &operator<< (std::ostream &os, Fixed const &fix)
{
	os << fix.toFloat();
	return os;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
