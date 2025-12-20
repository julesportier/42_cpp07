#ifndef ITER_H
# define ITER_H

#include <iostream>
#include <stdexcept>

template <typename T>
void print_generic(T s)
{
	std::cout << s << '\n';
};

template <typename A, typename L, typename F>
void iter(A* addr, const L len, F func)
{
	if (addr == NULL)
		throw std::invalid_argument("address is NULL");
	for (L i = 0; i < len; ++i) {
		func(*(addr + i));
	}
};

#endif
