#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "Team.h"
#include "Character.h"
#include "Thief.h"
#include "Wizard.h"
#include "Knight.h"

enum Color{

  blue,red,yellow,green,white,black
};

int main()
{
    std::cout<<"Bem-vindo Ao nosso RPG \n"<<std::endl;
    std::cout<<"By: Rodrigo(mito),Leonardo \n"<<std::endl;

    Knight Kn1("Zeca",3);
    Knight Kn2("JailsonMendes",4);
    Wizard Wz1("Azauri",1);
    Wizard Wz2("Humberto",6);

    Character *CharK1=&Kn1;
    Character *CharK2=&Kn2;
    Character *CharT1=&Wz1;
    Character *CharT2=&Wz2;


   Team TT1("Churrasqueira",blue);
    Team TT2("Fanta",red);

    TT1.addChar(CharK1);
    TT1.addChar(CharK2);

    TT2.addChar(CharT1);
    TT2.addChar(CharT2);

    TT1.resolveBattle(&TT2);

    std::cout<<TT1.getResults()<<std::endl;



    return 0;
}
