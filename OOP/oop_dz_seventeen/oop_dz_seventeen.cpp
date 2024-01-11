#include <iostream>
#include "HashSet.h"

int main()
{
    //while (true)
    {
        HashSet<std::string> int_hash;
        int_hash.add("John");
        int_hash.add("Alex");
        int_hash.add("Amin");
        int_hash.add("Josh");
        int_hash.add("Ben");
        int_hash.add("Boba");
        int_hash.add("Biba");
        std::cout << "load factor: " << int_hash.get_load_factor() << '\n';
        int_hash.add("Jack");
        std::cout << int_hash;
        std::cout << "load factor: " << int_hash.get_load_factor() << '\n';
        int_hash.add("Rasul");
        int_hash.remove("John");
        std::cout << int_hash;
        std::cout << "load factor: " << int_hash.get_load_factor() << '\n';
    }
}