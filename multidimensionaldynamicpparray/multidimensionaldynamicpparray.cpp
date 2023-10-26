#include <iostream>
#include "Array2d.h"

int main()
{
    srand(time(0));
    Array2d<int> mdarr = create_2d<int>();
    Array<int> arr = create<int>();
    for (int i = 0; i < 10; i++)
    {
        append(arr, i);
    }
    for (int i = 0; i < 10; i++)
    {
        append_col(mdarr, arr);
        append_row(mdarr, arr);
    }
    print_array(mdarr);
    for (int i = 0; i < 10; i++)
    {
        pop_row(mdarr, i);
    }
    for (int i = 0; i < 5; i++)
    {
        pop_col(mdarr, i);
    }
    print_array(mdarr);
    destroy(mdarr);
    destroy(arr);
}
