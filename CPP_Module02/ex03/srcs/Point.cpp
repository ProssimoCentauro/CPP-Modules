#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const Point& other) { *this = other; }

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        (Fixed) this->x = other.getX();
		(Fixed) this->y = other.getY();
    }
    return *this;
}

Point::~Point() {}


/*
void Point::setX( const Fixed& x)
{
	this->x = x;
}
void Point::setY( const Fixed& y)
{
	this->y = y;
}*/

Fixed Point::getX( void ) const
{
	return (this->x);
}
Fixed Point::getY( void ) const
{
	return (this->y);
}
