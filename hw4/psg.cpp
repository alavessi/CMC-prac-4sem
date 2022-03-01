#include "psg.h"

PSG::PSG(int _points) : points(_points) {}

PSG::~PSG() {}

const char* PSG::stadium()
{
    return "Park de Prens";
}

const char* PSG::coach()
{
    return "Pochettino";
}

const char* PSG::leader()
{
    return "Mbappe";
}

int PSG::UCL_winners()
{
    return 0;
}

