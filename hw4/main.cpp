#include "ucl.h"
#include "barcelona.h"
#include "real_madrid.h"
#include "bayern.h"
#include "psg.h"
#include <iostream>

int main()
{
    Barcelona barca(5);
    std::cout<<"Barcelona's stadium is "<<barca.Barcelona::stadium()<<"\n";
    std::cout<<"Barcelona's coach is "<<barca.Barcelona::coach()<<"\n";
    std::cout<<"Barcelona's best player is "<<barca.Barcelona::leader()<<"\n";
    std::cout<<"Barcelona won UCL "<<barca.Barcelona::UCL_winners()<<" times\n";

    Real_Madrid real;
    std::cout<<"Real's stadium is "<<real.Real_Madrid::stadium()<<"\n";
    std::cout<<"Real's coach is "<<real.Real_Madrid::coach()<<"\n";
    std::cout<<"Real's best player is "<<real.Real_Madrid::leader()<<"\n";
    std::cout<<"Real won UCL "<<real.Real_Madrid::UCL_winners()<<" times\n";

    Bayern munich(7);
    std::cout<<"Bayern's stadium is "<<munich.Bayern::stadium()<<"\n";
    std::cout<<"Bayern's coach is "<<munich.Bayern::coach()<<"\n";
    std::cout<<"Bayern's best player is "<<munich.Bayern::leader()<<"\n";
    std::cout<<"Bayern won UCL "<<munich.Bayern::UCL_winners()<<" times\n";

    Juventus juve(2);
    std::cout<<"Juventus's stadium is "<<juve.Juventus::stadium()<<"\n";
    std::cout<<"Juventus's coach is "<<juve.Juventus::coach()<<"\n";
    std::cout<<"Juventus's best player is "<<juve.Juventus::leader()<<"\n";
    std::cout<<"Juventus won UCL "<<juve.Juventus::UCL_winners()<<" times\n";

    PSG psg(6);
    std::cout<<"PSG's stadium is "<<psg.PSG::stadium()<<"\n";
    std::cout<<"PSG's coach is "<<psg.PSG::coach()<<"\n";
    std::cout<<"PSG's best player is "<<psg.PSG::leader()<<"\n";
    std::cout<<"PSG won UCL "<<psg.PSG::UCL_winners()<<" times\n";

    Manchester_City mc(8);
    std::cout<<"Manchester City's stadium is "<<mc.Manchester_City::stadium()<<"\n";
    std::cout<<"Manchester City's coach is "<<mc.Manchester_City::coach()<<"\n";
    std::cout<<"Manchester City's best player is "<<mc.Manchester_City::leader()<<"\n";
    std::cout<<"Manchester City won UCL "<<mc.Manchester_City::UCL_winners()<<" times\n";

    Liverpool liver(4);
    std::cout<<"Liverpool's stadium is "<<liver.Liverpool::stadium()<<"\n";
    std::cout<<"Liverpool's coach is "<<liver.Liverpool::coach()<<"\n";
    std::cout<<"Liverpool's best player is "<<liver.Liverpool::leader()<<"\n";
    std::cout<<"Liverpool won UCL "<<liver.Liverpool::UCL_winners()<<" times\n";

    UCL cup;
    std::cout<<"Top teams in the world are:\n";
    cup.print();

    return 0;
}
