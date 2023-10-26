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
	long long decimal = 0;
	const int size = (sizeof(decimal) * 8 + (sizeof(decimal)));
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
				decimal += (long long)pow(2, power);
				power++;
			}
			else
			{
				if (decimal == 0)
				{
					decimal -= (long long)pow(2, power);
				}
				else
				{
					decimal = -decimal;
				}
			}
		}
	}
	return decimal;
}

char* encrypt(char* text, int shift)
{
	int size = strlen(text) + 1;
	char* caesar = new char[size];
	for (int i = 0; i < size; i++)
	{
		if (text[i] >= 65 && text[i] <= 90 && shift != 0)
		{
			if (shift > 0)
			{
				caesar[i] = (text[i] + shift > 90) ? text[i] + shift - 26 : text[i] + shift;
			}
			else
			{
				caesar[i] = (text[i] + shift < 65) ? text[i] + shift + 26 : text[i] + shift;
			}
		}
		else if (text[i] >= 97 && text[i] <= 122 && shift != 0)
		{
			if (shift > 0)
			{
				caesar[i] = (text[i] + shift > 122) ? text[i] + shift - 26 : text[i] + shift;
			}
			else
			{
				caesar[i] = (text[i] + shift < 97) ? text[i] + shift + 26 : text[i] + shift;
			}
		}
		else
		{
			caesar[i] = text[i];
		}
	}
	return caesar;
}

char* decrypt(char* text, int shift)
{
	return encrypt(text, -shift);
}

int main()
{
	{
		std::cout << '\n';

		long long number_in_dec = 23424233;
		std::cout << "Source decimal number: " << number_in_dec << '\n';
		char* result = from10to2(number_in_dec);
		std::cout << "Decimal number to binary: " << result << '\n';
		number_in_dec = from2to10(result);
		std::cout << "Binary number to decimal: " << number_in_dec << '\n';
		delete[] result;

		std::cout << '\n';
	}
	std::cout << "------------------" << '\n';
	{
		std::cout << '\n';

		int shifts_count = -3;
		char* text = new char[32] {"Hello, my name is C++!"};
		std::cout << "Source text: " << text << '\n';
		char* encrypted_text = encrypt(text, shifts_count);
		std::cout << "Encrypted text: " << encrypted_text << '\n';
		char* decrypted_text = decrypt(encrypted_text, shifts_count);
		std::cout << "Decrypted text: " << decrypted_text << '\n';
		delete[] encrypted_text;
		delete[] decrypted_text;
		delete[] text;

		
		std::cout << '\n';
	}
}
