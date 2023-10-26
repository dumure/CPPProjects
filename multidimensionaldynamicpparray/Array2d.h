#pragma once
#include <iostream>

template<typename T>
struct Array
{
	T* data;
	int capacity;
	int size;
};

template<typename T>
struct Array2d
{
	Array<T>* data;
	int capacity;
	int size;
};

template<typename T>
Array<T> create()
{
	Array<T> arr;

	arr.capacity = 16;
	arr.data = new T[arr.capacity];
	arr.size = 0;

	return arr;
}

template<typename T>
Array2d<T> create_2d()
{
	Array2d<T> arr;

	arr.capacity = 16;
	arr.data = new Array<T>[arr.capacity];
	arr.size = 0;

	for (int i = 0; i < arr.capacity; i++)
	{
		arr.data[i] = create<T>();
	}

	return arr;
}

template<typename T>
void destroy(Array<T>& arr)
{
	delete arr.data;
}

template<typename T>
void destroy(Array2d<T>& arr)
{
	for (int i = 0; i < arr.capacity; i++)
	{
		delete[] arr.data[i].data;
	}
	delete[] arr.data;
}

template<typename T>
void reallocate(Array<T>& array)
{
	if (array.capacity == array.size)
	{
		array.capacity *= 2;

		T* new_data = new T[array.capacity];

		for (int i = 0; i < array.size; ++i)
		{
			new_data[i] = array.data[i];
		}

		delete[] array.data;

		array.data = new_data;
	}
}

template<typename T>
void reallocate(Array2d<T>& array)
{
	if (array.capacity == array.size)
	{
		array.capacity *= 2;

		Array<T>* new_data = new Array<T>[array.capacity];

		for (int i = 0; i < array.size; ++i)
		{
			new_data[i] = array.data[i];
		}

		for (int i = array.size; i < array.capacity; i++)
		{
			new_data[i] = create<T>();
		}

		delete[] array.data;

		array.data = new_data;
	}
}

template<typename T>
void move(Array<T>& from, Array<T>& to)
{
	to.size = 0;
	for (int i = 0; i < from.size; i++)
	{
		append(to, from.data[i]);
	}
	from.size = 0;
}

template<typename T>
void append(Array<T>& array, T value)
{
	reallocate(array);
	array.data[array.size] = value;
	++array.size;
}

template<typename T>
void prepend(Array<T>& array, T value)
{
	reallocate(array);
	for (int i = array.size; i >= 1; i--)
	{
		array.data[i] = array.data[i - 1];
	}
	array.data[0] = value;
	++array.size;
}

template<typename T>
void insert(Array<T>& array, T value, int index)
{
	reallocate(array);
	if (index < 0 || array.size == 0)
	{
		index = 0;
	}
	else if (index >= array.size)
	{
		index = array.size - 1;
	}
	for (int i = array.size; i >= index + 1; i--)
	{
		array.data[i] = array.data[i - 1];
	}
	array.data[index] = value;
	++array.size;
}

template<typename T>
void pop(Array<T>& array, int index = -1)
{
	--array.size;
	if (index != -1) {
		if (index < 0 || index > array.size)
		{
			index = 0;
		}
		for (; index < array.size; index++)
		{
			T temp = array.data[index];
			array.data[index] = array.data[index + 1];
			array.data[index + 1] = temp;
		}
	}
}

template<typename T>
void clear(Array<T>& array)
{
	array.size = 0;
}

template<typename T>
void clear(Array2d<T>& array)
{
	array.size = 0;
}

template<typename T>
void append_row(Array2d<T>& array, Array<T> row)
{
	reallocate(array);
	for (int i = 0; i < row.size; i++)
	{
		append(array.data[array.size], row.data[i]);
	}
	++array.size;
}

template<typename T>
void append_col(Array2d<T>& array, Array<T> col)
{
	for (; array.size < col.size; array.size++)
	{
		reallocate(array);
	}
	for (int i = 0; i < col.size; i++)
	{
		append(array.data[i], col.data[i]);
	}
}

template<typename T>
void prepend_row(Array2d<T>& array, Array<T> row)
{
	reallocate(array);
	for (int i = array.size; i >= 1; i--)
	{
		move(array.data[i - 1], array.data[i]);
		//array.data[i] = array.data[i - 1];
	}
	for (int i = 0; i < row.size; i++)
	{
		append(array.data[0], row.data[i]);
	}
	++array.size;
}

template<typename T>
void prepend_col(Array2d<T>& array, Array<T> col)
{
	for (; array.size < col.size; array.size++)
	{
		reallocate(array);
	}
	for (int i = 0; i < col.size; i++)
	{
		prepend(array.data[i], col.data[i]);
	}
}

template<typename T>
void insert_row(Array2d<T>& array, Array<T> row, int row_index)
{
	reallocate(array);
	for (int i = array.size; i >= row_index + 1; i--)
	{
		move(array.data[i - 1], array.data[i]);
	}
	for (int i = 0; i < row.size; i++)
	{
		append(array.data[row_index], row.data[i]);
	}
	++array.size;
}

template<typename T>
void insert_col(Array2d<T>& array, Array<T> col, int col_index)
{
	for (; array.size < col.size; array.size++)
	{
		reallocate(array);
	}
	for (int i = 0; i < col.size; i++)
	{
		insert(array.data[i], col.data[i], col_index);
	}
}

template<typename T>
void pop_row(Array2d<T>& array, int row_index = -1)
{
	--array.size;
	if (row_index != -1) {
		if (row_index < 0 || row_index > array.size)
		{
			row_index = 0;
		}
		for (; row_index < array.size; row_index++)
		{
			Array<T> temp_arr = create<T>();
			move(array.data[row_index], temp_arr);
			move(array.data[row_index + 1], array.data[row_index]);
			move(temp_arr, array.data[row_index + 1]);
			destroy(temp_arr);
		}
		array.data[array.size].size = 0;
	}
}

template<typename T>
void pop_col(Array2d<T>& array, int col_index)
{
	for (int i = 0; i < array.size; i++)
	{
		pop(array.data[i], col_index);
	}
}

template<typename T>
void print_array(Array<T> arr)
{
	if (arr.size == 0)
	{
		std::cout << "{}";

		return;
	}

	std::cout << "{ ";

	for (int i = 0; i < arr.size; ++i)
	{
		std::cout << arr.data[i];

		if (i != arr.size - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << " }";
}

template<typename T>
void print_array(Array2d<T> arr2d)
{
	std::cout << "{\n";
	for (int i = 0; i < arr2d.size; ++i)
	{
		std::cout << '\t';
		print_array(arr2d.data[i]);

		if (i != arr2d.size - 1)
		{
			std::cout << ',';
		}

		std::cout << '\n';
	}
	std::cout << "}\n";
}
