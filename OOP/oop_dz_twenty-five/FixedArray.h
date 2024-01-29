#pragma once
#include <iostream>
#include "LimitException.h"
#include "OutOfRangeException.h"
template<typename T, int Size>
class FixedArray
{
	T* m_data;
	int m_size;
public:
	~FixedArray()
	{
		delete[] m_data;
	}
	FixedArray(const FixedArray& a_other)
	{
		m_size = a_other.m_size;
		m_data = new T[Size]{};
		memcpy(m_data, a_other.m_data, Size * sizeof(T));
	}
	FixedArray(FixedArray&& a_other) noexcept
	{
		m_size = a_other.m_size;
		m_data = a_other.m_data;
		a_other.m_size = 0;
		a_other.m_data = nullptr;
	}
	FixedArray()
	{
		m_data = new T[Size]{};
		m_size = 0;
	}
	void push_back(const T& a_value)
	{
		if (m_size == Size)
		{
			throw LimitException{};
		}
		m_data[m_size] = a_value;
		++m_size;
	}
	T& operator[](int a_index)
	{
		if (a_index < 0 || a_index >= m_size)
		{
			throw OutOfRangeException{};
		}
		return m_data[a_index];
	}
	FixedArray& operator=(const FixedArray& a_other)
	{
		if (a_other == *this)
		{
			return *this;
		}
		~FixedArray();
		m_size = a_other.m_size;
		m_data = new T[Size]{};
		memcpy(m_data, a_other.m_data, Size * sizeof(T));
		return *this;
	}
	FixedArray& operator=(FixedArray&& a_other) noexcept
	{
		if (a_other == *this)
		{
			return *this;
		}
		~FixedArray();
		m_size = a_other.m_size;
		m_data = a_other.m_data;
		a_other.m_size = 0;
		a_other.m_data = nullptr;
		return *this;
	}
};

