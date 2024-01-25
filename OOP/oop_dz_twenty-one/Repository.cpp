#include "Repository.h"

void Repository::reallocate()
{
	if (m_size == m_capacity)
	{
		m_capacity += 16;
		File** new_data = new File * [m_capacity] {};
		for (int i = 0; i < m_size; ++i)
		{
			new_data[i] = m_data[i];
		}
		delete[] m_data;
		m_data = new_data;
	}
}
Repository::~Repository()
{
	for (int i = 0; i < m_local_size; i++)
	{
		delete m_data[i];
	}
	delete[] m_data;
}
Repository::Repository(const Repository& a_other)
{
	m_capacity = a_other.m_capacity;
	m_size = a_other.m_size;
	m_data = new File * [m_capacity];
	memcpy(m_data, a_other.m_data, sizeof(File*) * m_capacity);
}
Repository::Repository(Repository&& a_other)
{
	m_capacity = a_other.m_capacity;
	m_size = a_other.m_size;
	m_data = a_other.m_data;
	memcpy(m_data, a_other.m_data, sizeof(File*) * m_capacity);
	a_other.m_capacity = 0;
	a_other.m_size = 0;
	a_other.m_data = nullptr;
}
Repository::Repository()
{
	m_capacity = 16;
	m_size = 0;
	m_local_size = m_size;
	m_data = new File * [m_capacity];
}
void Repository::add(File* a_value)
{
	reallocate();
	m_data[m_size] = a_value;
	++m_size;
	++m_local_size;
}
void Repository::remove(File* a_value)
{
	int index = m_size;
	for (int i = 0; i < m_size; i++)
	{
		if (m_data[i] == a_value)
		{
			index = i;
			break;
		}
	}
	for (int i = index; i < m_size - 1; i++)
	{
		File* temp = m_data[i];
		m_data[i] = m_data[i + 1];
		m_data[i + 1] = temp;
	}
	--m_size;
}
File* Repository::operator[](int index)
{
	if (index > -1 && index < m_size)
	{
		return m_data[index];
	}
	return nullptr;
}
Repository& Repository::operator=(const Repository& a_other)
{
	m_capacity = a_other.m_capacity;
	m_size = a_other.m_size;
	delete[] m_data;
	m_data = new File * [m_capacity];
	memcpy(m_data, a_other.m_data, sizeof(File*) * m_capacity);
	return *this;
}
Repository& Repository::operator=(Repository&& a_other)
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