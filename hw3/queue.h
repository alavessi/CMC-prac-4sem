#pragma once
#include "list.h"
#define MAXSIZE 10

class Queue: public List
{
private:
    unsigned int Size;
    unsigned int maxsize;
    Node* head;
    Node* tail;

public:
    Queue(unsigned int _maxsize = MAXSIZE);
    ~Queue();
    void back(const Data& x);
    const Data& front() const;
    void pop();
    unsigned int size() const;
    bool empty() const;
    bool full() const;
    void print() const;
};
