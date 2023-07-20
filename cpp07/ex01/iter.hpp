#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template< typename T >
void iter(T *arr, int sz, void (*fc)(const T &)) {
	for (int i = 0; i < sz; i++)
	{
		fc(arr[i]);
	}
}

#endif