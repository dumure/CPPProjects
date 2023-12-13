#include <iostream>
#include "WordGame.h"

int main()
{
	{
		WordsDataBase database;
		database.clear_words();
		database.add_word("apple");
		database.add_word("cucumber");
		database.add_word("delegate");

		WordGame game;
		game.new_game(database);
		std::string result;
		int attempts = 0;
		char letter;
		while (!attempts)
		{
			std::cout << "Enter letter:\n >>> ";
			std::cin >> letter;
			game.try_letter(letter);
			result = game.get_result();
			std::cout << result << '\n';
			attempts = game.win_check(result);
		}
		std::cout << "You won by " << attempts << " attempts!" << '\n';
	}
	{
		std::string word = "pinapple";
		std::string player_word;
		int attempts = 0;
		bool flag = true;
		while (word != player_word)
		{
			std::cout << "Try to guess word (0 for stop):\n >>> ";
			std::cin >> player_word;
			if (player_word == "0")
			{
				flag = false;
				break;
			}
			if (attempts > 5 && attempts <= 10)
			{
				std::cout << "It's a fruit!\n";
			}
			if (attempts > 10 && attempts <= 15)
			{
				std::cout << "This fruit has a cool hairstyle!\n";
			}
			else if (attempts > 15 && attempts <= 20)
			{
				std::cout << "PPAP it's song about pen, apple and our guessed word!\n";
			}
			else if (attempts > 20)
			{
				std::cout << "Where does SpongeBob live?\n";
			}
			attempts++;
		}
		if (flag)
		{
			std::cout << "Congratulations! You win!!!";
		}
	}
}
