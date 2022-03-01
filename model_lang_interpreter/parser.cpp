#include "parser.h"

Parser::Parser (const char* program) : scan (program) {}

void Parser::gl()
{
    curr_lex = scan.get_lex();
    c_type = curr_lex.get_type();
    c_val = curr_lex.get_value();
    c_str = curr_lex.get_string();
}

void Parser::analyze()
{
    gl();
    P();
    if (c_type != LEX_FIN)
    {
        throw curr_lex;
    }
    /*for (Lex l : poliz)
    {
        std::cout << l;
    }*/
    std::cout << std::endl << "Yes!!!" << std::endl;
}

void Parser::P()
{
    if (c_type == LEX_PROGRAM)
    {
        gl();
    }
    else
    {
        throw curr_lex;
    }
    B();
}

void Parser::D()
{
    gl();
    if (c_type != LEX_ID)
    {
        throw curr_lex;
    }
    else
    {
        st_int.push(c_val);
        poliz.push_back (Lex (POLIZ_ADDRESS, c_val));
        gl();
        if (c_type == LEX_ASSIGN)
        {
            A();
        }
        while (c_type == LEX_COMMA)
	    {
            gl();
            if (c_type != LEX_ID)
	        {
                throw curr_lex;
	        }
            else
	        {
                st_int.push(c_val);
                gl();
            }
            if (c_type == LEX_ASSIGN)
            {
                A();
            }
        }
    }
}

void Parser::A()
{
    gl();
    E();
    st_lex.pop();
    poliz.push_back (Lex (LEX_ASSIGN));
    if (c_type==LEX_NUM || c_type==LEX_STR)
    {
        gl();
    }
    else
    {
        throw curr_lex;
    }
}

void Parser::B()
{
    if (c_type == LEX_BEGIN)
    {
        bool statements_begin = false;
        gl();
        if (c_type==LEX_BOOL || c_type==LEX_INT || c_type==LEX_STRING)
        {
            type_of_lex curr_type = c_type;
            D();
            dec(curr_type);
        }
        else
        {
            statements_begin = true;
            S();
        }
        while (c_type == LEX_SEMICOLON)
        {
            gl();
            if (c_type==LEX_BOOL || c_type==LEX_INT || c_type==LEX_STRING)
            {
                if (statements_begin)
                {
                    throw "description after statement";
                }
                else
                {
                    type_of_lex curr_type = c_type;
                    D();
                    dec(curr_type);
                }
            }
            else
            {
                statements_begin = true;
                if (c_type == LEX_END)
                {
                    gl();
                    return;
                }
                S();
            }
        }
        if (c_type == LEX_END)
        {
            gl();
            return;
        }
        else
        {
            throw curr_lex;
        }
    }
    else if (c_type == LEX_END)
    {
        gl();
        return;
    }
    else
    {
        throw curr_lex;
    }
}

void Parser::S()
{
    int pl0, pl1, pl2, pl3;
    if (c_type == LEX_IF)
    {
        gl();
        E();
        eq_bool();
        pl2 = poliz.size();
        poliz.push_back (Lex());
        poliz.push_back (Lex(POLIZ_FGO));
        gl();
        if (c_type == LEX_BEGIN)
        {
            gl();
        }
        S();
        pl3 = poliz.size();
        poliz.push_back (Lex());
        poliz.push_back (Lex(POLIZ_GO));
        poliz[pl2] = Lex (POLIZ_LABEL, poliz.size());
        if (c_type == LEX_ELSE)
        {
            gl();
            S();
            poliz[pl3] = Lex (POLIZ_LABEL, poliz.size());
        }

        else
        {
            throw curr_lex;
        }
    }//end if
    else if (c_type == LEX_WHILE)
    {
        pl0 = poliz.size();
        gl();
        E();
        eq_bool();
        pl1 = poliz.size();
        poliz.push_back (Lex());
        poliz.push_back (Lex (POLIZ_FGO));
        if (c_type == LEX_DO)
        {
            gl();
            S();
            poliz.push_back (Lex (POLIZ_LABEL, pl0));
            poliz.push_back (Lex (POLIZ_GO));
            poliz[pl1] = Lex (POLIZ_LABEL, poliz.size());
        }
        else
        {
            throw curr_lex;
        }
    }//end while
    else if (c_type == LEX_READ)
    {
        gl();
        if (c_type == LEX_LPAREN)
        {
            gl();
            if (c_type == LEX_ID)
            {
                check_id_in_read();
                poliz.push_back (Lex (POLIZ_ADDRESS, c_val));
                gl();
            }
            else
            {
                throw curr_lex;
            }
            if (c_type == LEX_RPAREN)
            {
                gl();
                poliz.push_back (Lex (LEX_READ));
            }
            else
            {
                throw curr_lex;
            }
        }
        else
        {
            throw curr_lex;
        }
    }//end read
    else if (c_type == LEX_WRITE)
    {
        gl ();
        if (c_type == LEX_LPAREN)
        {
            gl();
            E();
            while (c_type == LEX_COMMA)
            {
                gl();
                E();
            }

            if (c_type == LEX_RPAREN)
            {
                gl();
                poliz.push_back (Lex (LEX_WRITE));
            }
            else
            {
                throw curr_lex;
            }
        }
        else
        {
            throw curr_lex;
        }
    }//end write
    else if (c_type == LEX_ID)
    {
        check_id();
        poliz.push_back (Lex (POLIZ_ADDRESS, c_val));
        gl();
        if (c_type == LEX_ASSIGN)
        {
            gl();
            E();
            eq_type();
            poliz.push_back (Lex (LEX_ASSIGN));
        }
        else
        {
            throw curr_lex;
        }
    }//assign-end
    else if (c_type == LEX_BEGIN)
    {
        gl();
        S();
        if (c_type == LEX_END)
            gl();
    }
    else
    {
        B();
    }
}

void Parser::E()
{
    E1();
    if (c_type==LEX_EQ  || c_type==LEX_LSS || c_type==LEX_GTR || c_type==LEX_LEQ || c_type==LEX_GEQ || c_type==LEX_NEQ)
    {
        st_lex.push (c_type);
        gl();
        E1();
        check_op();
    }
}

void Parser::E1()
{
    T();
    while (c_type == LEX_PLUS || c_type == LEX_MINUS || c_type == LEX_OR)
    {
        st_lex.push (c_type);
        gl();
        T();
        check_op();
    }
}

void Parser::T()
{
    F();
    while (c_type == LEX_TIMES || c_type == LEX_SLASH || c_type == LEX_AND)
    {
        st_lex.push (c_type);
        gl();
        F();
        check_op();
    }
}

void Parser::F()
{
    if (c_type == LEX_ID)
    {
        check_id();
        poliz.push_back (Lex (LEX_ID, c_val));
        gl();
    }
    else if (c_type == LEX_NUM)
    {
        st_lex.push (LEX_INT);
        poliz.push_back (curr_lex);
        gl();
    }
    else if (c_type == LEX_TRUE)
    {
        st_lex.push (LEX_BOOL);
        poliz.push_back (Lex (LEX_TRUE, 1));
        gl();
    }
    else if (c_type == LEX_FALSE)
    {
        st_lex.push (LEX_BOOL);
        poliz.push_back (Lex (LEX_FALSE, 0));
        gl();
    }
    else if (c_type == LEX_NOT)
    {
        gl();
        F();
        check_not();
    }
    else if (c_type == LEX_LPAREN)
    {
        gl();
        E();
        if (c_type == LEX_RPAREN)
        {
            gl();
        }
        else
        {
            throw curr_lex;
        }
    }
    else
    {
        throw curr_lex;
    }
}

////////////////////////////////////////////////////////////////

void Parser::dec(type_of_lex type)
{
    while (!st_int.empty ())
    {
        int i = from_st(st_int);
        if (Scanner::TID[i].get_declare())
        {
            throw "twice";
        }
        else
        {
            Scanner::TID[i].put_declare();
            Scanner::TID[i].put_type(type);
        }
    }
}

void Parser::check_id()
{
    if (Scanner::TID[c_val].get_declare())
    {
        st_lex.push (Scanner::TID[c_val].get_type());
    }
    else
    {
        throw "not declared";
    }
}

void Parser::check_op()
{
    type_of_lex t = LEX_INT, r = LEX_BOOL;
    type_of_lex t2 = from_st(st_lex);
    type_of_lex op = from_st(st_lex);
    type_of_lex t1 = from_st(st_lex);
    if (op == LEX_PLUS || op == LEX_MINUS || op == LEX_TIMES || op == LEX_SLASH)
    {
        r = LEX_INT;
    }
    if (op == LEX_OR || op == LEX_AND)
    {
        t = LEX_BOOL;
    }
    if (t1 == t2  &&  t1 == t)
    {
        st_lex.push(r);
    }
    else
    {
        throw "wrong types are in operation";
    }
    poliz.push_back (Lex (op));
}

void Parser::check_not()
{
    if (st_lex.top() != LEX_BOOL)
    {
        throw "wrong type is in not";
    }
    else
    {
        poliz.push_back (Lex (LEX_NOT));
    }
}

void Parser::eq_type()
{
    if (from_st(st_lex) != st_lex.top())
    {
        throw "wrong types are in :=";
    }
    st_lex.pop();
}

void Parser::eq_bool()
{
    if (st_lex.top() != LEX_BOOL)
    {
        throw "expression is not boolean";
    }
    st_lex.pop();
}

void Parser::check_id_in_read()
{
    if (!Scanner::TID[c_val].get_declare())
    {
        throw "not declared";
    }
}
