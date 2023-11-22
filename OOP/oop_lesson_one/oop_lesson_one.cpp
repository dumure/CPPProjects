#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Student
{
public:
    ~Student()
    {
        std::cout << "Called destructor" << '\n';

        delete[] m_name;
    }

    Student()
    {
        std::cout << "Called default constructor" << '\n';

        m_diamonds = 0;
        m_coins = 0;
        m_badges = 0;
        m_name = nullptr;
    }

    Student(int a_diamonds, int a_coins, int a_badges, const char* a_name)
    {
        std::cout << "Called overloaded constructor" << '\n';

        m_diamonds = a_diamonds;
        m_coins = a_coins;
        m_badges = a_badges;
        m_name = new char[32];
        strcpy(m_name, a_name);
    }

    int get_diamonds()
    {
        return m_diamonds;
    }

    void set_diamonds(int a_diamonds)
    {
        if (a_diamonds >= 0 && a_diamonds <= 1000)
        {
            m_diamonds = a_diamonds;
        }
    }

    int get_coins()
    {
        return m_coins;
    }

    void set_coins(int a_coins)
    {
        if (a_coins >= 0 && a_coins <= 2000)
        {
            m_coins = a_coins;
        }
    }

    int get_badges()
    {
        return m_badges;
    }

    void set_badges(int a_badges)
    {
        if (a_badges >= 0 && a_badges <= 50)
        {
            m_badges = a_badges;
        }
    }

    const char* get_name()
    {
        return m_name;
    }

    void set_name(const char* a_name)
    {
        delete[] m_name;

        m_name = new char[strlen(a_name) + 1];

        strcpy(m_name, a_name);
    }

private:
    int m_diamonds;
    int m_coins;
    int m_badges;
    char* m_name;
};

int main()
{
    Student student1{301, 401, 9, "Rasul"};

    student1.set_badges(64);

    std::cout << "Student #1 coins: " << student1.get_diamonds() << '\n';
    std::cout << "Student #1 coins: " << student1.get_coins() << '\n';
    std::cout << "Student #1 badges: " << student1.get_badges() << '\n';
    std::cout << "Student #1 name: " << student1.get_name() << '\n';
}
