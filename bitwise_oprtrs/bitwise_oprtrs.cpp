#include <iostream> 

char* from10to2(long long value)
{
	const int size = (sizeof(value) * 8 + (sizeof(value)));
	char* binary = new char[size];
	int check = 0;
	int iterations = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (i == size - 1)
		{
			binary[i] = 0;
		}
		else if (iterations == 8 && i != 0)
		{
			iterations = -1;
			binary[i] = ' ';
		}
		else if (value > 1)
		{
			binary[i] = char(value % 2 + 48);
			value /= 2;
		}
		else if (check == 0)
		{
			binary[i] = char(value + 48);
			check++;
		}
		else
		{
			binary[i] = char(48);
		}
		iterations++;
	}
	return binary;
}

long long from2to10(char* value)
{
	long long result = 0;
	const int size = (sizeof(result) * 8 + (sizeof(result)));
	for (int i = size-1; i >= 0; i--)
	{
		if (value[i] == ' ')
		{

		}
	}
}

int main()
{
	long long number_in_dec = 123L;
	char* result = from10to2(number_in_dec);
	std::cout << result;
	delete[] result;
}
