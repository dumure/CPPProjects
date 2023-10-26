#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Metadata
{
	char data_type[12];
	int count;
};

int main()
{
	/*{
		FILE* file = std::fopen("data.bin", "wb");

		if (file == nullptr)
		{
			return -1;
		}

		int value = 12345;

		(void)std::fwrite(&value, sizeof(value), 1, file);

		(void)fclose(file);
	}

	{
		FILE* file = std::fopen("data.bin", "rb");

		if (file == nullptr)
		{
			return -1;
		}

		int value;

		(void)std::fread(&value, sizeof(value), 1, file);
		std::cout << value;

		(void)fclose(file);
	}*/

	//const int size = 4;

	/*{
		FILE* file = std::fopen("data.bin", "wb");

		if (file == nullptr)
		{
			return -1;
		}

		int* arr = new int[size] { 231, 738, 990, 623 };

		(void)std::fwrite(arr, sizeof(int), 4, file);

		delete[] arr;
		(void)fclose(file);
	}

	{
		FILE* file = std::fopen("data.bin", "rb");

		if (file == nullptr)
		{
			return -1;
		}
		
		int* arr = new int[size];

		(void)std::fread(arr, sizeof(int), size, file);
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << ' ';
		}

		delete[] arr;
		(void)fclose(file);
	}*/

	int size = 6;

	{
		FILE* file = std::fopen("data.bin", "wb");

		if (file == nullptr)
		{
			return -1;
		}

		Metadata meta {"double", size};
		double* arr = new double[size] {
				1343.14,
				212.223,
				321.311,
				43.43,
				531.52,
				62.608
			};

		(void)std::fwrite(&meta, sizeof(Metadata), 1, file);
		(void)std::fwrite(arr, sizeof(double), meta.count, file);

		delete[] arr;
		(void)fclose(file);
	}

	{
		FILE* file = std::fopen("data.bin", "rb");

		if (file == nullptr)
		{
			return -1;
		}

		Metadata meta;
		double* arr = new double[size];

		(void)std::fread(&meta, sizeof(Metadata), 1, file);

		std::cout << "Data type: " << meta.data_type << '\n';
		if (strcmp(meta.data_type, "double") == 0)
		{
			double* arr = new double[meta.count];

			(void)std::fread(arr, sizeof(double), meta.count, file);

			std::cout << "{ ";
			for (int i = 0; i < meta.count; i++)
			{
				std::cout << arr[i] << ", ";
			}
			std::cout << "\b\b }\n";

			delete[] arr;
		}

		
		(void)fclose(file);
	}
}
