#include "IntArray.h"

IntArray::~IntArray()
{
	delete[] m_data;
}

IntArray::IntArray(const IntArray& other)
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;

	memcpy(m_data, other.m_data, other.m_size * sizeof(int));
}

IntArray::IntArray(IntArray&& other)
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_data = other.m_data;

	other.m_size = 0;
	other.m_capacity = 0;
	other.m_data = nullptr;
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

IntArray& IntArray::operator=(const IntArray& other)
{
	if (this == &other)
	{
		return *this;
	}
	m_size = other.m_size;
	m_capacity = other.m_capacity;

	this->~IntArray();

	m_data = new int[m_capacity];
	memcpy(m_data, other.m_data, other.m_size * sizeof(int));

	return *this;
}

IntArray& IntArray::operator=(IntArray&& other)
{
	if (this == &other)
	{
		return *this;
	}
	m_size = other.m_size;
	m_capacity = other.m_capacity;

	this->~IntArray();
	m_data = other.m_data;

	m_size = 0;
	m_capacity = 0;
	m_data = nullptr;

	return *this;
}

int& IntArray::operator[](int index)
{
	return m_data[index];
}

IntArray IntArray::operator+(const IntArray& other)
{
	IntArray new_array;

	for (int i = 0; i < m_size; i++)
	{
		new_array.append(m_data[i]);
	}

	for (int i = 0; i < other.m_size; i++)
	{
		new_array.append(other.m_data[i]);
	}

	return new_array;
}

