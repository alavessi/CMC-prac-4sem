#include "vector.h"
#include <iostream>

int main()
{
    Vector v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i * i);
    }
    std::cout << "Size = " << v.get_size() << "\n";
    v.print();
    v.set(100, -7);
    std::cout << v.get(10) << "\n";
    Vector v1(v);
    std::cout << "Size = " << v.get_size() << "\n";
    v1.set(10, -3);
    std::cout << v1.get(10) << "\n";
    v1.print();
    int cap = 10;
    int* pointer = new int[cap];
    Vector v2(7, cap, pointer);
    v2.set(5, -5);
    std::cout << v2.get(5) << "\n";
    std::cout << "Size=" << v.get_size() << "\n";
    v2.print();
    v2 = v1;
    v2.set(10, -100);
    std::cout << v2.get(10) << "\n";
    v2.print();
    return 0;
}
