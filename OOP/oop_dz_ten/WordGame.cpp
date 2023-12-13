#include "WordGame.h"

void WordGame::new_game(WordsDataBase& data_base)
{
	attempts = 0;
	word.choose_word(data_base);
	word.clear_guessed_letters();
	std::string s;
}

void WordGame::try_letter(char letter)
{
	if (word.compare_to_word(letter))
	{
		attempts++;
	}
}

int WordGame::win_check(const std::string& result_word)
{
	std::string hidden_word = word.get_source_word();
	if (result_word == hidden_word)
	{
		return attempts;
	}
	return 0;
}

std::string WordGame::get_result()
{
	std::string result;
	std::string hidden_word = word.get_source_word();
	std::string guessed_letters = word.get_guessed_letters();
	bool flag = true;
	for (int i = 0; i < hidden_word.length(); i++)
	{
		flag = true;
		for (int j = 0; j < guessed_letters.length(); j++)
		{
			if (hidden_word[i] == guessed_letters[j])
			{
				result += hidden_word[i];
				flag = false;
				break;
			}
		}
		if (flag)
		{
			result += '*';
		}
	}
	return result;
}

