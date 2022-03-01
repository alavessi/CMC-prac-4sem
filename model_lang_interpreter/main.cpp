#include "interpreter.h"

int main (int argc, char* argv[])
{
    try
    {
        /*Scanner scan(argv[1]);
        Lex cur_lex = scan.get_lex();
        while (cur_lex.get_type() != LEX_FIN)
        {
            std::cout << cur_lex;
            cur_lex = scan.get_lex();
        }*/

        /*Parser pars(argv[1]);
        pars.analyze();*/

        Interpretator inter(argv[1]);
        inter.interpretation();

        return 0;
    }
    catch (char c)
    {
        std::cout << "unexpected symbol: " << c <<std::endl;
        return 1;
    }
    catch (const char* str)
    {
        std::cout << str << std::endl;
        return 1;
    }
    catch (Lex l)
    {
        std::cout << "unexpected lexeme: " << l << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
