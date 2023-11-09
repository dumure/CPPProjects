#include "Header.h"

void move_snake(Array2d<int>& grid, Array<int>& snake, int* direction)
{
	if (snake.data[1] + direction[1] < 0)
	{
		prepend(snake, GRID_WIDTH - 1);
	}
	else if (snake.data[1] + direction[1] >= 0 && snake.data[1] + direction[1] < GRID_WIDTH)
	{
		prepend(snake, snake.data[1] + direction[1]);
	}
	else
	{
		prepend(snake, 0);
	}
	if (snake.data[1] + direction[0] < 0)
	{
		prepend(snake, GRID_HEIGHT - 1);
	}
	else if (snake.data[1] + direction[0] >= 0 && snake.data[1] + direction[0] < GRID_HEIGHT)
	{
		prepend(snake, snake.data[1] + direction[0]);
	}
	else
	{
		prepend(snake, 0);
	}
	pop(snake);
	pop(snake);
}

void clear_grid(Array2d<int> arr2d, int corner)
{
	for (int i = corner; i < arr2d.size - corner; i++)
	{
		for (int j = corner; j < arr2d.data[i].size - corner; j++)
		{
			arr2d.data[i].data[j] = 0;
		}
	}
}

void print_grid(Array2d<int> arr2d, int score, int time)
{
    system("cls");
    int iterations_score = 0;
    for (int i = score; i > 0; i /= 10)
    {
        iterations_score++;
    }
    int iterations_time = 0;
    for (int i = time; i > 0; i /= 10)
    {
        iterations_time++;
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
    for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 36 : GRID_WIDTH - 35 - iterations_score); i++)
    {
        std::cout << ' ';
    }
    std::cout << "Time left: " << time;
    for (int i = 0; i < ((time == 0) ? GRID_WIDTH - 36 : GRID_WIDTH - 35 - iterations_time); i++)
    {
        std::cout << ' ';
    }
    std::cout << " L - Leave ";
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
            case 3: std::cout << 'X'; break;
            case 10: std::cout << 'X'; break;
            case 9: std::cout << 'x'; break;
            case 4: std::cout << '&'; break;
            case 5: std::cout << '0'; break;
            case 6: std::cout << 'a'; break;
            case 7: std::cout << 'd'; break;
            case 8: std::cout << '$'; break;
            }
        }
        std::cout << '*';
        std::cout << '\n';
    }
    for (int i = 0; i < GRID_WIDTH + 2; i++)
    {
        std::cout << '*';
    }
}

void pause()
{
    system("cls");
    std::cout << "******************************************\n";
    std::cout << "*                                        *\n";
    std::cout << "*                Pause menu              *\n";
    std::cout << "*                                        *\n";
    std::cout << "******************************************\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "*         Press 'ESC' for resume         *\n";
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
    char key = 0;
    while (true)
    {
        if (_kbhit())
        {
            key = _getch();
        }
        if (key == 27)
        {
            break;
        }
        Sleep(250);
    }
}

void info()
{
    system("cls");
    std::cout << "******************************************\n";
    std::cout << "*                                        *\n";
    std::cout << "*            Info | Get ready            *\n";
    std::cout << "*                                        *\n";
    std::cout << "******************************************\n";
    std::cout << "*                                        *\n";
    std::cout << "*       Space - skip this window         *\n";
    std::cout << "*                                        *\n";
    std::cout << "*                                        *\n";
    std::cout << "*        @ - apple ( score + 1 )         *\n";
    std::cout << "*                                        *\n";
    std::cout << "*         & - pear ( score - 1 )         *\n";
    std::cout << "*                                        *\n";
    std::cout << "*         X - wall ( game over )         *\n";
    std::cout << "*                                        *\n";
    std::cout << "*          O - snake ( player )          *\n";
    std::cout << "*                                        *\n";
    std::cout << "*      0 - mirrored snake ( enemy )      *\n";
    std::cout << "*                                        *\n";
    std::cout << "*       a - acceleration ( 7 secs )      *\n";
    std::cout << "*                                        *\n";
    std::cout << "*       d - deceleration ( 7 secs )      *\n";
    std::cout << "*                                        *\n";
    std::cout << "*       $ - immortality  ( 5 secs )      *\n";
    std::cout << "*                                        *\n";
    std::cout << "******************************************";
    char key = 0;
    for (int i = 0; i < 60; i++)
    {
        if (_kbhit())
        {
            key = _getch();
        }
        if (key == 32)
        {
            break;
        }
        Sleep(250);
    }
}