#ifndef ITER_H
# define ITER_H

#include <iostream>
#include <stdexcept>

template <typename T>
void iter(T* addr, const size_t len, void (*func)(T&))
{
	if (!addr)
		throw std::invalid_argument("array address is NULL");
	for (size_t i = 0; i < len; ++i) {
		func(*(addr + i));
	}
};

template <typename T>
void iter(const T* addr, const size_t len, void (*func)(const T&))
{
	if (!addr)
		throw std::invalid_argument("array address is NULL");
	for (size_t i = 0; i < len; ++i) {
		func(*(addr + i));
	}
};

#endif
