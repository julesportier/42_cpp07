#ifndef ARRAY_H
# define ARRAY_H

#include <exception>
#include <iostream>

template <typename T> class Array
{
public:
	Array()
		: m_size(0)
		, m_arr(new T[0])
	{}

	Array(unsigned int size)
		: m_size(size)
		, m_arr(new T[size])
	{}

	Array(const Array& src)
		: m_size(src.m_size)
		, m_arr(new T[src.m_size])
	{
		for (unsigned int i = 0; i < m_size; ++i) {
			m_arr[i] = src.m_arr[i];
		}
	}

	~Array()
	{
		delete[] m_arr;
	}

	Array& operator=(const Array& src) const
	{
		if (&src != this) {
			for (unsigned int i = 0; i < m_size && i < src.m_size; ++i) {
				m_arr[i] = src.m_arr[i];
			}
		}
		return (*this);
	}

	T& operator[](unsigned int i)
	{
		if (i >= m_size || i < 0) {
			throw std::exception();
		}
		return (m_arr[i]);
	}

	unsigned int size() const
	{
		return (m_size);
	}

private:
	const unsigned int m_size;
	T* m_arr;
};

template <typename T>
void fill_array(Array<T>& a, unsigned int start, unsigned int step)
{
	for (unsigned int i = 0; i < a.size(); ++i) {
		a[i] = start + i * step;
	}
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& array)
{
	unsigned int size = array.size();
	if (size == 0) {
		os << "[]";
		return (os);
	}
	os << "[";
	for (unsigned int i = 0; i < size - 1; ++i) {
		os << array[i] << ", ";
	}
	os << array[size - 1] << "]\n";
	return (os);
}

template <typename T>
void print_array(Array<T>& a, const std::string& name)
{
	std::cout << "# " << name << " #"<< '\n';
	std::cout << "object address: " << &a << '\n';
	std::cout << "member array address: " << &(a[0]) << '\n';
	std::cout << a << '\n';
}

#endif
