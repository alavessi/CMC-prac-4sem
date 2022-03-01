#pragma once
#include "ident.h"
#include <vector>
#include <string>
#include <iostream>

class Scanner
{
private:
    FILE* fp;
    int look(const std::string& buf, const char** list);
    int put(const std::string& buf);
    
public:
    Scanner(const char* program);
    ~Scanner();
    static const char* TW [];
    static const char* TD [];
    static std::vector<Ident> TID;
    Lex get_lex();
};

std::ostream& operator<<(std::ostream &s, Lex l);
