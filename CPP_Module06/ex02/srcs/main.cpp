#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

Base* generate() {
	Base *p = NULL;
    int r = rand() % 3;

    if (r == 0)
	{
		p = new A;
		std::cout << "Generated type: A" << std::endl;
	}
	else if (r == 1)
	{
		p = new B;
		std::cout << "Generated type: B" << std::endl;
	}
	else if (r == 2)
	{
		p = new C;
		std::cout << "Generated type: C" << std::endl;
	}

	return p;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "p type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "p type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "p type: C" << std::endl;
	else
		std::cout << "p type: UNRECOGNIZED!" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "p type: A" << std::endl;
		return;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "p type: B" << std::endl;
		return;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "p type: C" << std::endl;
		return;
	}
	catch (...) {}

	std::cout << "p type: UNRECOGNIZED!" << std::endl;
}

int	main()
{
	srand(time(0));

	Base *p = generate();
	Base *base = new Base;

	identify(p);
	identify(*p);

	std::cout << "\nTest with Base class" << std::endl;
	identify(base);
	identify(*base);
	
	std::cout << "\nTest with NULL class" << std::endl;
	identify(NULL);
	
	delete(p);

	return EXIT_SUCCESS;
}


