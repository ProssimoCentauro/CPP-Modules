#include "Bureaucrat.hpp"

int main()
{
    try
	{
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade(); // diventa grade 1
        std::cout << b1 << std::endl;

        b1.incrementGrade(); // lancia eccezione
    }
    catch (const std::exception& e)
	{
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}

