#include <iostream>
#include "LinkedList.h"

int main()
{
    while (true)
    {
        LinkedList<int> llist;

        llist.push_back(10);
        auto pos = llist.push_back(20);
        llist.push_back(30);
        llist.insert_after(25, pos);
        llist.reverse();
    }
}
