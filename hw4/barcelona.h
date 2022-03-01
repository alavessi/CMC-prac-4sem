#pragma once
#include "football_club.h"

class Barcelona: public FC
{
public:
    Barcelona(int _points = 0);
    ~Barcelona();
    const char* stadium();
    const char* coach();
    const char* leader();
    int UCL_winners();
    int points;
};
