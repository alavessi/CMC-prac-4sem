#pragma once
#include "data.h"

class Node
{
    friend class List;
    friend class Queue;

public:
    Node(const Data& _value, Node* _prev, Node* _next);
    
private:
    Data value;
    Node* prev;
    Node* next;
};
