#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

Fixed myAbs(Fixed x) {
	    if (x.getRawBits() < 0)
    {
        Fixed tmp;
        tmp.setRawBits(-x.getRawBits());
        return (tmp);
    }
    return (x);
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

bool calculate_point(Point const a, Point const b, Point const c, Point const point)
{
	Fixed epsilon;
	epsilon.setRawBits(1);

    Fixed t0 = calculateArea(a, b, c);
    
	Fixed t1 = calculateArea(a, b, point);
    Fixed t2 = calculateArea(a, c, point);
    Fixed t3 = calculateArea(b, c, point);


    return (t0 == t1 + t2 + t3 && t1 > epsilon && t2 > epsilon && t3 > epsilon);
}

static void check_point(Point &a, Point &b, Point &c, Point &point)
{
    std::cout << "A: " << a.getX() << ", " << a.getY() << std::endl;
    std::cout << "B: " << b.getX() << ", " << b.getY() << std::endl;
    std::cout << "C: " << c.getX() << ", " << c.getY() << std::endl;
    std::cout << "Point: " << point.getX() << ", " << point.getY() << std::endl;
    if (calculate_point(a, b, c, point))
        std::cout << "Point is inside" << std::endl;
    else
        std::cout << "Point is outside, on an edge or a vertex" << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(-5.50495f, -4.5319f);
        std::cout << "Test 1: Point on vertex C (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(-7.60495f, 4.5081f);
        std::cout << "Test 2: Point on vertex A (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(-2.0f, 2.0f);
        std::cout << "Test 3: Point inside triangle (inside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(10.0f, 10.0f);
        std::cout << "Test 4: Point clearly outside triangle (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(-0.6647f, 4.877f);
        std::cout << "Test 5: Point on edge AB (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(-6.55495f, 0.0f);
        std::cout << "Test 6: Point on edge AC (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(0.385305f, 0.3574f);
        std::cout << "Test 7: Point on edge BC (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(-2.0f, 1.9f);
        std::cout << "Test 8: Point slightly inside center (inside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(-7.605f, 4.512f);
        std::cout << "Test 9: Point very close to vertex A (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(-6.55495f, 0.003f);
        std::cout << "Test 10: Point very close to edge AC (inside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(0.0f, 0.0f);
        Point b(5.0f, 0.0f);
        Point c(0.0f, 5.0f);
        Point point(1.0f, 1.0f);
        std::cout << "Test 11: Simple triangle (inside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(0.0f, 0.0f);
        Point b(5.0f, 0.0f);
        Point c(0.0f, 5.0f);
        Point point(2.5f, 2.5f);
        std::cout << "Test 12: Simple triangle - point on boundary (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(0.0f, 0.0f);
        Point b(5.0f, 0.0f);
        Point c(0.0f, 5.0f);
        Point point(2.51f, 2.51f);
        std::cout << "Test 13: Simple triangle - point slightly outside (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(0.0f, 0.0f);
        Point b(0.5f, 0.0f);
        Point c(0.0f, 0.5f);
        Point point(0.1f, 0.1f);
        std::cout << "Test 14: Very small triangle (inside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-7.60495f, 4.5081f);
        Point b(6.27556f, 5.2468f);
        Point c(-5.50495f, -4.5319f);
        Point point(-5.5053f, -4.5315f);
        std::cout << "Test 15: Point very close to vertex C (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-10.0f, -10.0f);
        Point b(10.0f, -10.0f);
        Point c(0.0f, 10.0f);
        Point point(0.0f, -5.0f);
        std::cout << "Test 16: Point on median of triangle (inside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(-10.0f, -10.0f);
        Point b(10.0f, -10.0f);
        Point c(0.0f, 10.0f);
        Point point(0.004f, -5.0f);
        std::cout << "Test 17: Point epsilon distance from median (inside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(0.0f, 0.0f);
        Point b(1.0f, 0.0f);
        Point c(0.0f, 1.0f);
        Point point(0.33f, 0.33f);
        std::cout << "Test 18: Unit triangle (inside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(0.0f, 0.0f);
        Point b(1.0f, 0.0f);
        Point c(0.0f, 1.0f);
        Point point(0.334f, 0.67f);
        std::cout << "Test 19: Unit triangle (outside)" << std::endl;
        check_point(a, b, c, point);
    }

    {
        Point a(0.0f, 0.0f);
        Point b(5.0f, 5.0f);
        Point c(10.0f, 10.0f);
        Point point(7.0f, 7.0f);
        std::cout << "Test 20: Degenerate triangle (outside)" << std::endl;
        check_point(a, b, c, point);
    }
    return (0);
}
