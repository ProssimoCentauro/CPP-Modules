#include <iostream>
#include "iter.hpp"

void printInt(int &i)
{
	std::cout << i << " ";
}
void printDouble(const double &d)
{
	std::cout << d << " ";
}

int main()
{
    int arrInt[] = {1, 2, 3, 4, 5};
    double arrDouble[] = {1.1, 2.2, 3.3};

    std::cout << "Integers: ";
    iter(arrInt, 5, printInt);
    std::cout << std::endl;

    std::cout << "Doubles: ";
    iter(arrDouble, 3, printDouble);
    std::cout << std::endl;

    return 0;
}

