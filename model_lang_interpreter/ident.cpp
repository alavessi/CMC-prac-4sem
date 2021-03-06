#include "ident.h"

Ident::Ident()
{ 
    declare = false; 
    assign  = false; 
}

Ident::Ident(const std::string new_name)
{
    name = new_name;
    declare = false; 
    assign = false;
}

bool Ident::operator==(const std::string& s) const
{ 
    return name == s; 
}

std::string Ident::get_name() const
{ 
    return name; 
}

bool Ident::get_declare() const
{ 
    return declare; 
}

void Ident::put_declare()
{ 
    declare = true; 
}

type_of_lex Ident::get_type() const
{ 
    return type; 
}

void Ident::put_type(type_of_lex t)
{ 
    type = t; 
}

bool Ident::get_assign() const
{ 
    return assign; 
}

void Ident::put_assign()
{ 
    assign = true; 
}

int  Ident::get_value() const
{ 
    return value; 
}

void Ident::put_value(int v)
{ 
    value = v; 
}