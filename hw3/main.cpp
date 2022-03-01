#include "queue.h"
#include <iostream>

int main()
{
    Queue q1, q2(5);
    for (int i = 0; i < 20; i++)
    {
        q1.back({"ABC", 2000 * i + 1000});
        q2.back({"DEF", 2000 * i});
    }
    q1.print();
    q2.print();
    std::cout << "\nSize=" << q1.size() << "\n";
    for (int i = 0; i < 7; i++)
    { 
        q1.front().print();
        q1.pop();
    }
    std::cout << "\nSize=" << q1.size() << "\n";
    std::cout << "Is queue empty? ";
    if (q1.empty())
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }
    q1.print();
    for (int i = 0; i < 15; i++)
    {
        q2.front().print();
        q2.pop();
    }
    std::cout << "\nSize=" << q2.size() << "\n";
    std::cout << "Is queue empty? ";
    if (q2.empty())
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }
    return 0;
}
