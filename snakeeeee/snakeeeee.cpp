#include "Header.h"

void show_menu(int choice)
{
	if (choice == 0)
	{
		system("cls");
		std::cout << "******************************************\n";
		std::cout << "*                                        *\n";
		std::cout << "*               Main Menu                *\n";
		std::cout << "*                                        *\n";
		std::cout << "******************************************\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*            N   K      G   M            *\n";
		std::cout << "*           / \\ / \\      \\ / \\           *\n";
		std::cout << "*          S   A   E      A   E          *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*            [ L E V E L S ]             *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*         D E F A U L T   M O D E        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*          M I R R O R   M O D E         *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                 Q U I T                *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "******************************************";
	}
	else if (choice == 1)
	{
		system("cls");
		std::cout << "******************************************\n";
		std::cout << "*                                        *\n";
		std::cout << "*               Main Menu                *\n";
		std::cout << "*                                        *\n";
		std::cout << "******************************************\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*            N   K      G   M            *\n";
		std::cout << "*           / \\ / \\      \\ / \\           *\n";
		std::cout << "*          S   A   E      A   E          *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*              L E V E L S               *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*       [ D E F A U L T   M O D E ]      *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*          M I R R O R   M O D E         *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                 Q U I T                *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "******************************************";
	}
	else if (choice == 2)
	{
		system("cls");
		std::cout << "******************************************\n";
		std::cout << "*                                        *\n";
		std::cout << "*               Main Menu                *\n";
		std::cout << "*                                        *\n";
		std::cout << "******************************************\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*            N   K      G   M            *\n";
		std::cout << "*           / \\ / \\      \\ / \\           *\n";
		std::cout << "*          S   A   E      A   E          *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*              L E V E L S               *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*         D E F A U L T   M O D E        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*        [ M I R R O R   M O D E ]       *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                 Q U I T                *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "******************************************";
	}
	else if (choice == 3)
	{
		system("cls");
		std::cout << "******************************************\n";
		std::cout << "*                                        *\n";
		std::cout << "*               Main Menu                *\n";
		std::cout << "*                                        *\n";
		std::cout << "******************************************\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*            N   K      G   M            *\n";
		std::cout << "*           / \\ / \\      \\ / \\           *\n";
		std::cout << "*          S   A   E      A   E          *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*              L E V E L S               *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*         D E F A U L T   M O D E        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*          M I R R O R   M O D E         *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*               [ Q U I T ]              *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "*                                        *\n";
		std::cout << "******************************************";
	}
}

int main()
{
	int consoleWidth = GRID_WIDTH + 2;
	int consoleHeight = GRID_HEIGHT + 6;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD newSize;
	newSize.X = consoleWidth;
	newSize.Y = consoleHeight;

	SetConsoleScreenBufferSize(hConsole, newSize);

	SMALL_RECT sr;
	sr.Left = 0;
	sr.Top = 0;
	sr.Right = consoleWidth - 1;
	sr.Bottom = consoleHeight - 1;

	
	SetConsoleWindowInfo(hConsole, TRUE, &sr);
	
	while (true)
	{
		char key = 0;
		int choice = 0;
		show_menu(choice);
		while (key != 32)
		{
			if (_kbhit())
			{
				key = _getch();
			}
			switch (key)
			{
			case 'W':
			case 'w': choice--;if (choice < 0){choice = 3;} else if (choice > 3){choice = 0;} show_menu(choice); key = 0; break;
			case 'S':
			case 's': choice++;if (choice < 0){choice = 3;} else if (choice > 3){choice = 0;} show_menu(choice); key = 0; break;
			case 32: break;
			}
		}

		if (choice == 0)
		{
			levels();
		}
		else if (choice == 1)
		{
			default_mode();
		}
		else if (choice == 2)
		{
		
		}
		else if (choice == 3)
		{
			break;
		}
	}
}
