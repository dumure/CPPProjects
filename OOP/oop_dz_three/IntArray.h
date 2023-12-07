#pragma once
class IntArray
{
	int m_size;
	int m_capacity;
	int* m_data;
	void reallocate();
public:
	~IntArray();
	IntArray();
	int get_size();
	int get_capacity();
	int get_data(int index);
	void append(int value);
	void prepend(int value);
	void bubble_sort(bool is_ascending = true);
	bool is_arr_empty();
};

