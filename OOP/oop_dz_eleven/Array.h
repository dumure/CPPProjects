#pragma once
#include <iostream>

template<typename T>
class Array
{
	int m_capacity;
	int m_size;
	T* m_data;
	void reallocate()
	{
		if (m_size == m_capacity)
		{
			T* new_data = new T[m_capacity];
			m_capacity += 16;
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
		delete[] a_data;
	}
	Array(const Array& a_other)
	{
		m_capacity = a_other.m_capacity;
		m_size = a_other.m_size;
		m_data = new T[m_capacity];
		memcpy(m_data, a_other.m_data, sizeof(T) * m_capacity);
	}
	Array(Array&& a_other)
	{
		m_capacity = a_other.m_capacity;
		m_size = a_other.m_size;
		m_data = a_other.m_data;
		memcpy(m_data, a_other.m_data, sizeof(T) * m_capacity);
		a_other.m_capacity = 0;
		a_other.m_size = 0;
		a_other.m_data = nullptr;
	}
	Array(Array)
};

