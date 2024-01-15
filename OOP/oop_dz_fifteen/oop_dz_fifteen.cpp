#include <iostream>
#include "Queue.h"
#include "PriorityQueue.h"

int main()
{
    //while (true)
    {
        PriorityQueue<int, Less<int>> queue;
        queue.push(5);
        queue.push(6);
        queue.push(3);
        queue.push(18);
        queue.push(2);
        std::cout << queue;
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        std::cout << queue;
        std::cout << queue.empty();
    }
}

