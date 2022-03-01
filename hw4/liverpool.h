#pragma once
#include "football_club.h"

class Liverpool: public FC
{
public:
    Liverpool(int _points = 0);
    ~Liverpool();
    const char* stadium();
    const char* coach();
    const char* leader();
    int UCL_winners();
    int points;
};
