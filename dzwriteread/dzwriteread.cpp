#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

void write(int* buffer, int size)
{
    FILE* file = std::fopen("data.txt", "w");

    if (file != nullptr)
    {
        for (int i = 0; i < size; i++)
        {
            int value = buffer[i];

            if (value == 0)
            {
                std::fputc(value % 10 + 48, file);
            }
            else
            {
                int count = 0;

                int i = value;
                while (i >= 1)
                {
                    count++;
                    i /= 10;
                }

                while (value > 0)
                {
                    int number;
                    number = value / std::pow(10, count - 1);
                    std::fputc(number + 48, file);
                    value -= number * std::pow(10, count - 1);
                    count--;
                }
            }
            if (i != size - 1)
            {
                std::fputc('\n', file);
            }
        }

        std::fclose(file);
    }
}

int* read(int& size)
{
    FILE* file = std::fopen("data.txt", "r");


    if (file != nullptr)
    {
        std::fseek(file, 0, SEEK_END);
        int content_size = std::ftell(file);
        char* content = new char[content_size + 1];
        std::fseek(file, 0, SEEK_SET);

        for (int i = 0; i < content_size; i++)
        {
            content[i] = (char)std::fgetc(file);
        }
        content[content_size] = 0;

        for (int i = 0; i < content_size; i++)
        {
            if (content[i] == '\n')
            {
                size++;
            }
        }
        size++;

        std::fseek(file, 0, SEEK_SET);
        int* result = new int[size];
        for (int i = 0; i < size; i++)
        {
            char line[12]{};
            std::fscanf(file, "%s", line);
            int line_size = std::strlen(line);
            int value = 0;
            for (int i = 0,j = line_size-1; i < line_size; i++, j--)
            {
                value += (line[i] - 48) * std::pow(10, j);
            }
            result[i] = value;
        }

        std::fclose(file);

        delete[] content;

        return result;
    }
}

int main()
{
    constexpr int size = 23;
    int arr_to_write[size]{123,456,789,24234,4,23,4234,324,4,2434,3,42343,342,4,423,23,423,23,23,4,23,42,423};

    write(arr_to_write, size);

    int* arr_to_read{};
    int size_read = 0;

    arr_to_read = read(size_read);

    for (int i = 0; i < size_read; i++)
    {
        std::cout << arr_to_read[i] << '\n';
    }

    delete[] arr_to_read;
}
