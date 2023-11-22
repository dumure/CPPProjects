#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point
{
    int m_x;
    int m_y;
public:
    Point()
    {
        m_x = 0;
        m_y = 0;
    }
    Point(int a_x, int a_y)
    {
        m_x = a_x;
        m_y = a_y;
    }
    int get_x()
    {
        return m_x;
    }
    int get_y()
    {
        return m_y;
    }
    void show_coords()
    {
        std::cout << "Object point1:\n-X: " << get_x() << "\n-Y: " << get_y() << '\n';
    }
    void set_x(int a_x)
    {
        m_x = a_x;
    }
    void set_y(int a_y)
    {
        m_y = a_y;
    }
};

class Item
{
    char* m_name;
    int m_price;
    int m_quantity;
public:
    ~Item()
    {
        delete[] m_name;
    }
    Item()
    {
        m_name = nullptr;
        m_price = 0;
        m_quantity = 0;
    }
    Item(const char* a_name, int a_price, int a_quantity)
    {
        int len = strlen(a_name);
        m_name = new char[len + 1];
        strcpy(m_name, a_name);
        m_name[len] = 0;
        m_price = a_price;
        m_quantity = a_quantity;
    }
    const char* get_name()
    {
        return m_name;
    }
    int get_price()
    {
        return m_price;
    }
    int get_quantity()
    {
        return m_quantity;
    }
    void show_info()
    {
        std::cout << "Object item1:\n-name: " << get_name() << "\n-price: " << get_price() << "$\n-quantity: " << get_quantity() << '\n';
    }
    void set_name(const char* a_name)
    {
        delete[] m_name;
        int len = strlen(a_name);
        m_name = new char[len + 1];
        strcpy(m_name, a_name);
        m_name[len] = 0;
    }
    void set_price(int a_price)
    {
        m_price = a_price;
    }
    void set_quantity(int a_price)
    {
        m_quantity = m_quantity;
    }
};

int main()
{
    {
        int x, y;
        std::cout << "Enter value for x:\n >>> ";
        std::cin >> x;
        std::cout << "Enter value for x:\n >>> ";
        std::cin >> y;
        Point point1{ x, y };
        point1.show_coords();
    }
    {
        char name[32]{};
        int price, quantity;
        std::cout << "Enter name:\n >>> ";
        std::cin.ignore();
        std::cin.getline(name, 32);
        std::cout << "Enter price:\n >>> ";
        std::cin >> price;
        std::cout << "Enter quantity:\n >>> ";
        std::cin >> quantity;
        Item item1{ name, price, quantity };
        item1.show_info();
    }
}
