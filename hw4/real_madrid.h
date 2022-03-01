#pragma once
#include "football_club.h"

class Real_Madrid: public FC
{
public:
    Real_Madrid(int _points = 0);
    ~Real_Madrid();
    const char* stadium();
    const char* coach();
    const char* leader();
    int UCL_winners();
    int points;
};
