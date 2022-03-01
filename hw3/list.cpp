#include "list.h"
#include <iostream>

List::List() : Size(0), head(nullptr), tail(nullptr) {}

List::~List()
{
    clear();
}

void List::push_front(const Data& x)
{
    Node* p = new Node(x, nullptr, head);
    if (empty())
    {
        tail = p;
    }
    else
    {
        head->prev = p;
    }
    head = p;
    Size++;
}

void List::push_back(const Data& x)
{
    Node* p = new Node(x,tail,nullptr);
    if (empty())
    {
        head = p;
    }
    else
    {
        tail->next = p;
    }
    tail = p;
    Size++;
}

const Data& List::front() const
{
    if (!empty())
    {
        return head->value;
    }
    std::cout << "Error: list is empty, front() returned ";
}

const Data& List::back() const
{
    if (!empty())
    {
        return tail->value;
    }
    std::cout << "Error: list is empty, back() returned ";
}

void List::pop_front()
{
    if (empty())
    {
        std::cout << "Error: list/queue is empty\n";
    }
    else
    {
        Node* p = head;
        if (size() == 1)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;         
        }
        delete p;
        Size--;
    }
}

void List::pop_back()
{
    if (empty())
    {
        std::cout << "Error: list/queue is empty\n";
    }
    else
    {
        Node* p = tail;
        if (size() == 1)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;   
        }
        delete p;
        Size--;
    }
}

void List::insert(unsigned int p, const Data& x)
{
    if (p == 0)
    {
        push_front(x);
    }
    else if (p < size())
    {
        Node* current = head;
        for (unsigned int i = 0; i < p; i++)
        {
            current = current->next;
        } 
        Node* temp = new Node(x, current->prev, current);
        (current->prev)->next = temp;
        current->prev = temp;
        Size++;
    }
    else
    {
        std::cout << "ERROR: There is no " << p << "th element in the list\n";
    }
}

void List::erase(unsigned int p)
{
    if (p == 0)
    {
        pop_front();
    }
    else if (p == size() - 1)
    {
        pop_back();
    }
    else if (p < Size - 1)
    {
        Node* current = head;
        for (unsigned int i = 0; i < p; i++)
        {
            current = current->next;
        }
        (current->prev)->next = current->next;
        (current->next)->prev = current->prev;
        delete current;
        Size--;
    }
    else
    {
        std::cout << "ERROR: There is no " << p << "th element in the list\n";
    }
}

bool List::empty() const
{
    return size() == 0;
}

unsigned int List::size() const
{
    return Size;
}

void List::print() const
{
    for (Node* p = head; p != nullptr; p = p->next)
    {
        p->value.Data::print();
    }
    std::cout << "\n";
}

void List::clear()
{
    while(head != nullptr)
    {
        Node* p = head;
        head = head->next;
        delete p;
    }
}
