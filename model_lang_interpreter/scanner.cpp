#include "scanner.h"
#include <algorithm>
#include <exception>

std::vector<Ident> Scanner::TID = {};

int Scanner::put(const std::string& buf)
{
    std::vector<Ident>::iterator k;
    if ((k = find (TID.begin(), TID.end(), buf)) != TID.end())
    {
        return k - TID.begin();
    }
    TID.push_back(Ident(buf));
    return TID.size() - 1;
}

Scanner::Scanner(const char* program)
{
    if (!(fp = fopen(program, "r")))
    {
        throw "can't open file";
    }
}

Scanner::~Scanner()
{
    TID.clear();
}

int Scanner::look(const std::string& buf, const char** list)
{
    int i = 0;
    while (list[i])
    {
        if (buf == list[i])
        {
            return i;
        }
        i++;
    }
    return 0;
}

const char* Scanner::TW [] = {"", "and", "bool", "break", "do", "else", "if", "false", "goto", "int", "not", "or", "program",
                      "read", "string", "true", "var", "while", "write", NULL};

const char* Scanner::TD [] = {"@", ";", ",", ":", "=", "(", ")", "==", "<", ">", "+", "-", "*", "/", "<=", "!=", ">=", "{", "}", NULL};

Lex Scanner::get_lex()
{
    enum state {H, IDENT, NUMB, SLASH, COM, STAR, STR, ALE, NEQ};
    int d, j;
    std::string buf;
    state CS = H;
    do
    {
        char c = fgetc(fp);
        switch (CS)
        {
            case H:
                if (c==' ' || c == '\n' || c== '\r' || c == '\t');
                    else if (isalpha(c))
                    {
                        buf.push_back(c);
                        CS = IDENT;
                    }
                    else if (isdigit(c))
                    {
                        d = c - '0';
                        CS = NUMB;
                    }
                    else if (c == '/')
                    {
                        CS = SLASH;
                    }
                    else if (c == '"')
                    {
                        CS = STR;
                    }
                    else if (c == '=' || c == '<' || c == '>')
                    {
                        buf.push_back(c);
                        CS = ALE;
                    }
                    else if (feof(fp))
                    {
                        return Lex (LEX_FIN);
                    }
                    else if (c == '!')
                    {
                        buf.push_back(c);
                        CS = NEQ;
                    }
                    else
                    {
                        buf.push_back(c);
                        if ((j = look(buf, TD)))
                        {
                            return Lex((type_of_lex)(j + (int) LEX_FIN), j);
                        }
                        else
                        {
                            throw c;
                        }
                    }
                    break;
            case IDENT:
                if (isalpha(c) || isdigit(c))
                {
                    buf.push_back(c);
                }
                else
                {
                    ungetc(c, fp);
                    if ((j = look(buf, TW)))
                    {
                        return Lex((type_of_lex) j, j);
                    }
                    else
                    {
                        j = put(buf);
                        return Lex(LEX_ID, j);
                    }
                }
                break;
            case NUMB:
                if (isdigit(c))
                {
                    d = d * 10 + (c - '0');
                }
                else
                {
                    ungetc(c, fp);
                    return Lex(LEX_NUM, d);
                }
                break;
            case SLASH:
                if (c == '*')
                {
                    CS = COM;
                }
                else
                {
                    ungetc(c,fp);
                    CS = H;
                    return Lex(LEX_SLASH, 33);
                }
                break;
            case COM:
                if (c == '*')
                {
                    CS = STAR;
                }
                break;
            case STAR:
                if (c == '/')
                {
                    CS = H;
                }
                else if (c != '*')
                {
                    ungetc(c,fp);
                    CS = COM;
                }
                break;
            case STR:
                if (c == '"')
                {
                    CS = H;
                    if ((j = look(buf, TW)))
                    {
                        return Lex((type_of_lex) j, j);
                    }
                    else
                    {
                        j = put(buf);
                        return Lex(LEX_STR, j);
                    }
                }
                else
                {
                    buf.push_back(c);
                }
                break;
            case ALE:
                if (c == '=')
                {
                    buf.push_back(c);
                    j = look(buf, TD);
                    return Lex((type_of_lex) (j + (int) LEX_FIN), j);
                }
                else
                {
                    ungetc(c, fp);
                    j = look(buf, TD);
                    return Lex((type_of_lex) (j + (int) LEX_FIN), j);
                }
                break;
            case NEQ:
                if (c == '=')
                {
                    buf.push_back(c);
                    j = look(buf, TD);
                    return Lex (LEX_NEQ, j);
                }
                else
                {
                    throw '!';
                }
                break;
        } //end switch
    } while (true);
}

std::ostream& operator<<(std::ostream &s, Lex l)
{
    std::string t;
    if (l.get_type() <= LEX_WRITE)
        t = Scanner::TW[l.get_type()];
    else if (l.get_type() >= LEX_FIN && l.get_type() <= LEX_END)
        t = Scanner::TD[l.get_type() - LEX_FIN];
    else if (l.get_type() == LEX_NUM)
        t = "NUMB";
    else if (l.get_type() == LEX_STR)
        t = "STR";
    else if (l.get_type() == LEX_ID)
        t = Scanner::TID[l.get_value()].get_name();
    else if (l.get_type() == POLIZ_LABEL)
        t = "Label";
    else if (l.get_type() == POLIZ_ADDRESS)
        t = "Addr";
    else if (l.get_type() == POLIZ_GO)
        t = "!";
    else if (l.get_type() == POLIZ_FGO)
        t = "!F";
    else
        throw l;
    s << '(' << t << ',' << l.get_value() << ");" << std::endl;
    return s;
}
