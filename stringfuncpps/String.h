#pragma once
#include <iostream>

template<typename T = char>
struct Str
{
    T* data;
    int capacity;
    int size;
};

template<typename T = char>
Str<T> str_create()
{
    Str<T> str;

    str.capacity = 16;
    str.data = new T[str.capacity]{};
    str.size = 0;

    return str;
}

template<typename T = char>
void str_destroy(Str<T> str)
{
    delete[] str.data;
}

template <typename T = char>
void reallocate(Str<T>& str)
{
    if (str.capacity == str.size)
    {
        str.capacity *= 2;

        T* new_data = new T[str.capacity]{};

        for (int i = 0; i < str.size; ++i)
        {
            new_data[i] = str.data[i];
        }

        delete[] str.data;

        str.data = new_data;
    }
}

template<typename T = char>
int str_len(Str<T> str)
{
    return str.size;
}

template<typename T>
int str_len(const T* str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        ++i;
    }
    return i;
}

template<typename T = char>
void str_append(Str<T>& str, T source)
{
    reallocate(str);
    str.data[str.size] = source;
    ++str.size;
}

template<typename T = char>
void str_append(Str<T>& str, const T* source)
{
    for (int i = 0; i < str_len(source); ++i)
    {
        str_append(str, source[i]);
    }
}

template<typename T = char>
void str_append(Str<T>& str, Str<T>& source)
{
    for (int i = 0; i < str_len(source); ++i)
    {
        str_append(str, source.data[i]);
    }
}

template<typename T = char>
void str_remove(Str<T>& str, int index)
{
    --str.size;
    for (int i = index; i < str.size; ++i)
    {
        T temp = str.data[i];
        str.data[i] = str.data[i + 1];
        str.data[i + 1] = temp;
    }
}

template<typename T = char>
void str_remove(Str<T>& str, T symbol, int count = -1)
{
    if (count == -1)
    {
        for (int i = 0; i < str.size; ++i)
        {
            if (str.data[i] == symbol)
            {
                str_remove(str, i);
                --i;
            }
        }
    }
    else
    {
        for (int i = 0; i < str.size; ++i)
        {
            if (count == 0)
            {
                break;
            }
            if (str.data[i] == symbol)
            {
                str_remove(str, i);
                --i;
                --count;
            }
        }
    }
}

template<typename T = char>
void str_remove(Str<T>& str, int index, int size)
{
    for (int i = 0; i < size; i++)
    {
        str_remove(str, index);
    }
}

template<typename T>
void str_insert(Str<T>& str, int index, T symbol)
{
    reallocate(str);

    for (int i = str.size; i >= index + 1; --i) {
        str.data[i] = str.data[i - 1];
    }
    str.data[index] = symbol;

    ++str.size;
}

template<typename T>
void str_insert(Str<T>& str, int index, const T* source)
{
    for (int i = 0; i < str_len(source); i++)
    {
        str_insert(str, i + index, source[i]);
    }
}

template<typename T>
void str_insert(Str<T>& str, int index, Str<T> source)
{
    for (int i = 0; i < source.size; i++)
    {
        str_insert(str, i + index, source.data[i]);
    }
}


template<typename T = char>
int str_find(Str<T> str, T symbol)
{
    for (int i = 0; i < str.size; ++i)
    {
        if (str.data[i] == symbol)
        {
            return i;
        }
    }
    return -1;
}

template<typename T>
void str_count(Str<T> str, int& ltr, int& dgt, int& oth)
{
    for (int i = 0; i < str.size; ++i)
    {
        if (str.data[i] >= 65 && str.data[i] <= 90 || str.data[i] >= 97 && str.data[i] <= 122)
        {
            ++ltr;
        }
    }
    for (int i = 0; i < str.size; ++i)
    {
        if (str.data[i] >= 48 && str.data[i] <= 57)
        {
            ++dgt;
        }
    }
    oth = str_len(str) - ltr - dgt;
}

template<typename T = char>
void str_clear(Str<T>& str)
{
    str.size = 0;
}

template<typename T>
bool str_cmp(Str<T> str1, Str<T> str2)
{
    if (str1.size != str2.size)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < str1.size; i++)
        {
            if (!(str1.data[i] == str2.data[i]))
            {
                return false;
            }
        }
        return true;
    }
}

template<typename T>
bool str_cmp(Str<T> str1, const T* str2)
{
    if (str1.size != str_len(str2))
    {
        return false;
    }
    else
    {
        for (int i = 0; i < str1.size; i++)
        {
            if (!(str1.data[i] == str2[i]))
            {
                return false;
            }
        }
        return true;
    }
}

template<typename T>
void replace(Str<T>& str, const T* what, const T* to)
{
    Str<T> check_str = str_create<T>();
    for (int i = 0; i < str.size + 1 - str_len(what); i++)
    {
        int j = i;
        for (; j < str_len(what) + i; j++)
        {
            str_append(check_str, str.data[j]);
        }
        if (str_cmp(check_str, what))
        {
            int k = j - str_len(what);
            str_remove(str, k, str_len(what));
            str_insert(str, k, to);
        }
        str_clear(check_str);
    }
    str_destroy(check_str);
}

template<typename T>
void replace(Str<T>& str, Str<T> what, Str<T> to)
{
    Str<T> check_str = str_create<T>();
    for (int i = 0; i < str.size + 1 - str_len(what); i++)
    {
        int j = i;
        for (; j < str_len(what) + i; j++)
        {
            str_append(check_str, str.data[j]);
        }
        if (str_cmp(check_str, what))
        {
            int k = j - str_len(what);
            str_remove(str, k, str_len(what));
            str_insert(str, k, to);
        }
        str_clear(check_str);
    }
    str_destroy(check_str);
}

template<typename T>
void str_print(Str<T>& str, char end = '\0')
{
    for (int i = 0; i < str.size; ++i)
    {
        std::cout << str.data[i];
    }
    std::cout << end;
}

