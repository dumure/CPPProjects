#include "HiddenWord.h"
#include <iostream>
#include <fstream>

void HiddenWord::choose_word(WordsDataBase& data_base)
{
	srand(time(0));
	source_word = data_base[rand() % data_base.get_words_count()];
}

void HiddenWord::clear_guessed_letters()
{
	guessed_letters.clear();
}

bool HiddenWord::compare_to_word(char letter)
{
	for (int i = 0; i < tried_letters.length(); i++)
	{
		if (tried_letters[i] == letter)
		{
			return false;
		}
	}
	tried_letters += letter;
	for (int i = 0; i < source_word.length(); i++)
	{
		if (source_word[i] == letter)
		{
			guessed_letters += letter;
			return true;
		}
	}
	return true;
}

std::string HiddenWord::get_source_word()
{
	return source_word;
}

std::string HiddenWord::get_guessed_letters()
{
	return guessed_letters;
}