#pragma once
#include "HiddenWord.h"
#include <iostream>

class WordGame
{
	int attempts;
	HiddenWord word;
public:
	void new_game(WordsDataBase& data_base);
	void try_letter(char letter);
	int win_check(const std::string& result_word);
	std::string get_result();
};

