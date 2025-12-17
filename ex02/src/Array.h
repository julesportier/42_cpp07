#ifndef ARRAY_H
# define ARRAY_H

#include <exception>

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
		return (m_size); // better with size_t ?
	}

private:
	const unsigned int m_size;
	T* m_arr;
};

#endif
