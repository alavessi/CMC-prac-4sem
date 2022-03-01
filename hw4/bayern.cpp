#include "bayern.h"

Bayern::Bayern(int _points) : points(_points) {}

Bayern::~Bayern() {}

const char* Bayern::stadium()
{
    return "Allianz arena";
}

const char* Bayern::coach()
{
    return "Flick";
}

const char* Bayern::leader()
{
    return "Lewandowski";
}

int Bayern::UCL_winners()
{
    return 5;
}
