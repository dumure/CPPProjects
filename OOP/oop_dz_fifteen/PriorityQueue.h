#pragma once
#include <iostream>
#include "Functors.h"

template<typename T, typename F>
class PriorityQueue
{
	template<typename T2, typename T3> friend std::ostream& operator<<(std::ostream& a_os, const PriorityQueue<T2, T3> a_priority_queue);
	T* m_data;
	constexpr static int m_capacity = 100;
	int m_size;
	F m_functor;
public:
	~PriorityQueue()
	{
		::operator delete[](m_data);
	}
	PriorityQueue(const PriorityQueue& a_other)
	{
		m_data = (T*)operator new[](m_capacity);
		memcpy(m_data, a_other.m_data, m_capacity);
		m_size = a_other.m_size;
	}
	PriorityQueue(PriorityQueue&& a_other)
	{
		m_data = a_other.m_data;
		m_size = a_other.m_size;
		a_other.m_data = nullptr;
		a_other.m_size = 0;
	}
	PriorityQueue()
	{
		m_data = (T*)operator new[](m_capacity);
		m_size = 0;
	}
	const T& front()
	{
		return m_data[0];
	}
	const T& back()
	{
		return m_data[m_size - 1];
	}
	const T& pop()
	{
		if (m_size != 0)
		{
			T value = m_data[0];
			--m_size;
			for (int i = 0; i < m_size; i++)
			{
				T temp = m_data[i];
				m_data[i] = m_data[i + 1];
				m_data[i + 1] = temp;
			}
			m_data[0].~T();
			return value;
		}
	}
	void push(const T& a_value)
	{
		if ((m_size + 1) * sizeof(T) <= m_capacity)
		{
			int index = m_size;
			for (int i = 0; i < m_size; i++)
			{
				if (!m_functor(a_value, m_data[i]))
				{
					index = i;
					break;
				}
			}
			m_size++;
			for (int i = m_size - 1; i > index; i--)
			{
				m_data[i] = m_data[i - 1];
			}
			new (&(m_data[index])) T(a_value);
		}
	}
	int count()
	{
		return m_size;
	}
	bool empty()
	{
		return m_size == 0;
	}
	PriorityQueue& operator=(const PriorityQueue& a_other)
	{
		::operator delete[](m_data);
		m_data = (T*)operator new[](m_capacity);
		memcpy(m_data, a_other.m_data, m_capacity);
		m_size = a_other.m_size;
		return *this;
	}
	PriorityQueue& operator=(PriorityQueue&& a_other)
	{
		::operator delete[](m_data);
		m_data = a_other.m_data;
		m_size = a_other.m_size;
		a_other.m_data = nullptr;
		a_other.m_size = 0;
		return *this;
	}
};

template<typename T2, typename T3>
std::ostream& operator<<(std::ostream& a_os, const PriorityQueue<T2, T3> a_priority_queue)
{
	std::cout << "{ ";
	for (int i = 0; i < a_priority_queue.m_size; i++)
	{
		std::cout << a_priority_queue.m_data[i];
		if (i != a_priority_queue.m_size - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " }\n";
	return a_os;
}
