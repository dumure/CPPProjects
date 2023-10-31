#include <iostream>
#include "DB.h"
#include "User.h"

#define SAY_HELLO(NAME) std::cout << "Hello " << NAME << '\n'

#define CREATE_VARIABLE(TYPE, NAME) TYPE g##NAME = {}

CREATE_VARIABLE(int, Val);

#define CREATE_SUM(TYPE) TYPE Sum_##TYPE(TYPE a, TYPE b) \
{ \
    return a + b; \
}

CREATE_SUM(int)
CREATE_SUM(double)

int main()
{
    std::cout << Sum_int(5, 5);
}

