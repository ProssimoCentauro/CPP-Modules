#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator res = std::find(container.begin(), container.end(),  value);
	
	if (res == container.end())
		throw std::out_of_range("Exception: Value not found!");
	return res;
}
