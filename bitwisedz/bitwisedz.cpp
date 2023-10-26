#include <iostream> 

char* from10to2(long long value)
{
	const int size = (sizeof(value) * 8 + (sizeof(value)));
	char* binary = new char[size];
	int check = 0;
	int iterations = -1;
	if (value >= 0) {
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
	}
	else
	{
		binary[0] = 49;
		value = -value;
		for (int i = size - 1; i >= 1; i--)
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
	}
	return binary;
}

long long from2to10(char* value)
{
	long long result = 0;
	const int size = (sizeof(result) * 8 + (sizeof(result)));
	for (int i = size - 2, power = 0; i >= 0; i--)
	{
		if (value[i] == ' ')
		{
			continue;
		}
		else if (value[i] == 48)
		{
			power++;
			continue;
		}
		else if (value[i] == 49)
		{
			if (i != 0)
			{
				result += (long long)pow(2, power);
				power++;
			}
			else
			{
				if (result == 0)
				{
					result -= (long long)pow(2, power);
				}
				else
				{
					result = -result;
				}
			}
		}
	}
	return result;
}

char* from10to2(long long value)
{
	const int size = (sizeof(value) * 8 + (sizeof(value)));
	char* binary = new char[size];
	int check = 0;
	int iterations = -1;
	if (value >= 0) {
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
	}
	else
	{
		binary[0] = 49;
		value = -value;
		for (int i = size - 1; i >= 1; i--)
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
	}
	return binary;
}

long long from2to10(char* value)
{
	long long result = 0;
	const int size = (sizeof(result) * 8 + (sizeof(result)));
	for (int i = size - 2, power = 0; i >= 0; i--)
	{
		if (value[i] == ' ')
		{
			continue;
		}
		else if (value[i] == 48)
		{
			power++;
			continue;
		}
		else if (value[i] == 49)
		{
			if (i != 0)
			{
				result += (long long)pow(2, power);
				power++;
			}
			else
			{
				if (result == 0)
				{
					result -= (long long)pow(2, power);
				}
				else
				{
					result = -result;
				}
			}
		}
	}
	return result;
}

int main()
{
	std::cout << '\n';

	long long number_in_dec = 23424233;
	std::cout << "Source decimal number: " << number_in_dec << '\n';
	char* result = from10to2(number_in_dec);
	std::cout << "Decimal number to binary: " << result << '\n';
	number_in_dec = from2to10(result);
	std::cout << "Binary number to decimal: " << number_in_dec;
	delete[] result;

	std::cout << '\n';
}
