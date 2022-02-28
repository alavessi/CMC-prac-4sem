#include "vector.h"
#include <iostream>

Vector::Vector()
{
    size = 0;
    capacity = 1;
    p = new int[capacity];
    std::cout << "Default constructor\n";
}

Vector::Vector(int _size, int _capacity, int* _p)
{
    size = _size;
    capacity = _capacity;
    p = _p;
    std::cout << "Constructor\n";
}

Vector::Vector(const Vector& v)
{
    size = v.size;
    capacity = v.capacity;
    p = new int[capacity];
    for(int i = 0; i < size; i++)
    {
        p[i] = v.p[i];
    }
    std::cout << "Copy constructor\n";
}

Vector::~Vector()
{
    delete [] p;
    std::cout << "Destructor\n";
}

Vector& Vector::operator=(const Vector& v)
{
    if (this == &v)
    {
        return *this;
    }
    delete [] p;
    size = v.size;
    capacity = v.capacity;
    p = new int[capacity];
    for(int i = 0; i < size; i++)
    {
        p[i] = v.p[i];
    }
    std::cout << "Overloading of operator =\n";
    return *this;
}

void Vector::push_back(int a)
{
    if (size >= capacity)
    {
        int* copy = new int [capacity*=2];
        for (int i = 0; i < size; i++)
        {
            copy[i] = p[i];
        }
        delete [] p;
        p = copy;
    }
    p[size++] = a;
    std::cout << "Push back " << a << "\n";
}

int Vector::get(int i) const
{
    if (i >= 0 && i < size)
    {
        std::cout << i << "th element of vector was got successfully\n";
        return p[i];
    }
    else
    {
        std::cout << "ERROR: There is no " << i << "th element in the vector\n";
        return 666;
    }
}

void Vector::set(int i, int value)
{
    if (i >= 0 && i < size)
    {
        std::cout << i << "th element of vector was changed on " << value << " successfully\n";
        p[i] = value;
    }
    else
    {
        std::cout << "ERROR: There is no " << i << "th element in the vector\n";
    }
}

int Vector::get_size() const
{
    return size;
}

void Vector::print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << p[i] << " ";
    }
    std::cout << "\n";
}
