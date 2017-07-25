#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Inventory.h"
#include "Character.h"
#include "Knight.h"
#include "Wizard.h"
#include "Team.h"
#include <sstream>

enum Color{

  blue,red,yellow,green,white,black
};
int main()
{
    std::cout<<"Bem-vindo Ao nosso RPG delicia \n"<<std::endl;
    std::cout<<"By: Rodrigo(mito),Leonardo(Cara que ta escrevendo isso aqui) \n"<<std::endl;

    Knight Kn1("Zeca",3);
    Knight Kn2("JailsonMendes",4);
    Wizard Wz1("Azauri",1);
    Wizard Wz2("Humberto",6);

    Character *CharK1=&Kn1;
    Character *CharK2=&Kn2;
    Character *CharW1=&Wz1;
    Character *CharW2=&Wz2;


    Kn1.setSpeed(20); Kn1.setStrength(17); Kn1.setDexterity(29); Kn1.setConstitution(15);

    Kn2.setSpeed(20); Kn2.setStrength(10); Kn2.setDexterity(25); Kn2.setConstitution(30);

    Wz1.setSpeed(15); Wz1.setStrength(10); Wz1.setDexterity(30); Wz1.setConstitution(20);

    Wz2.setSpeed(15); Wz2.setStrength(25); Wz2.setDexterity(25); Wz2.setConstitution(15);


    CharK1->attack(CharK2);

    return 0;
}
