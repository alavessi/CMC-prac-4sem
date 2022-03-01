#include "interpreter.h"

Interpretator::Interpretator (const char* program): pars (program) {}

void Interpretator::interpretation()
{
    pars.analyze();
    E.execute(pars.poliz);
}
