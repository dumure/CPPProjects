#pragma once
#include <iostream>

template<typename T>
class Queue
{
	template<typename T2> friend std::ostream& operator<<(std::ostream& a_os, const Queue<T2> a_Queue);
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
	T& peek()
	{
		return m_data[m_size - 1];
	}
	T& dequeue()
	{
		T value = m_data[m_size - 1];
		m_data[m_size - 1].~T();
		--m_size;
		return value;
	}
	void enqueue(const T& a_value)
	{
		if ((m_size + 1) * sizeof(T) <= m_capacity)
		{
			T* p = new (&(m_data[m_size])) T(a_value);
			m_size++;
		}
	}
	int size()
	{
		return m_size;
	}
	void swap(Queue&& a_other)
	{
		T* temp_data = m_data;
		m_data = a_other.m_data;
		a_other.m_data = temp_data;
		int temp_size = m_size;
		m_size = a_other.m_size;
		a_other.m_size = temp_size;
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
