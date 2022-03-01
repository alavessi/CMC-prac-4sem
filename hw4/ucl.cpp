#include "ucl.h"
#include <typeinfo>
#include <iostream>

UCL::UCL()
{
    clubs[0] = new Barcelona;
    clubs[1] = new Real_Madrid;
    clubs[2] = new Bayern;
    clubs[3] = new Juventus;
    clubs[4] = new PSG;
    clubs[5] = new Manchester_City;
    clubs[6] = new Liverpool;
}

UCL::~UCL()
{
    for (int i = 0; i < 7; i++)
    {
        delete clubs[i];
    }
}

void UCL::print() const
{
    for (int i = 0; i < 7; i++)
    {
        std::cout << typeid(*clubs[i]).name() << " ";
    }
    std::cout << "\n";
}
