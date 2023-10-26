#pragma once
#include "String.h"

template<typename T = char>
struct Arr
{
	Str<T>* data;
	int capacity;
	int size;
};

template<typename T = char>
Arr<T> arr_create()
{
	Arr<T> arr;

	arr.capacity = 16;
	arr.data = new Str<T>[arr.capacity];
	for (int i = 0; i < arr.capacity; i++)
	{
		arr.data[i] = str_create<>();
	}
	arr.size = 0;

	return arr;
}

template<typename T = char>
void arr_destroy(Arr<T>& arr)
{
	for (int i = 0; i < arr.capacity; i++)
	{
		str_destroy(arr.data[i]);
	}
	delete[] arr.data;
}

template<typename T = char>
void arr_reallocate(Arr<T>& arr)
{
	if (arr.size == arr.capacity)
	{
		arr.capacity *= 2;

		Str<T>* new_data = new Str<T>[arr.capacity];

		for (int i = 0; i < arr.size; i++)
		{
			new_data[i] = arr.data[i];
		}

		for (int i = arr.size; i < arr.capacity; i++)
		{
			new_data[i] = str_create<>();
		}

		delete[] arr.data;

		arr.data = new_data;
	}
}

template<typename T = char>
void arr_append(Arr<T>& arr, Str<T> source)
{
	arr_reallocate(arr);
	for (int i = 0; i < source.size; i++)
	{
		str_append(arr.data[arr.size], source.data[i]);
	}
	++arr.size;
}

template<typename T = char>
Arr<T> split(Str<T>& str, const T* delimiter)
{
	Str<T> check_str = str_create<T>();
	Str<T> temp_str = str_create<T>();
	Arr<T> result = arr_create<T>();
	for (int i = 0; i < str.size + 1; i++)
	{
		for (int j = i; j < str_len(delimiter) + i; j++)
		{
			str_append(check_str, str.data[j]);
		}
		if (str_cmp(check_str, delimiter) || i == str.size)
		{
			arr_append(result, temp_str);
			i = i + str_len(delimiter) - 1;
			str_clear(temp_str);
		}
		else
		{
			str_append(temp_str, str.data[i]);
		}
		str_clear(check_str);
	}
	str_destroy(temp_str);
	str_destroy(check_str);
	return result;
}

template<typename T = char>
Arr<T> split(Str<T>& str, Str<T> delimiter)
{
	Str<T> check_str = str_create<T>();
	Str<T> temp_str = str_create<T>();
	Arr<T> result = arr_create<T>();
	for (int i = 0; i < str.size + 1; i++)
	{
		for (int j = i; j < str_len(delimiter) + i; j++)
		{
			str_append(check_str, str.data[j]);
		}
		if (str_cmp(check_str, delimiter) || i == str.size)
		{
			arr_append(result, temp_str);
			i = i + str_len(delimiter) - 1;
			str_clear(temp_str);
		}
		else
		{
			str_append(temp_str, str.data[i]);
		}
		str_clear(check_str);
	}
	str_destroy(temp_str);
	str_destroy(check_str);
	return result;
}

template<typename T>
Str<T> join(Arr<T> arr, Str<T> joiner)
{
	Str<T> result = str_create<T>();
	int sizeee = 0;
	for (int i = 0; i < arr.size; i++)
	{
		str_append(result, arr.data[i]);
		sizeee += str_len(arr.data[i]);
		if (i != arr.size - 1)
		{
			str_append(result, joiner);
			sizeee += str_len(joiner);
		}
	}
	return result;
}

template<typename T = char>
void arr_print(Arr<T> arr, char end = '\0')
{
	std::cout << "{ ";
	for (int i = 0; i < arr.size; i++)
	{
		std::cout << '"';
		str_print(arr.data[i]);
		std::cout << '"';
		std::cout << ", ";
	}
	std::cout << "\b\b }" << end;
}