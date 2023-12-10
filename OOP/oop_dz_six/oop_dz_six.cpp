#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Clock.h"
#include "DateTime.h"
#include <Windows.h>

int main()
{
    DateTime date_and_time1 = DateTime::get_now();
    Sleep(3000);
    DateTime date_and_time2 = DateTime::get_now();
    std::cout << std::boolalpha << (date_and_time1 < date_and_time2);
}
