/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:56:13 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/05 21:56:13 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:54:21 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/05 21:54:21 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void) : fixed_pv(0)
{
}

Fixed::Fixed(int const _fix_pv)
{
	this->fixed_pv = _fix_pv << Fixed::fract_b;
}

Fixed::Fixed(float const _fix_pv)
{
	this->fixed_pv = (int)roundf(_fix_pv * (1 << Fixed::fract_b));
}

Fixed::Fixed(const Fixed &fix) : fixed_pv(fix.getRawBits())
{
}

const int Fixed::fract_b = 8;

Fixed	&Fixed::operator= (const Fixed &fix)
{
	this->fixed_pv = fix.getRawBits();
	return *this;
}

bool operator> (const Fixed &fix1, const Fixed &fix2)
{
	return (fix1.fixed_pv > fix2.fixed_pv);
}

bool operator< (const Fixed &fix1, const Fixed &fix2)
{
	return (fix1.fixed_pv < fix2.fixed_pv);
}

bool operator>= (const Fixed &fix1, const Fixed &fix2)
{
	return (fix1.fixed_pv >= fix2.fixed_pv);
}

bool operator<= (const Fixed &fix1, const Fixed &fix2)
{
	return (fix1.fixed_pv <= fix2.fixed_pv);
}

bool	operator== (const Fixed &fix1, const Fixed &fix2)
{
	return (fix1.fixed_pv == fix2.fixed_pv);
}

bool	operator!= (const Fixed &fix1, const Fixed &fix2)
{
	return !(fix1 == fix2);
}


Fixed Fixed::operator+(Fixed const &fix)
{
	Fixed temp;

	temp.setRawBits(this->fixed_pv + fix.getRawBits());
	return temp;
}

Fixed Fixed::operator-(Fixed const &fix)
{
	Fixed temp;

	temp.setRawBits(this->fixed_pv - fix.getRawBits());
	return temp;
}

Fixed Fixed::operator*(Fixed const &fix)
{
	Fixed temp;

	temp.setRawBits((this->fixed_pv * fix.getRawBits()) >> Fixed::fract_b);
	return temp;
}

Fixed Fixed::operator/(Fixed const &fix)
{
	Fixed temp;

	temp.setRawBits((this->fixed_pv << Fixed::fract_b) / fix.getRawBits());
	return temp;
}



Fixed		&Fixed::operator++(void)
{
	this->fixed_pv++;
	return *this;
}

Fixed		&Fixed::operator--(void)
{
	this->fixed_pv--;
	return *this;
}

Fixed		Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return temp;
}

Fixed		Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return temp;
}


Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed & Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed & Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}


int		Fixed::getRawBits(void) const
{
	return this->fixed_pv;
}

void	Fixed::setRawBits(int const raw)
{
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
}
