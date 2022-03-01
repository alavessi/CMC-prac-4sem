#include "barcelona.h"

Barcelona::Barcelona(int _points): points(_points) {}

Barcelona::~Barcelona() {}

const char* Barcelona::stadium()
{
    return "Camp Nou";
}

const char* Barcelona::coach()
{
    return "Koeman";
}

const char* Barcelona::leader()
{
    return "Messi";
}

int Barcelona::UCL_winners()
{
    return 5;
}
