#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const Point& other) : x(other.getX()), y(other.getY()) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}


Point &Point::operator=(const Point &other)
{
    (void)other;
    return (*this);
}

Point::~Point() {}

Fixed Point::getX( void ) const
{
	return (this->x);
}
Fixed Point::getY( void ) const
{
	return (this->y);
}

void Point::printInfo( std::string name ) const
{
	std::cout 
		<< "Point" << name << "(" 
		<< this->getX().toFloat() 
		<< ", " 
		<< this->getY().toFloat() 
		<< ")" 
		<< std::endl;
}

