#include "RepositoryArray.h"

RepositoryArray::~RepositoryArray()
{
	for (int i = 0; i < m_local_size; i++)
	{
		delete m_arr.m_data[i];
	}
}

RepositoryArray::RepositoryArray()
{
	m_size = m_arr.m_size;
	m_capacity = m_arr.m_capacity;
}

void RepositoryArray::add(File* a_file)
{
	m_arr.append(a_file);
	m_size = m_arr.m_size;
	m_local_size = m_size;
	m_capacity = m_arr.m_capacity;
}

void RepositoryArray::remove(File* a_file)
{
	m_arr.remove(a_file);
	m_size = m_arr.m_size;
	m_capacity = m_arr.m_capacity;
}

int RepositoryArray::get_size()
{
	return m_size;
}

int RepositoryArray::get_capacity()
{
	return m_capacity;
}

File* RepositoryArray::operator[](int index)
{
	if (index > -1 && index < m_size)
	{
		return m_arr.m_data[index];
	}
	return nullptr;
}
