#include <iostream>

class FixedIntArray
{
	int size;
	int* data;
public:
	~FixedIntArray()
	{
		delete[] data;
	}
	FixedIntArray(const FixedIntArray& a_other)
	{
		size = a_other.size;
		data = new int[size] {};
		memcpy(data, a_other.data, size * sizeof(int));
	}	
	FixedIntArray(FixedIntArray&& a_other)
	{
		size = a_other.size;
		data = new int[size] {};
		memcpy(data, a_other.data, size * sizeof(int));
		a_other.size = 0;
		a_other.data = nullptr;
	}
	FixedIntArray(int a_size)
	{
		size = a_size;
		data = new int[size] {};
	}
	int get_size()
	{
		return size;
	}
	FixedIntArray& operator=(const FixedIntArray& a_other)
	{
		delete[] data;
		size = a_other.size;
		data = new int[size] {};
		memcpy(data, a_other.data, size * sizeof(int));
		return *this;
	}
	FixedIntArray& operator=(FixedIntArray&& a_other)
	{
		delete[] data;
		size = a_other.size;
		data = new int[size] {};
		memcpy(data, a_other.data, size * sizeof(int));
		a_other.size = 0;
		a_other.data = nullptr;
		return *this;
	}
    int& operator[](int index)
	{
		return data[index];
	}
};

std::ostream& operator<<(std::ostream& a_os, FixedIntArray& a_fia)
{
	a_os << "{ ";
	int fia_size = a_fia.get_size();
	for (int i = 0; i < fia_size; i++)
	{
		if (i != fia_size - 1)
		{
			a_os << a_fia[i] << ", ";
		}
		else
		{
			a_os << a_fia[i];
		}
	}
	std::cout << " }\n";
	return a_os;
}

std::istream& operator>>(std::istream& a_is, FixedIntArray& a_fia)
{
	int fia_size = a_fia.get_size();
	for (int i = 0; i < fia_size; i++)
	{
		a_is >> a_fia[i];
	}
	return a_is;
}

int main()
{
	FixedIntArray fia{ 5 };
	std::cin >> fia;
	std::cout << fia;
}