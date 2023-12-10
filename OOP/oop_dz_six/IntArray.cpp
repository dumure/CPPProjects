#include "IntArray.h"
#include <iostream>

IntArray::~IntArray()
{
	delete[] m_data;
}

IntArray::IntArray()
{
	m_size = 0;
	m_capacity = 16;

	m_data = new int[m_capacity];
}

int IntArray::get_size()
{
	return m_size;
}

int IntArray::get_capacity()
{
	return m_capacity;
}

int IntArray::get_data(int index)
{
	return m_data[index];
}

void IntArray::reallocate()
{
	if (m_capacity == m_size)
	{
		m_capacity *= 2;
		int* new_data = new int[m_capacity];

		for (int i = 0; i < m_size; i++)
		{
			new_data[i] = m_data[i];
		}

		delete[] m_data;

		m_data = new_data;
	}
}

void IntArray::append(int value)
{
	reallocate();
	m_data[m_size] = value;
	m_size++;
}

void IntArray::prepend(int value)
{
	reallocate();
	for (int i = 0; i < m_size; i++)
	{
		m_data[i + 1] = m_data[i];
	}
	m_data[0] = value;
	m_size++;
}

bool IntArray::is_arr_empty()
{
	return m_size == 0;
}
