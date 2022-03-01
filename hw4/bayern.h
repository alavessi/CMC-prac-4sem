#pragma once
#include "football_club.h"

class Bayern: public FC
{
public:
    Bayern(int _points = 0);
    ~Bayern();
    const char* stadium();
    const char* coach();
    const char* leader();
    int UCL_winners();
    int points;
};
