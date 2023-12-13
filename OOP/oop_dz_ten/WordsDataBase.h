#pragma once
#include <fstream>

class WordsDataBase
{
	std::string* words;
	int words_count;
	int words_capacity;
	void reallocate();
	void serialize();
	void deserialize();
public:
	~WordsDataBase();
	WordsDataBase(const WordsDataBase& a_other);
	WordsDataBase(WordsDataBase&& a_other);
	WordsDataBase();
	void add_word(const std::string a_word);
	void remove_word(int index);
	void remove_word(const std::string a_word);
	void clear_words();
	int get_words_count();
	std::string& operator[](int index);
};

