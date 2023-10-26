#include <iostream>
#include <Windows.h>

void reallocate(char**& data, int& capacity, int size)
{
    if (size == capacity)
    {
        capacity *= 2;

        char** new_data = new char* [capacity];

        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }

        for (int i = 0; i < size; i++)
        {
            delete[] data[i];
        }

        delete[] data;
        data = new_data;
    }
}

void add_word(char**& russian_data, char**& english_data, int& size, int& capacity)
{
    reallocate(russian_data, capacity, size);
    
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int capacity = 16;
    int size = 0;
    char** russian_data = new char* [capacity];
    char** english_data = new char* [capacity];

    std::cout << "\nДобро пожаловать в переводчик! Для начала выберите язык интерфейса:"
              << "\nWelcome to translator! At once choose the interface language:"
              << "\n1 - Русский\n2 - English\n\n";
    char choice[64];
    std::cin.getline(choice, 64);
    std::cout << choice;
}

