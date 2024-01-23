#pragma once
template<typename T>
class SharedPtr
{
	T* m_data;
	int* m_counter;
public:
	~SharedPtr()
	{
		if (*m_counter == 1)
		{
			delete m_data;
			delete m_counter;
		}
		--(*m_counter);
	}
	SharedPtr(T* a_data)
	{
		m_data = a_data;
		m_counter = new int{ 1 };
	}
	SharedPtr(const SharedPtr& a_other)
	{
		m_data = a_other.m_data;
		++(*a_other.m_counter);
		m_counter = a_other.m_counter;
	}
	SharedPtr(SharedPtr&& a_other)
	{
		m_data = a_other.m_data;
		m_counter = a_other.m_counter;
		a_other.m_data = nullptr;
		a_other.m_counter = nullptr;
	}
	int& use_count()
	{
		return *m_counter;
	}
	T& operator*()
	{
		return *m_data;
	}
	T* operator->()
	{
		return m_data;
	}
	SharedPtr& operator=(const SharedPtr& a_other)
	{
		if (a_other == *this)
		{
			return *this;
		}
		this->~SharedPtr();
		m_data = a_other.m_data;
		++(*a_other.m_counter);
		m_counter = a_other.m_counter;
		return *this;
	}
	SharedPtr& operator=(SharedPtr&& a_other)
	{
		if (a_other == *this)
		{
			return *this;
		}
		this->~SharedPtr();
		m_data = a_other.m_data;
		m_counter = a_other.m_counter;
		a_other.m_data = nullptr;
		a_other.m_counter = nullptr;
		return *this;
	}
};
