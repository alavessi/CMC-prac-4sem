#include "man_city.h"

Manchester_City::Manchester_City(int _points) : points(_points) {}

Manchester_City::~Manchester_City() {}

const char* Manchester_City::stadium()
{
    return "Etihad stadium";
}

const char* Manchester_City::coach()
{
    return "Guardiola";
}

const char* Manchester_City::leader()
{
    return "de Bruyne";
}

int Manchester_City::UCL_winners()
{
    return 0;
}

