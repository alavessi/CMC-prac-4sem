#include "queue.h"
#include <iostream>

Queue::Queue(unsigned int _maxsize) : maxsize(_maxsize), Size(0), head(nullptr), tail(nullptr) {}

Queue::~Queue()
{
    List::~List();
}

void Queue::back(const Data& x)
{
    if (!full())
    {
        List::push_back(x);
    }
    else
    {
        std::cout << "Error: queue is full\n";
    }
}

const Data& Queue::front() const
{
    return List::front();
}

void Queue::pop()
{
    List::pop_front();
}

unsigned int Queue::size() const
{
    return List::size();
}

bool Queue::empty() const
{
    return List::empty();
}

bool Queue::full() const
{
    return size()==maxsize;
}

void Queue::print() const
{
    List::print();
}
