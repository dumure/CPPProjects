#pragma once
#include <iostream>

template<typename T>
class Array
{
	template<typename T2> friend std::ostream& operator<<(std::ostream&, const Array<T2>& a_array);
	int m_capacity;
	int m_size;
	T* m_data;
	void reallocate()
	{
		if (m_size == m_capacity)
		{
			m_capacity += 16;
			T* new_data = new T[m_capacity]{};
			for (int i = 0; i < m_size; ++i)
			{
				new_data[i] = m_data[i];
			}
			delete[] m_data;
			m_data = new_data;
		}
	}
public:
	~Array()
	{
		delete[] m_data;
	}
	Array(const Array& a_other)
	{
		m_capacity = a_other.m_capacity;
		m_size = a_other.m_size;
		m_data = new T[m_capacity];
		memcpy(m_data, a_other.m_data, sizeof(T) * m_capacity);
	}
	Array(Array&& a_other) noexcept
	{
		m_capacity = a_other.m_capacity;
		m_size = a_other.m_size;
		m_data = a_other.m_data;
		memcpy(m_data, a_other.m_data, sizeof(T) * m_capacity);
		a_other.m_capacity = 0;
		a_other.m_size = 0;
		a_other.m_data = nullptr;
	}
	Array(int a_capacity = 16)
	{
		m_capacity = a_capacity;
		m_size = 0;
		m_data = new T[m_capacity];
	}
	void append(T a_value)
	{
		reallocate();
		m_data[m_size] = a_value;
		++m_size;
	}
	void prepend(T a_value)
	{
		insert(0, a_value);
	}
	void insert(int a_index, T a_value)
	{
		for (int i = m_size; i < a_index; i--)
		{
			m_data[i] = m_data[i - 1];
		}
		m_data[a_index] = a_value;
		++m_size;
	}
	Array& operator=(const Array& a_other)
	{
		m_capacity = a_other.m_capacity;
		m_size = a_other.m_size;
		delete[] m_data;
		m_data = new T[m_capacity];
		memcpy(m_data, a_other.m_data, sizeof(T) * m_capacity);
		return *this;
	}
	Array& operator=(Array&& a_other) noexcept
	{
		m_capacity = a_other.m_capacity;
		m_size = a_other.m_size;
		delete[] m_data;
		m_data = a_other.m_data;
		a_other.m_capacity = 0;
		a_other.m_size = 0;
		a_other.m_data = nullptr;
		return *this;
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& a_array)
{
	os << "{ ";
	for (int i = 0; i < a_array.m_size; i++)
	{
		os << a_array.m_data[i];
		if (i != a_array.m_size - 1)
		{
			os << ", ";
		}
	}
	os << " }\n";
	return os;
}