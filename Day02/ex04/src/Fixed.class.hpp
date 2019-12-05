#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
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

	Fixed			&operator= (const Fixed &fix);

	friend bool		operator> (const Fixed &fix1, const Fixed &fix2);
	friend bool		operator< (const Fixed &fix1, const Fixed &fix2);

	friend bool		operator>= (const Fixed &fix1, const Fixed &fix2);
	friend bool		operator<= (const Fixed &fix1, const Fixed &fix2);

	friend bool		operator== (const Fixed &fix1, const Fixed &fix2);
	friend bool		operator!= (const Fixed &fix1, const Fixed &fix2);

	Fixed			operator+(Fixed const &fix);
	Fixed			operator-(Fixed const &fix);
	Fixed			operator/(Fixed const &fix);
	Fixed			operator*(Fixed const &fix);

	Fixed			&operator++(void);
	Fixed			&operator--(void);
	Fixed			operator++(int);
	Fixed			operator--(int);

	int				getRawBits(void) const;
	void			setRawBits(int const raw);

	float			toFloat(void) const;
	int				toInt(void) const;

	static Fixed		&min(Fixed &fix1, Fixed &fix2);
	static const Fixed	&min(Fixed const &fix1, Fixed const &fix2);
	static Fixed		&max(Fixed &fix1, Fixed &fix2);
	static const Fixed	&max(Fixed const &fix1, Fixed const &fix2);


	~Fixed(void);
};

std::ostream &operator<< (std::ostream &os, Fixed const &fix);


#endif
