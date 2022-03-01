#include "liverpool.h"

Liverpool::Liverpool(int _points) : points(_points) {}

Liverpool::~Liverpool() {}

const char* Liverpool::stadium()
{
    return "Enfield";
}

const char* Liverpool::coach()
{
    return "Klopp";
}

const char* Liverpool::leader()
{
    return "Salah";
}

int Liverpool::UCL_winners()
{
    return 6;
}

