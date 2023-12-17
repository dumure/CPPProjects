#include "SortedRandomArray.h"

SortedRandomArray::~SortedRandomArray()
{
	delete[] m_data;
}

SortedRandomArray::SortedRandomArray(const SortedRandomArray& a_other)
{
	m_size = a_other.m_size;
	m_data = new int[m_size];
	memcpy(m_data, a_other.m_data, m_size * sizeof(int));
}

SortedRandomArray::SortedRandomArray(SortedRandomArray&& a_other)
{
	m_size = a_other.m_size;
	m_data = a_other.m_data;
	a_other.m_size = 0;
	a_other.m_data = nullptr;
}

SortedRandomArray::SortedRandomArray(int a_size)
{
	srand(time(0));
	m_size = a_size;
	m_data = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = rand() % 100;
	}
}

void SortedRandomArray::sort(Greater a_greater)
{
	int skips = 0;
	bool flag = true;
	for (int i = 0; i < m_size - 1 && flag; i++)
	{
		for (int j = 0; j < m_size - i - 1; j++)
		{
			skips++;
			if (a_greater(m_data[j], m_data[j + 1]))
			{
				skips = 0;
				int temp = m_data[j];
				m_data[j] = m_data[j + 1];
				m_data[j + 1] = temp;
			}
			if (skips == m_size - 1)
			{
				flag = false;
				break;
			}
		}
	}
}

void SortedRandomArray::sort(Less a_less)
{
	int skips = 0;
	bool flag = true;
	for (int i = 0; i < m_size - 1 && flag; i++)
	{
		for (int j = 0; j < m_size - i - 1; j++)
		{
			skips++;
			if (a_less(m_data[j], m_data[j + 1]))
			{
				skips = 0;
				int temp = m_data[j];
				m_data[j] = m_data[j + 1];
				m_data[j + 1] = temp;
			}
			if (skips == m_size - 1)
			{
				flag = false;
				break;
			}
		}
	}
}

SortedRandomArray& SortedRandomArray::operator=(const SortedRandomArray& a_other)
{
	m_size = a_other.m_size;
	delete[] m_data;
	m_data = new int[m_size];
	memcpy(m_data, a_other.m_data, m_size * sizeof(int));
	return *this;
}

SortedRandomArray& SortedRandomArray::operator=(SortedRandomArray&& a_other)
{
	m_size = a_other.m_size;
	delete[] m_data;
	m_data = a_other.m_data;
	return *this;
}