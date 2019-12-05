#include "Fixed.class.hpp"

		Fixed::Fixed(void) : fixed_pv(0)
		{
			std::cout << "Default constructor called" << std::endl;
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



		Fixed::~Fixed(void)
		{
			std::cout << "Destructor called" << std::endl;
		}