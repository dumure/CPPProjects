#pragma once
#include <string>
#include "WordsDataBase.h"

class HiddenWord
{
	friend class WordsDataBase;
	std::string source_word;
	std::string guessed_letters;
	std::string tried_letters;
public:
	void choose_word(WordsDataBase& data_base);
	void clear_guessed_letters();
	bool compare_to_word(char letter);
	std::string get_source_word();
	std::string get_guessed_letters();
};