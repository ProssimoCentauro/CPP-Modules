#include "Point.hpp"

Point::Point() {}

Point::Point(const Point& other) { *this = other; }

Point::Point(float x, float y) : x(Fixed(x)), y(Fixed(y)) {}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        this->x = other.getX();
        this->y = other.getY();
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
