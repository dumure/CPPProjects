#pragma once

void move_snake(Array<int>& snake, int* direction, bool is_mirrored);

void clear_grid(Array2d<int> arr2d, int corner);

void print_grid(Array2d<int> arr2d, int score, int time);

bool pause(int, int = 0);

void info();