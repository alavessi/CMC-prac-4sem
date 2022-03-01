#include "list.h"
#include <iostream>

int main()
{
    List lst;
    for (int i = 0; i < 10; i++)
    {
        lst.push_front(i * i);
    }
    lst.print();
    List lst2;
    for (int i = 0; i < 10; i++)
    {
        lst2.push_back(i);
    }
    std::cout << "Size=" << lst2.size() << "\n";
    lst2.print();
    for (int i = 0; i < 15; i++)
    {
        std::cout << "front=" << lst.front() << " ";
        lst.pop_front();
    }
    std::cout << "\nSize=" << lst.size() << "\n";
    for (int i = 0; i < 15; i++)
    {
        lst.push_back(-1 * i);
    }
    std::cout << "Size=" << lst.size() << "\n";
    lst.print();
    for (int i = 0; i < 5; i++)
    {
        lst.pop_back();
    }
    std::cout << "Size=" << lst.size() << "\n";
    lst.print();
    std::cout << lst.front() << " " << lst.back() << "\n";
    lst.insert(9, -100);
    std::cout << "Size=" << lst.size() << "\n";
    lst.print();
    lst.erase(0);
    std::cout << "Size=" << lst.size() << "\n";
    lst.print();
    std::cout << "Is list empty? " << lst.empty() << "\n";
    for (int i = 0; i < 20; i++)
    {
        lst.erase(i);
        lst.push_front(i * i);
        lst.insert(i, -100);
        lst.pop_back();
        lst.pop_front();
        lst.push_back(-1 * i);
        lst.push_front(lst.size());
        lst.insert(lst.size() - i, 10 * i);
    }
    lst.print();
    return 0;
}
