#pragma once
template<typename T>
class UniquePtr
{
	T* m_data;
public:
	~UniquePtr()
	{
		delete m_data;
	}
	UniquePtr(T* a_data)
	{
		m_data = a_data;
	}
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr(UniquePtr&& a_other)
	{
		m_data = a_other.m_data;
		a_other.m_data = nullptr;
	}
	T& operator*()
	{
		return *m_data;
	}
	T* operator->()
	{
		return m_data;
	}
	UniquePtr& operator=(const UniquePtr&) = delete;
	UniquePtr& operator=(UniquePtr&& a_other)
	{
		if (a_other == *this)
		{
			return *this;
		}
		this->~UniquePtr();
		m_data = a_other.m_data;
		a_other.m_data = nullptr;
		return *this;
	}
};

template<typename T>
class UniquePtr<T[]>
{
	T* m_data;
public:
	~UniquePtr()
	{
		delete[] m_data;
	}
	UniquePtr(T* a_data)
	{
		m_data = a_data;
	}
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr(UniquePtr&& a_other)
	{
		m_data = a_other.m_data;
		a_other.m_data = nullptr;
	}
	T& operator*()
	{
		return *m_data;
	}
	T* operator->()
	{
		return m_data;
	}
	T& operator[](int a_index)
	{
		return m_data[a_index];
	}
	UniquePtr& operator=(const UniquePtr&) = delete;
	UniquePtr& operator=(UniquePtr&& a_other)
	{
		if (a_other == *this)
		{
			return *this;
		}
		this->~UniquePtr();
		m_data = a_other.m_data;
		a_other.m_data = nullptr;
		return *this;
	}
};
