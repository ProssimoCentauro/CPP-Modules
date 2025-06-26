#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

float myAbs(float x) {
    return (x < 0) ? -x : x;
}


float	calculateArea(Point const a, Point const b, Point const c)
{
	
	float x1 = a.getX().toFloat();
	float y1 = a.getY().toFloat();
	float x2 = b.getX().toFloat();
	float y2 = b.getY().toFloat();
	float x3 = c.getX().toFloat();
	float y3 = c.getY().toFloat();

//	std::cout << x1 << "," << y1 << " | " << x2 << "," << y2 << " | " << x3 << "," << y3 << std::endl;
	float area = 0.5f * myAbs((x1*y2) + (x2*y3) + (x3*y1) - (x1*y3) - (x2*y1) - (x3*y2));
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float t0 = calculateArea(a, b, c); 

	float t1 = calculateArea(a, b, point); 
	float t2 = calculateArea(a, c, point); 
	float t3 = calculateArea(b, c, point);

//	std::cout << "\nt0: " << t0 << std::endl;
//	std::cout << "t1+t2+t3: " << t1+t2+t3 << std::endl;
	return (t0 == t1 + t2 + t3 && t1 > 0 && t2 > 0 && t3 > 0);
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
