#include <iostream>

class A
{
public:
    virtual void foo()
    {

    }
};

class B : public A
{
    virtual void foo() override
    {

    }
};


int main()
{
    A* b = new B;
    A* a = new A;
    std::cout << "breakpoint\n";
    delete a;
    delete b;
}
