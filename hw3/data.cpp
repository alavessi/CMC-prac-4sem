#include "data.h"
#include <iostream>

int Data::Number = 0;

Data::Data(const char* _name, int _phone) : name(_name), phone(_phone), number(Number++){}

Data::Data(const Data& data)
{
    name = data.name;
    phone = data.phone;
    number = Number;
}

void Data::print() const
{
    std::cout << "Firm's name is " << name << ", phone number is " << phone << ", number of order is " << number << "\n";
}
