#include "HiddenWord.h"
#include <iostream>
#include <fstream>

HiddenWord::HiddenWord()
{
	srand(time(0));
	std::fstream file{"words.txt", std::ios::in};

	if (file.is_open())
	{
		int lines_count = 0;
		while (!file.eof())
		{
			file >> source_word;
			lines_count++;
		}
		file.seekg(0);
		int random_number = rand() % lines_count;
		char symbol;
		for (int i = 0; i < random_number; i++)
		{
			file >> source_word;
		}
		file >> source_word;

		file.close();
	}

	std::cout << source_word;
}