#pragma once

void move_snake(Array2d<int>& grid, Array<int>& snake, int* direction);

void clear_grid(Array2d<int> arr2d, int corner);

void print_grid(Array2d<int> arr2d, int score, int time);

void pause();

void info();