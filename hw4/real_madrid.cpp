#include "real_madrid.h"

Real_Madrid::Real_Madrid(int _points) : points(_points) {}

Real_Madrid::~Real_Madrid() {}

const char* Real_Madrid::stadium()
{
    return "Santiago Bernabeu";
}

const char* Real_Madrid::coach()
{
    return "Zidane";
}

const char* Real_Madrid::leader()
{
    return "Modric";
}

int Real_Madrid::UCL_winners()
{
    return 13;
}
