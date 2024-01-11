#pragma once
#include <iostream>

template<typename T>
class Bucket
{
	template<typename T2> friend std::ostream& operator<<(std::ostream&, const Bucket<T2>& a_bucket);
	int m_capacity;
	int m_size;
	T* m_data;
	void reallocate()
	{
		if (m_size == m_capacity)
		{
			m_capacity += 16;
			T* new_data = new T[m_capacity]{};
			for (int i = 0; i < m_size; ++i)
			{
				new_data[i] = m_data[i];
			}
			delete[] m_data;
			m_data = new_data;
		}
	}
public:
	~Bucket()
	{
		delete[] m_data;
	}
	Bucket(const Bucket& a_other)
	{
		m_capacity = a_other.m_capacity;
		m_size = a_other.m_size;
		m_data = new T[m_capacity];
		memcpy(m_data, a_other.m_data, sizeof(T) * m_capacity);
	}
	Bucket(Bucket&& a_other) noexcept
	{
		m_capacity = a_other.m_capacity;
		m_size = a_other.m_size;
		m_data = a_other.m_data;
		memcpy(m_data, a_other.m_data, sizeof(T) * m_capacity);
		a_other.m_capacity = 0;
		a_other.m_size = 0;
		a_other.m_data = nullptr;
	}
	Bucket(int a_capacity = 16)
	{
		m_capacity = a_capacity;
		m_size = 0;
		m_data = new T[m_capacity];
	}
	int get_size()
	{
		return m_size;
	}
	T& get_element(int a_index)
	{
		return m_data[a_index];
	}
	void append(const T& a_value)
	{
		reallocate();
		m_data[m_size] = a_value;
		++m_size;
	}
	void append(T&& a_value)
	{
		reallocate();
		m_data[m_size] = std::move(a_value);
		++m_size;
	}
	void remove(const T& a_value)
	{
		int index;
		for (int i = 0; i < m_size; i++)
		{
			if (m_data[i] == a_value)
			{
				index = i;
				break;
			}
		}
		for (int i = index; i < m_size; i++)
		{
			T temp = m_data[i];
			m_data[i] = m_data[i + 1];
			m_data[i + 1] = temp;
		}
		--m_size;
	}
	Bucket& operator=(const Bucket& a_other)
	{
		if (*this == a_other)
		{
			return *this;
		}
		m_capacity = a_other.m_capacity;
		m_size = a_other.m_size;
		delete[] m_data;
		m_data = new T[m_capacity];
		memcpy(m_data, a_other.m_data, sizeof(T) * m_capacity);
		return *this;
	}
	Bucket& operator=(Bucket&& a_other) noexcept
	{
		if (*this == a_other)
		{
			return *this;
		}
		m_capacity = a_other.m_capacity;
		m_size = a_other.m_size;
		delete[] m_data;
		m_data = a_other.m_data;
		a_other.m_capacity = 0;
		a_other.m_size = 0;
		a_other.m_data = nullptr;
		return *this;
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Bucket<T>& a_bucket)
{
	os << "{ ";
	for (int i = 0; i < a_bucket.m_size; i++)
	{
		os << a_bucket.m_data[i];
		if (i != a_bucket.m_size - 1)
		{
			os << ", ";
		}
	}
	os << " }\n";
	return os;
}