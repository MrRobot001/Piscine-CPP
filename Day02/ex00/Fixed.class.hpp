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
