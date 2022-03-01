#include "lex.h"

Lex::Lex (type_of_lex t, int v, std::string s) : t_lex (t), v_lex (v), s_lex(s) {}

type_of_lex Lex::get_type() const
{ 
    return t_lex; 
}

int Lex::get_value() const
{ 
    return v_lex; 
}

std::string Lex::get_string() const
{
    return s_lex;
}
