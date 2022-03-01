#pragma once
#include "executer.h"

class Interpretator
{
private:
    Parser pars;
    Executer E;
public:
    Interpretator (const char* program);
    void interpretation();
};