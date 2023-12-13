#include "WordsDataBase.h"
#include <iostream>

void WordsDataBase::reallocate()
{
	if (words_capacity == words_count)
	{
		words_capacity += 5;
		std::string* new_words = new std::string[words_capacity]{};
		for (int i = 0; i < words_count; i++)
		{
			new_words[i] = words[i];
		}
		delete[] words;
		words = new_words;
	}
}

void WordsDataBase::serialize()
{
	std::ofstream file{ "words.txt" };
	if (file.is_open())
	{
		if (words_count > 0)
		{
			for (int i = 0; i < words_count; i++)
			{
				file << words[i] << '\n';
			}
		}
		else
		{
			file << "";
		}
		file.close();
	}
}

void WordsDataBase::deserialize()
{
	std::ifstream file{ "words.txt" };
	if (file.is_open())
	{
		int i = 0;
		while (!file.eof())
		{
			reallocate();
			file >> words[words_count];
			words_count++;
			i++;
		}
		if (i > 0)
		{
			words_count--;
		}
		file.close();
	}
}

WordsDataBase::~WordsDataBase()
{
	delete[] words;
}

WordsDataBase::WordsDataBase(const WordsDataBase& a_other)
{
	words_capacity = a_other.words_capacity;
	words_count = a_other.words_count;
	for (int i = 0; i < words_count; i++)
	{
		words[i] = a_other.words[i];
	}
}

WordsDataBase::WordsDataBase(WordsDataBase&& a_other)
{
	words_capacity = a_other.words_capacity;
	words_count = a_other.words_count;
	for (int i = 0; i < words_count; i++)
	{
		words[i] = a_other.words[i];
	}
	a_other.words = nullptr;
	a_other.words_capacity = 0;
	a_other.words_count = 0;
}

WordsDataBase::WordsDataBase()
{
	words_capacity = 5;
	words = new std::string[words_capacity];
	words_count = 0;
	deserialize();
}

void WordsDataBase::add_word(const std::string a_word)
{
	reallocate();
	words[words_count] = a_word;
	words_count++;
	serialize();
}

void WordsDataBase::remove_word(int index)
{
	if (index >= 0 && index <= words_count - 1)
	{
		words_count--;
		for (int i = index; i < words_count; i++)
		{
			words[i] = words[i + 1];
		}
	}
	serialize();
}

void WordsDataBase::remove_word(const std::string a_word)
{
	for (int i = 0; i < words_count; i++)
	{
		if (!words[i].compare(a_word))
		{
			remove_word(i);
			return;
		}
	}
}

void WordsDataBase::clear_words()
{
	words_count = 0;
	serialize();
}

int WordsDataBase::get_words_count()
{
	return words_count;
}

std::string& WordsDataBase::operator[](int index)
{
	return words[index];
}