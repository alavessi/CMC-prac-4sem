#pragma once
#include "barcelona.h"
#include "real_madrid.h"
#include "bayern.h"
#include "juventus.h"
#include "psg.h"
#include "man_city.h"
#include "liverpool.h"

class UCL
{
private:
    FC* clubs[7];
    
public:
    UCL();
    void print() const;
    ~UCL();
};
