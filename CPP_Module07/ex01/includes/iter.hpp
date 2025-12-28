#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename U, typename F>
void iter(T* array, const U len, F func)
{
    for (U i = 0; i < len; i++)
        func(array[i]);
}

#endif

