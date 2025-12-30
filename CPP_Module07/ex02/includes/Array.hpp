#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>

class Array
{
private:
	T*				_array;
	unsigned int	_size;

public:

	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();	
	
	unsigned int size(void) const;

	T& operator[](unsigned int index);
	
	class OutOfBoundsException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#include "Array.tpp"

#endif
