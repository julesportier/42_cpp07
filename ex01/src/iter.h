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
	if (!addr)
		throw std::invalid_argument("array address is NULL");
	if (!func)
		throw std::invalid_argument("func ptr is NULL");
	if (len < 0)
		throw std::out_of_range("len must be positive");
	for (L i = 0; i < len; ++i) {
		func(*(addr + i));
	}
};

#endif
