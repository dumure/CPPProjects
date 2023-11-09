#include "Header.h"

void insert_objects(Array2d<int>& grid, Array<int> snake, Array<int> walls, int* apple = nullptr)
{
	clear_grid(grid, 1);
	for (int i = 0; i < snake.size; i += 2)
	{
		grid.data[snake.data[i]].data[snake.data[i + 1]] = 1;
	}
	if (apple != nullptr)
	{
		grid.data[apple[0]].data[apple[1]] = 2;
	}
	for (int i = 0; i < walls.size; i += 2)
	{
		grid.data[walls.data[i]].data[walls.data[i + 1]] = 3;
	}
}


void level_one(int diff)
{
    info();
	if (diff == 1)
	{
		bool retry = false;
    	while (true)
    	{
    		Array2d<int> grid = create_2d<int>();
    		Array<int> row = create<int>();
    		int score = 0;
    		int time_left = 30;
    		for (int i = 0; i < GRID_WIDTH; i++)
    		{
    			append(row, 3);
    		}
            append_row(grid, row);
            clear(row);
            append(row, 3);
            for (int i = 0; i < GRID_WIDTH - 2; i++)
            {
                append(row, 0);
            }
            append(row, 3);
            for (int i = 0; i < GRID_HEIGHT - 2; i++)
            {
                append_row(grid, row);
            }
            clear(row);
            for (int i = 0; i < GRID_WIDTH; i++)
            {
                append(row, 3);
            }
            append_row(grid, row);
    		srand(time(0));
    		Array<int> snake = create<int>();
    		Array<int> walls = create<int>();
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
    		append(walls, GRID_HEIGHT / 3);
    		append(walls, GRID_WIDTH / 5);
    		char choice = 'd';
    		int iterations = 0;
    		int tail_r;
    		int tail_c;
    		bool flag = true;
    		bool is_game_over = false;
    		int delay_time = 250;
    		while (!is_game_over)
    		{
				if (iterations == 4)
				{
					time_left--;
					int x = 0;
					int y = 0;
					iterations = 0;
					while (true){
						x = rand() % GRID_HEIGHT;
						y = rand() % GRID_WIDTH;
						if (grid.data[x].data[y] == 0)
						{
							break;
						}
					}
					append(walls, x);
					append(walls, y);
				}
                if (time_left == 0)
                {
                    is_game_over = true;
                }
                if (is_game_over)
                {
                    break;
                }
    			insert_objects(grid, snake, walls, apple);
    			print_grid(grid, score, time_left);
                Sleep(delay_time);
                char temp = choice;
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
                case 27: pause(); choice = temp;
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
                    int x = 0;
                    int y = 0;
                    while (true) {
                        x = rand() % GRID_HEIGHT;
                        y = rand() % GRID_WIDTH;
                        if (grid.data[x].data[y] == 0)
                        {
                            break;
                        }
                    }
                    apple[0] = x;
                    apple[1] = y;
    			}
                else if (grid.data[snake.data[0]].data[snake.data[1]] == 1 || grid.data[snake.data[0]].data[snake.data[1]] == 3)
    			{
    				is_game_over = true;
    			}
    			if (is_game_over)
    			{
    				break;
    			}
    			iterations++;
    		}
    		destroy(grid);
    		destroy(walls);
    		destroy(row);
            destroy(snake);
    		if (is_game_over)
    		{
    			system("cls");
    			if (time_left != 0)
    			{
    				int iterations_score = 0;
    				for (int i = score; i > 0; i /= 10)
    				{
    					iterations_score++;
    				}
    				int iterations_time = 0;
    				for (int i = time_left; i > 0; i /= 10)
    				{
    					iterations_time++;
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
    				std::cout << "* ";
                    std::cout << "Score: " << score;
                    for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 38 : GRID_WIDTH - 37 - iterations_score); i++)
                    {
                        std::cout << ' ';
                    }
                    std::cout << "Time: " << time_left;
                    for (int i = 0; i < ((time_left == 0) ? GRID_WIDTH - 38 : GRID_WIDTH - 37 - iterations_time); i++)
                    {
                        std::cout << ' ';
                    }
                    std::cout << "L - Leave R - Retry ";
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
    				std::cout << "******************************************";
    			}
    			else
    			{
                    int iterations_score = 0;
                    for (int i = score; i > 0; i /= 10)
                    {
                        iterations_score++;
                    }
                    int iterations_time = 0;
                    for (int i = time_left; i > 0; i /= 10)
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
                    for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 38 : GRID_WIDTH - 37 - iterations_score); i++)
                    {
                        std::cout << ' ';
                    }
                    std::cout << "Time: " << time_left;
                    for (int i = 0; i < ((time_left == 0) ? GRID_WIDTH - 38 : GRID_WIDTH - 37 - iterations_time); i++)
                    {
                        std::cout << ' ';
                    }
                    std::cout << "L - Leave R - Retry ";
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
                    if (score == 0)
    				std::cout << "*          By getting zero stars         *\n";
                    else if (score == 1)
                    std::cout << "*           By getting one stars         *\n";
                    else if (1 < score && score < 5)
                    std::cout << "*           By getting two stars         *\n";
                    else 
                    std::cout << "*         By getting three stars         *\n";
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
    else {
        bool retry = false;
        while (true)
        {
            Array2d<int> grid = create_2d<int>();
            Array<int> row = create<int>();
            int score = 0;
            int time_left = 30;
            for (int i = 0; i < GRID_WIDTH; i++)
            {
                append(row, 3);
            }
            append_row(grid, row);
            clear(row);
            append(row, 3);
            for (int i = 0; i < GRID_WIDTH - 2; i++)
            {
                append(row, 0);
            }
            append(row, 3);
            for (int i = 0; i < GRID_HEIGHT - 2; i++)
            {
                append_row(grid, row);
            }
            clear(row);
            for (int i = 0; i < GRID_WIDTH; i++)
            {
                append(row, 3);
            }
            append_row(grid, row);
            srand(time(0));
            Array<int> snake = create<int>();
            Array<int> walls = create<int>();
            struct
            {
                int up[2]{ -1, 0 };
                int left[2]{ 0, -1 };
                int down[2]{ 1, 0 };
                int right[2]{ 0, 1 };
            } Directions;
            int* direction = Directions.right;
            append(snake, GRID_HEIGHT / 2);
            append(snake, GRID_WIDTH / 8 + 2);
            append(snake, GRID_HEIGHT / 2);
            append(snake, GRID_WIDTH / 8 + 1);
            append(snake, GRID_HEIGHT / 2);
            append(snake, GRID_WIDTH / 8);
            append(walls, GRID_HEIGHT / 3);
            append(walls, GRID_WIDTH / 5);
            char choice = 'd';
            int iterations = 0;
            bool flag = true;
            bool is_game_over = false;
            int delay_time = 250;
            while (!is_game_over)
            {
                if (iterations == 4)
                {
                    time_left--;
                    int x = 0;
                    int y = 0;
                    iterations = 0;
                    while (true) {
                        x = rand() % GRID_HEIGHT;
                        y = rand() % GRID_WIDTH;
                        if (grid.data[x].data[y] == 0)
                        {
                            break;
                        }
                    }
                    append(walls, x);
                    append(walls, y);
                }
                if (time_left == 0)
                {
                    is_game_over = true;
                }
                if (is_game_over)
                {
                    break;
                }
                insert_objects(grid, snake, walls);
                print_grid(grid, score, time_left);
                Sleep(delay_time);
                char temp = choice;
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
                case 27: pause(); choice = temp;
                }
                if (flag == false)
                {
                    break;
                }
                move_snake(grid, snake, direction);
                if (grid.data[snake.data[0]].data[snake.data[1]] == 1 || grid.data[snake.data[0]].data[snake.data[1]] == 3)
                {
                    is_game_over = true;
                }
                if (is_game_over)
                {
                    break;
                }
                iterations++;
            }
            destroy(grid);
            destroy(walls);
            destroy(row);
            destroy(snake);
            if (is_game_over)
            {
                system("cls");
                if (time_left != 0)
                {
                    int iterations_score = 0;
                    for (int i = score; i > 0; i /= 10)
                    {
                        iterations_score++;
                    }
                    int iterations_time = 0;
                    for (int i = time_left; i > 0; i /= 10)
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
                    for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 38 : GRID_WIDTH - 37 - iterations_score); i++)
                    {
                        std::cout << ' ';
                    }
                    std::cout << "Time: " << time_left;
                    for (int i = 0; i < ((time_left == 0) ? GRID_WIDTH - 38 : GRID_WIDTH - 37 - iterations_time); i++)
                    {
                        std::cout << ' ';
                    }
                    std::cout << "L - Leave R - Retry ";
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
                    std::cout << "******************************************";
                }
                else
                {
                    int iterations_score = 0;
                    for (int i = score; i > 0; i /= 10)
                    {
                        iterations_score++;
                    }
                    int iterations_time = 0;
                    for (int i = time_left; i > 0; i /= 10)
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
                    for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 38 : GRID_WIDTH - 37 - iterations_score); i++)
                    {
                        std::cout << ' ';
                    }
                    std::cout << "Time: " << time_left;
                    for (int i = 0; i < ((time_left == 0) ? GRID_WIDTH - 38 : GRID_WIDTH - 37 - iterations_time); i++)
                    {
                        std::cout << ' ';
                    }
                    std::cout << "L - Leave R - Retry ";
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
}