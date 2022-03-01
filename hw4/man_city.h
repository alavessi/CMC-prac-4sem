#pragma once
#include "football_club.h"

class Manchester_City: public FC
{
public:
    Manchester_City(int _points = 0);
    ~Manchester_City();
    const char* stadium();
    const char* coach();
    const char* leader();
    int UCL_winners();
    int points;
};
