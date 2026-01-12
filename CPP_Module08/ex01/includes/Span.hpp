#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <algorithm>

class Span {
private:
	std::vector<int> _vec;
	unsigned int _size;

	int	getMin();
	int	getMax();

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

	void addNumber(int num);

	int shortestSpan();
	int longestSpan();

	class SpanFullException : public std::exception
    {
        const char *what() const throw();
    };
	class WrongArraySizeException : public std::exception
    {
        const char *what() const throw();
    };
};

#endif
