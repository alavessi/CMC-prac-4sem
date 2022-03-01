#pragma once
#include <string>

enum type_of_lex
{
    LEX_NULL,                                                                                                                       /*0*/
    LEX_AND, LEX_BOOL, LEX_BREAK, LEX_DO, LEX_ELSE, LEX_IF, LEX_FALSE, LEX_GOTO, LEX_INT, LEX_NOT, LEX_OR,                          /*11*/
    LEX_PROGRAM, LEX_READ, LEX_STRING, LEX_TRUE, LEX_VAR, LEX_WHILE, LEX_WRITE,                                                     /*18*/
    LEX_FIN,                                                                                                                        /*19*/
    LEX_SEMICOLON, LEX_COMMA, LEX_COLON, LEX_ASSIGN, LEX_LPAREN, LEX_RPAREN, LEX_EQ, LEX_LSS, LEX_GTR,                              /*28*/
    LEX_PLUS, LEX_MINUS, LEX_TIMES, LEX_SLASH, LEX_LEQ, LEX_NEQ, LEX_GEQ, LEX_BEGIN, LEX_END,                                       /*37*/
    LEX_NUM, LEX_STR,                                                                                                               /*39*/
    LEX_ID,                                                                                                                         /*40*/
    POLIZ_LABEL,                                                                                                                    /*41*/
    POLIZ_ADDRESS,                                                                                                                  /*42*/
    POLIZ_GO,                                                                                                                       /*43*/
    POLIZ_FGO                                                                                                                       /*44*/
};

class Lex
{
private:
    type_of_lex t_lex;
    int v_lex;
    std::string s_lex;

public:
    Lex(type_of_lex t = LEX_NULL, int v = 0, std::string s = "");
    type_of_lex get_type() const;
    int get_value() const;
    std::string get_string() const;
};
