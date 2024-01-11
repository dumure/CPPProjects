#pragma once
#include "Bucket.h"

template<typename T>
class HashSet
{
	template<typename F> friend std::ostream& operator<<(std::ostream& os, const HashSet<F>& a_hashset);
	int m_size;
	int m_capacity;
    std::hash<T> m_hash;
	Bucket<T>* m_buckets;
	void reallocate()
	{
		m_capacity *= 2;
		Bucket<T>* new_buckets = new Bucket<T>[m_capacity];
		for (int i = 0; i < m_capacity / 2; ++i)
		{
			for (int j = 0; j < m_buckets[i].get_size(); j++)
			{
				T& element = m_buckets[i].get_element(j);
				new_buckets[m_hash(element) % m_capacity].append(std::move(element));
			}
		}
		delete[] m_buckets;
		m_buckets = new_buckets;
	}
public:
	~HashSet()
	{
		delete[] m_buckets;
	}

	HashSet(const HashSet& a_other)
	{
		m_size = a_other.m_size;
		m_capacity = a_other.m_capacity;
		m_buckets = new Bucket<T>[m_capacity];
		memcpy(m_buckets, a_other.m_capacity, m_capacity * sizeof(Bucket<T>));
	}

	HashSet(HashSet&& a_other)
	{
		m_size = a_other.m_size;
		m_capacity = a_other.m_capacity;
		m_buckets = a_other.m_buckets;
		a_other.m_size = 0;
		a_other.m_capacity = 0;
		a_other.m_buckets = nullptr;
	}

	HashSet()
	{
		m_size = 0;
		m_capacity = 5;
		m_buckets = new Bucket<T>[m_capacity];
	}

	void add(const T& a_element)
	{
		if (get_load_factor() >= .75f)
		{
			reallocate();
		}
		++m_size;
		m_buckets[m_hash(a_element) % m_capacity].append(a_element);
	}

	void remove(const T& a_element)
	{
		--m_size;
		m_buckets[m_hash(a_element) % m_capacity].remove(a_element);
	}

	float get_load_factor()
	{
		return (float)(m_size) / m_capacity;
	}

	HashSet& operator=(const HashSet& a_other)
	{
		if (*this == a_other)
		{
			return *this;
		}
		delete[] m_buckets;
		m_size = a_other.m_size;
		m_capacity = a_other.m_capacity;
		m_buckets = new Bucket<T>[m_capacity];
		memcpy(m_buckets, a_other.m_capacity, m_capacity * sizeof(Bucket<T>));
		return *this;
	}

	HashSet& operator=(HashSet&& a_other)
	{
		if (*this == a_other)
		{
			return *this;
		}
		delete[] m_buckets; 
		m_size = a_other.m_size;
		m_capacity = a_other.m_capacity;
		m_buckets = a_other.m_buckets;
		a_other.m_size = 0;
		a_other.m_capacity = 0;
		a_other.m_buckets = nullptr;
		return *this;
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const HashSet<T>& a_hashset)
{
	os << "Buckets:\n";
	for (int i = 0; i < a_hashset.m_capacity; i++)
	{
		os << i + 1 << ". " << a_hashset.m_buckets[i];
	}
	return os;
}