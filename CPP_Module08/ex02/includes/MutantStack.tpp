#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	*this = other;
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return (std::stack<T>::c.end());
}
