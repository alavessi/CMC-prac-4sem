#include "executer.h"

void Executer::execute(std::vector<Lex>& poliz)
{
    Lex pc_el;
    std::stack<int> args;
    int i, j, index = 0, size = poliz.size();
    while (index < size)
    {
        pc_el = poliz[index];
        switch (pc_el.get_type())
        {
            case LEX_TRUE: case LEX_FALSE: case LEX_NUM: case POLIZ_ADDRESS: case POLIZ_LABEL:
                args.push(pc_el.get_value());
                break;

            case LEX_ID:
                i = pc_el.get_value();
                if (Scanner::TID[i].get_assign())
                {
                    args.push(Scanner::TID[i].get_value());
                }
                else
                {
                    throw "POLIZ: indefinite identifier";
                }
                break;

            case LEX_NOT:
                args.push(!from_st(args));
                break;

            case LEX_OR:
                args.push(from_st(args) || from_st(args));
                break;

            case LEX_AND:
                args.push(from_st(args) && from_st(args));
                break;

            case POLIZ_GO:
                index = from_st(args) - 1;
                break;

            case POLIZ_FGO:
                i = from_st(args);
                if (!from_st(args))
                {
                    index = i-1;
                }
                break;

            case LEX_WRITE:
                std::cout << from_st(args) << std::endl;
                break;

            case LEX_READ:
                int k;
                i = from_st(args);
                if (Scanner::TID[i].get_type() == LEX_INT)
                {
                    std::cout << "Input int value for " << Scanner::TID[i].get_name() << std::endl;
                    std::cin >> k;
                }
                else
                {
                    std::string j;
                    while (1)
                    {
                        std::cout << "Input boolean value (true or false) for" << Scanner::TID[i].get_name() << std::endl;
                        std::cin >> j;
                        if (j != "true" && j!= "false")
                        {
                            std::cout << "Error in input:true/false" << std::endl;
                            continue;
                        }
                        k = (j == "true") ? 1 : 0;
                        break;
                    }
                }
                Scanner::TID[i].put_value(k);
                Scanner::TID[i].put_assign ();
                break;

            case LEX_PLUS:
                args.push(from_st(args) + from_st(args));
                break;

            case LEX_TIMES:
                args.push(from_st(args) * from_st(args));
                break;

            case LEX_MINUS:
                args.push((-1)*from_st(args) + from_st(args));
                break;

            case LEX_SLASH:
                i = from_st(args);
                if (!i)
                {
                    args.push(from_st(args) / i);
                    break;
                }
                else
                {
                    throw "POLIZ:divide by zero";
                }
            case LEX_EQ:
                args.push(from_st(args) == from_st(args));
                break;

            case LEX_LSS:
                args.push(from_st(args) > from_st(args));
                break;

            case LEX_GTR:
                args.push(from_st(args) < from_st(args));
                break;

            case LEX_LEQ:
                args.push(from_st(args) >= from_st(args));
                break;

            case LEX_GEQ:
                args.push(from_st(args) <= from_st(args));
                break;

            case LEX_NEQ:
                args.push(from_st(args) != from_st(args));
                break;

            case LEX_ASSIGN:
                i = from_st(args);
                j = from_st(args);
                Scanner::TID[j].put_value(i);
                Scanner::TID[j].put_assign();
                break;

            default:
                throw "POLIZ: unexpected elem";
        }//end of switch
        ++index;
    };//end of while
    std::cout << "Finish of executing!!!" << std::endl;
}
