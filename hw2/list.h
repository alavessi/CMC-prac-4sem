#pragma once
#include "node.h"

class List
{
    friend class Queue;

public:
    List();
    ~List();
    void push_front(const Data& x);
    void push_back(const Data& x);
    const Data& front() const;
    const Data& back() const;
    void pop_front();
    void pop_back();
    void insert(unsigned int p, const Data& x);
    void erase(unsigned int p);
    bool empty() const;
    unsigned int size() const;
    void print() const;
    void clear();
    
private:
    unsigned int Size;
    Node* head;
    Node* tail;
};
