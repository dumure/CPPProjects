#pragma once
#include <iostream>

template<typename T>
class Queue
{
	template<typename T2> friend std::ostream& operator<<(std::ostream& a_os, const Queue<T2> a_queue);
	T* m_data;
	constexpr static int m_capacity = 1000;
	int m_size;
public:
	~Queue()
	{
		::operator delete[](m_data);
	}
	Queue(const Queue& a_other)
	{
		m_data = (T*)operator new[](m_capacity);
		memcpy(m_data, a_other.m_data, m_capacity);
		m_size = a_other.m_size;
	}
	Queue(Queue&& a_other)
	{
		m_data = a_other.m_data;
		m_size = a_other.m_size;
		a_other.m_data = nullptr;
		a_other.m_size = 0;
	}
	Queue()
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
		if (m_size == 0)
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
			m_size++;
			for (int i = m_size - 1; i > 0; i--)
			{
				m_data[i] = m_data[i - 1];
			}
			new (&(m_data[0])) T(a_value);
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
	Queue& operator=(const Queue& a_other)
	{
		::operator delete[](m_data);
		m_data = (T*)operator new[](m_capacity);
		memcpy(m_data, a_other.m_data, m_capacity);
		m_size = a_other.m_size;
		return *this;
	}
	Queue& operator=(Queue&& a_other)
	{
		::operator delete[](m_data);
		m_data = a_other.m_data;
		m_size = a_other.m_size;
		a_other.m_data = nullptr;
		a_other.m_size = 0;
		return *this;
	}
};

template<typename T2>
std::ostream& operator<<(std::ostream& a_os, const Queue<T2> a_Queue)
{
	std::cout << "{ ";
	for (int i = 0; i < a_Queue.m_size; i++)
	{
		std::cout << a_Queue.m_data[i];
		if (i != a_Queue.m_size - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " }\n";
	return a_os;
}
