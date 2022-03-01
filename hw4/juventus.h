#pragma once
#include "football_club.h"

class Juventus: public FC
{
public:
    Juventus(int _points = 0);
    ~Juventus();
    const char* stadium();
    const char* coach();
    const char* leader();
    int UCL_winners();
    int points;
};
