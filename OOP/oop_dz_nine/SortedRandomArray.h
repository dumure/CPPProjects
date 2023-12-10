#pragma once
class SortedRandomArray
{
	int m_size;
	int* m_data;
public:
	~SortedRandomArray();
	SortedRandomArray(const SortedRandomArray& a_other);
	SortedRandomArray(SortedRandomArray&& a_other);
	SortedRandomArray(int a_size);
};

