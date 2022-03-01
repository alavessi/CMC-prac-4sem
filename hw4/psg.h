#pragma once
#include "football_club.h"

class PSG: public FC
{
public:
    PSG(int _points = 0);
    ~PSG();
    const char* stadium();
    const char* coach();
    const char* leader();
    int UCL_winners();
    int points;
};
