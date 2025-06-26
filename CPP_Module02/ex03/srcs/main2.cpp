#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

Fixed myAbs(Fixed x) {
    return (x < Fixed(0) ? x * Fixed(-1) : x);
}

Fixed calculateArea(Point const a, Point const b, Point const c)
{
    Fixed x1 = a.getX();
    Fixed y1 = a.getY();
    Fixed x2 = b.getX();
    Fixed y2 = b.getY();
    Fixed x3 = c.getX();
    Fixed y3 = c.getY();

    Fixed term1 = x1 * y2 + x2 * y3 + x3 * y1;
    Fixed term2 = x1 * y3 + x2 * y1 + x3 * y2;
    Fixed area = myAbs(term1 - term2) * Fixed(0.5f);

    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed t0 = calculateArea(a, b, c);
    Fixed t1 = calculateArea(a, b, point);
    Fixed t2 = calculateArea(a, c, point);
    Fixed t3 = calculateArea(b, c, point);

    return (t0 == t1 + t2 + t3 && t1 > Fixed(0) && t2 > Fixed(0) && t3 > Fixed(0));
}

int main( void )
{
	// AREA = 1/2|x1y2 + x2y3 + x3y1 - x1y3 - x2y1 - x3y2|
	const Point a(-3.0f, -2.0f);
	const Point b(3.0f, 5.0f);
	const Point c(6.0f, -4.0f);
	
	//point inside the triangle
	const Point d(2.0f, 1.0f);
	
	//point outside the triangle
	const Point e(-3.0f, 5.0f);
	
	// point on the edge of the triangle
	const Point f(0.0f, 1.5f);
	
	a.printInfo("A");
	b.printInfo("B");
	c.printInfo("C");
	d.printInfo("D");
	e.printInfo("E");
	f.printInfo("F");

	std::cout << "Point D is inside the Triangle ABC: " << bsp(a, b, c, d) << std::endl;
	std::cout << "Point E is outside the Triangle ABC: " << bsp(a, b, c, e) << std::endl;
	std::cout << "Point F is on an edge of the Triangle ABC: " << bsp(a, b, c, e) << std::endl;
	std::cout << "Point B is on a vertex of the Triangle ABC: " << bsp(a, b, c, e) << std::endl;
	
	return (0);
}
