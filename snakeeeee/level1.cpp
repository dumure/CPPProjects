#include "Header.h"

template<typename T>
void print_grid(Array2d<T> arr2d, int score, int time)
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
            case 4: std::cout << '&'; break;
            case 5: std::cout << '0'; break;
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

template<typename T>
void clear_grid(Array2d<T>& arr2d)
{
	for (int i = 1; i < arr2d.size-1; i++)
	{
		for (int j = 1; j < arr2d.data[i].size-1; j++)
		{
			arr2d.data[i].data[j] = 0;
		}
	}
}

template<typename T>
void insert_objects(Array2d<T>& grid, Array<T> snake, Array<T> walls, int* apple = nullptr)
{
	clear_grid(grid);
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

template<typename T>
void move_snake(Array2d<T>& grid, Array<T>& snake, int* direction)
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
    			Sleep(delay_time);
    		}
    		destroy(grid);
    		destroy(walls);
    		destroy(row);
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
    				for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 36 : GRID_WIDTH - 35 - iterations_score); i++)
    				{
    					std::cout << ' ';
    				}
    				std::cout << "Time left: " << time_left;
    				for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 36 : GRID_WIDTH - 35 - iterations_time); i++)
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
                    if (score == 0)
    				std::cout << "*          By getting zero stars         *\n";
                    else if (score == 1)
                    std::cout << "*           By getting one stars         *\n";
                    else if (1 < score && score < 4)
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
                if (grid.data[snake.data[0]].data[snake.data[1]] == 1 || grid.data[snake.data[0]].data[snake.data[1]] == 3)
                {
                    is_game_over = true;
                }
                if (is_game_over)
                {
                    break;
                }
                iterations++;
                Sleep(delay_time);
            }
            destroy(grid);
            destroy(walls);
            destroy(row);
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
                    for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 36 : GRID_WIDTH - 35 - iterations_score); i++)
                    {
                        std::cout << ' ';
                    }
                    std::cout << "Time left: " << time_left;
                    for (int i = 0; i < ((score == 0) ? GRID_WIDTH - 36 : GRID_WIDTH - 35 - iterations_time); i++)
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
}