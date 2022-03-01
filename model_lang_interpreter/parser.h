#pragma once
#include "scanner.h"
#include <stack>

template <class T>
auto from_st (T& st)
{
    auto i = st.top();
    st.pop();
    return i;
}

class Parser
{
private:
    Lex curr_lex;
    type_of_lex c_type;
    int c_val;
    std::string c_str;
    Scanner scan;
    std::stack <int> st_int;
    std::stack <std::string> st_string;
    std::stack <type_of_lex> st_lex;
    void P();
    void D();
    void B();
    void A();
    void S();
    void E();
    void E1();
    void T();
    void F();
    void dec (type_of_lex type);
    void check_id();
    void check_op();
    void check_not();
    void eq_type();
    void eq_bool();
    void check_id_in_read();
    void gl();

public:
    std::vector<Lex> poliz;
    Parser (const char* program);
    void analyze();
};
