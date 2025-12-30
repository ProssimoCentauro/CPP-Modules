#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	_size = 0;
	_array = new T[_size];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[_size];
}

template <typename T>
Array<T>::Array(const Array& other)
{
	_size = other.size();
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}
	
template <typename T>
unsigned int Array<T>::size(void) const
{
	return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}
	
template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index out of bounds";
}
