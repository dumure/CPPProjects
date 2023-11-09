#include "Header.h"

void insert_objects(Array2d<int>& grid, Array<int> snake, int* apple)
{
	clear_grid(grid, 0);
	for (int i = 0; i < snake.size; i += 2)
	{
		grid.data[snake.data[i]].data[snake.data[i + 1]] = 1;
	}
	grid.data[apple[0]].data[apple[1]] = 2;
}

void print_grid(Array2d<int> arr2d, int score)
{
	system("cls");
	int iterations = 0;
	for (int i = score; i > 0; i /= 10)
	{
		iterations++;
	}
	for (int i = 0; i < GRID_WIDTH+2; i++)
	{
		std::cout << '*';
	}
	std::cout << '\n';
	std::cout << '*';
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		std::cout << ' ';
	}
	std::cout << '*';
	std::cout << '\n';
	std::cout << "*   ";
	std::cout << "Score: " << score;
	for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 23 : GRID_WIDTH - 22 - iterations); i++)
	{
		std::cout << ' ';
	}
	std::cout << "L - Leave   ";
	std::cout << '*';
	std::cout << '\n';
	std::cout << '*';
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		std::cout << ' ';
	}
	std::cout << '*';
	std::cout << '\n';
	for (int i = 0; i < GRID_WIDTH + 2; i++)
	{
		std::cout << '*';
	}
	std::cout << '\n';
	for (int i = 0; i < GRID_HEIGHT; i++)
	{
		std::cout << '*';
		for (int j = 0; j < GRID_WIDTH; j++)
		{

			switch (arr2d.data[i].data[j])
			{
			case 0: std::cout << ' '; break;
			case 1: std::cout << 'O'; break;
			case 2: std::cout << '@'; break;
			}
		}
		std::cout << '*';
		std::cout << '\n';
	}
	for (int i = 0; i < GRID_WIDTH+2; i++)
	{
		std::cout << '*';
	}
}

void default_mode()
{
	info();
    bool retry = false;
	while (true) {
		Array2d<int> grid = create_2d<int>();
		Array<int> row = create<int>();
		int score = 0;
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			append(row, 0);
		}
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			append_row(grid, row);
		}
		srand(time(0));
		Array<int> snake = create<int>();
		int apple[2]{ GRID_HEIGHT / 4, GRID_WIDTH / 4 * 3 };
		struct
		{
			int up[2]{ -1, 0 };
			int left[2]{ 0, -1 };
			int down[2]{ 1, 0 };
			int right[2]{ 0, 1 };
		} Directions;
		int* direction = Directions.right;
		append(snake, GRID_HEIGHT/2);
		append(snake, GRID_WIDTH / 8 + 2);
		append(snake, GRID_HEIGHT / 2);
		append(snake, GRID_WIDTH / 8 + 1);
		append(snake, GRID_HEIGHT / 2);
		append(snake, GRID_WIDTH / 8);
		char choice = 'd';
		int tail_r;
		int tail_c;
		bool flag = true;
		bool is_game_over = false;
		int delay_time = 300;
		while (flag) {
			insert_objects(grid, snake, apple);
			print_grid(grid, score);
			Sleep(delay_time - ((score <= 3*30) ? score*3 : delay_time-30));
			if (_kbhit())
			{
				choice = _getch();
			}
			switch (choice)
			{
			case 'W':
			case 'w': if (direction != Directions.down) direction = Directions.up; break;
			case 'A':
			case 'a': if (direction != Directions.right) direction = Directions.left; break;
			case 'S':
			case 's': if (direction != Directions.up) direction = Directions.down; break;
			case 'D':
			case 'd': if (direction != Directions.left) direction = Directions.right; break;
			case 'L':
			case 'l': retry = false; flag = false; break;
			}
			if (flag == false)
			{
				break;
			}
			tail_r = snake.data[snake.size - 2];
			tail_c = snake.data[snake.size - 1];
			move_snake(grid, snake, direction);
			if (snake.data[0] == apple[0] && snake.data[1] == apple[1])
			{
				score++;
				append(snake, tail_r);
				append(snake, tail_c);
				while (true) {
					bool flag = false;
					apple[0] = rand() % GRID_HEIGHT;
					apple[1] = rand() % GRID_WIDTH;
					for (int i = 0; i < snake.size; i += 2)
					{
						if (apple[0] == snake.data[i] && apple[1] == snake.data[i + 1] && score != GRID_WIDTH * GRID_HEIGHT - 3)
						{
							flag = true;
							break;
						}
					}
					if (flag)
					{
						continue;
					}
					break;
				}
			}
			else if (grid.data[snake.data[0]].data[snake.data[1]] == 1)
			{
				is_game_over = true;
			}
			if (is_game_over)
			{
				break;
			}
		}
		destroy(grid);
		destroy(row);
		destroy(snake);
		if (is_game_over)
		{
			system("cls");
			if (score != GRID_WIDTH * GRID_HEIGHT - 3)
			{
				int iterations = 0;
				for (int i = score; i > 0; i /= 10)
				{
					iterations++;
				}
				for (int i = 0; i < GRID_WIDTH + 2; i++)
				{
					std::cout << '*';
				}
				std::cout << '\n';
				std::cout << '*';
				for (int i = 0; i < GRID_WIDTH; i++)
				{
					std::cout << ' ';
				}
				std::cout << '*';
				std::cout << '\n';
				std::cout << "* ";
				std::cout << "Score: " << score;
				for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 30 : GRID_WIDTH - 29 - iterations); i++)
				{
					std::cout << ' ';
				}
				std::cout << "L - Leave  R - Retry ";
				std::cout << '*';
				std::cout << '\n';
				std::cout << '*';
				for (int i = 0; i < GRID_WIDTH; i++)
				{
					std::cout << ' ';
				}
				std::cout << '*';
				std::cout << '\n';
				for (int i = 0; i < GRID_WIDTH + 2; i++)
				{
					std::cout << '*';
				}
				std::cout << '\n';
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                 G A M E                *\n";
				std::cout << "*                 O V E R                *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "******************************************";
			}
			else
			{
				int iterations = 0;
				for (int i = score; i > 0; i /= 10)
				{
					iterations++;
				}
				for (int i = 0; i < GRID_WIDTH + 2; i++)
				{
					std::cout << '*';
				}
				std::cout << '\n';
				std::cout << '*';
				for (int i = 0; i < GRID_WIDTH; i++)
				{
					std::cout << ' ';
				}
				std::cout << '*';
				std::cout << '\n';
				std::cout << "* ";
				std::cout << "Score: " << score;
				for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 30 : GRID_WIDTH - 29 - iterations); i++)
				{
					std::cout << ' ';
				}
				std::cout << "L - Leave  R - Retry ";
				std::cout << '*';
				std::cout << '\n';
				std::cout << '*';
				for (int i = 0; i < GRID_WIDTH; i++)
				{
					std::cout << ' ';
				}
				std::cout << '*';
				std::cout << '\n';
				for (int i = 0; i < GRID_WIDTH + 2; i++)
				{
					std::cout << '*';
				}
				std::cout << '\n';
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                  Y O U                 *\n";
				std::cout << "*                  W O N                 *\n";
				std::cout << "*                  ! ! !                 *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "*                                        *\n";
				std::cout << "******************************************";
			}
			char choice = 'm';
			bool flag = true;
			while (flag) {
				choice = _getch();
				switch (choice)
				{
				case 'L':
				case 'l': {flag = false; break; }
				case 'R':
				case 'r': {retry = true; flag = false; break; }
				default: break;
				}
			}
		}
		if (retry)
		{
			retry = false;
			continue;
		}
		break;
	}
}