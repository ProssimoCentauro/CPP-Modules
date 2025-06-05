#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
    Point();
    Point(const Point& other);
    Point(float x, float y);
	Point& operator=(const Point& other);
    ~Point();

	//void setX( const Fixed& x);
	//void setY( const Fixed& y);

	Fixed getX( void ) const;
	Fixed getY( void ) const;

private:
	Fixed const x;
	Fixed const y;
};

#endif
