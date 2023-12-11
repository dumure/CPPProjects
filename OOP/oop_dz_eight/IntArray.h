#pragma once
#include <iostream>

class IntArray
{
	friend std::ostream& operator<<(std::ostream& a_os, const IntArray& arr);
	friend std::istream& operator>>(std::istream& a_is, IntArray& a_arr);
	int m_size;
	int m_capacity;
	int* m_data;
	void reallocate();
public:
	~IntArray();
	IntArray(const IntArray& other);
	IntArray(IntArray&& other);
	IntArray();
	int get_size();
	int get_capacity();
	int get_data(int index);
	void append(int value);
	void prepend(int value);
	bool is_arr_empty();
	IntArray& operator=(const IntArray& other);
	IntArray& operator=(IntArray&& other);
	int& operator[](int index);
	IntArray operator+(const IntArray& other);
};

