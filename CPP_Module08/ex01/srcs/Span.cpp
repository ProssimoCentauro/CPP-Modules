#include "Span.hpp"

Span::Span(unsigned int N) : _size(N) {
    if (N < 2)
        throw WrongArraySizeException();
    std::cout << "Span constructed" << std::endl;
}

Span::Span(const Span& other) {
    std::cout << "Span copied" << std::endl;
    *this = other;
}

Span& Span::operator=(const Span& other) {
    std::cout << "Span assigned" << std::endl;
    if (this != &other) {
        _vec = other._vec;
		_size = other._size;
    }
    return *this;
}

Span::~Span() {
    std::cout << "Span destructed" << std::endl;
}

int	Span::getMin()
{
	int min = _vec[0];

	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (_vec[i] < min)
			min = _vec[i];
	}
	return min;
}

int	Span::getMax()
{
	int max = _vec[0];

	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (_vec[i] > max)
			max = _vec[i];
	}
	return max;
}

void Span::addNumber(int num)
{
	if (_vec.size() >= _size)
		throw SpanFullException();
	_vec.push_back(num);
}

int Span::shortestSpan()
{
    if (_vec.size() < 2)
        throw WrongArraySizeException();

    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];

    for (size_t i = 1; i < tmp.size() - 1; i++)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}


int Span::longestSpan()
{
    if (_vec.size() < 2)
	{
        throw WrongArraySizeException();
	}

	return std::abs(getMax() - getMin()); 
}

const char *Span::SpanFullException::what() const throw()
{
	return "Span is full, cannot add number!\n";
}
const char *Span::WrongArraySizeException::what() const throw()
{
	return "Array size is < 2, cannot perform operation!\n";
}
