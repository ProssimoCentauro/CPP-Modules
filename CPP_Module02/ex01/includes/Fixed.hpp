#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int	_rawBits;
		static const int	_fractionalBits = 8;

	public:

		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int	number);
		Fixed(const float number);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream& out, const Fixed& fixed);

#endif
