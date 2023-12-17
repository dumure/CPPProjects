#pragma once
#include "Greater.h"
#include "Less.h"
#include <iostream>

class SortedRandomArray
{
	friend std::ostream& operator<<(std::ostream& a_os, SortedRandomArray& a_sra);
	int m_size;
	int* m_data;
public:
	~SortedRandomArray();
	SortedRandomArray(const SortedRandomArray& a_other);
	SortedRandomArray(SortedRandomArray&& a_other);
	SortedRandomArray(int a_size);
	void sort(Greater a_greater);
	void sort(Less a_less);
	SortedRandomArray& operator=(const SortedRandomArray& a_other);
	SortedRandomArray& operator=(SortedRandomArray&& a_other);
};

