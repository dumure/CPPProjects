#pragma once
#include <iostream>

template<typename K, typename V>
class Dictionary
{
    int m_size;
    int m_capacity;
    void** m_data;
    void reallocate()
    {
        if (m_size == m_capacity)
        {
            m_capacity += 10;
            void** new_data = new void*[m_capacity] {};
            for (int i = m_size; i < m_capacity; i++)
            {
                if (i % 2 == 0)
                {
                    new_data[i] = new K;
                }
                else
                {
                    new_data[i] = new V;
                }
            }
            for (int i = 0; i < m_size; i++)
            {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
        }
    }
public:
    ~Dictionary()
    {
        for (int i = 0; i < m_capacity; i++)
        {
            if (i % 2 == 0)
            {
                delete (K*)m_data[i];
            }
            else
            {
                delete (V*)m_data[i];
            }
        }
        delete[] m_data;
    }
    Dictionary(const Dictionary& a_other)
    {
        m_size = a_other.m_size;
        m_capacity = a_other.m_capacity;
        m_data = new void*[m_capacity];
        for (int i = 0; i < m_capacity; i++)
        {
            if (i % 2 == 0)
            {
                m_data[i] = new K;
            }
            else
            {
                m_data[i] = new V;
            }
        }
        for (int i = 0; i < m_capacity; i++)
        {
            m_data[i] = a_other.m_data[i];
        }
    }
    Dictionary(Dictionary&& a_other)
    {
        m_size = a_other.m_size;
        m_capacity = a_other.m_capacity;
        m_data = a_other.m_data;
        a_other.m_capacity = 0;
        a_other.m_size = 0;
        a_other.m_data = nullptr;
    }
    Dictionary(int a_capacity = 10)
    {
        m_size = 0;
        m_capacity = a_capacity;
        m_data = new void* [m_capacity];
        for (int i = 0; i < m_capacity; i++)
        {
            if (i % 2 == 0)
            {
                m_data[i] = new K;
            }
            else
            {
                m_data[i] = new V;
            }
        }
    }
    Dictionary& operator=(const Dictionary& a_other)
    {
        m_size = a_other.m_size;
        m_capacity = a_other.m_capacity;
        for (int i = 0; i < m_capacity; i++)
        {
            delete m_data[i];
        }
        delete[] m_data;
        m_data = new void* [m_capacity];
        for (int i = 0; i < m_capacity; i++)
        {
            if (i % 2 == 0)
            {
                m_data[i] = new K;
            }
            else
            {
                m_data[i] = new V;
            }
        }
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = a_other.m_data[i];
        }
        return *this;
    }
    Dictionary& operator=(Dictionary&& a_other)
    {
        m_size = a_other.m_size;
        m_capacity = a_other.m_capacity;
        for (int i = 0; i < m_capacity; i++)
        {
            delete m_data[i];
        }
        delete[] m_data;
        m_data = a_other.m_data;
        a_other.m_capacity = 0;
        a_other.m_size = 0;
        a_other.m_data = nullptr;
        return *this;
    }
    V& operator[](const K& key)
    {
        for (int i = 0; i < m_size; i += 2)
        {
            if (*(K*)m_data[i] == key)
            {
                return *(V*)m_data[i + 1];
            }
        }
        reallocate();
        *(K*)m_data[m_size] = key;
        m_size += 2;
        return *(V*)m_data[m_size-1];
    }
};

