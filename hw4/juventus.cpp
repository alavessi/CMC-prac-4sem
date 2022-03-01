#include "juventus.h"

Juventus::Juventus(int _points) : points(_points) {}

Juventus::~Juventus() {}

const char* Juventus::stadium()
{
    return "Allianz Stadium";
}

const char* Juventus::coach()
{
    return "Pirlo";
}

const char* Juventus::leader()
{
    return "Ronaldo";
}

int Juventus::UCL_winners()
{
    return 2;
}

