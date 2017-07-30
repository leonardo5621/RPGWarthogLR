/* Feito por Rodrigo de Abreu Boni e Leonardo Rodrigues*/
/* EESC-USP */
/// Trabalho do Warthog ///

#include <iostream>
#include "Weapon.h"
#include "Item.h"
#include "Armor.h"
#include "Potion.h"
#include "HealthPotion.h"
#include "ManaPotion.h"
#include "Inventory.h"
#include "Character.h"
#include "Knight.h"
#include "Thief.h"
#include "Wizard.h"
#include "Team.h"

int main()
{
    std::cout<<"Bem-vindo Ao nosso RPG \n"<<std::endl;
    std::cout<<"By: Rodrigo&Leonardo \n"<<std::endl;

    Knight Kn1("Zeca",3);
    Knight Kn2("JailsonMendes",4);
    Wizard Wz1("BAM",1);
    Wizard Wz2("Humberto",6);
    Thief  Th1("ToSemCriatividade",3);
    Thief  Th2("Papaco",4);

    Character *CharK1=&Kn1;
    Character *CharK2=&Kn2;
    Character *CharW1=&Wz1;
    Character *CharW2=&Wz2;
    Character *CharT1=&Th1;
    Character *CharT2=&Th2;

     Kn1.setSpeed(20); Kn1.setStrength(17); Kn1.setDexterity(29); Kn1.setConstitution(15);

    Wz2.setSpeed(20); Wz2.setStrength(10); Wz2.setDexterity(15); Wz2.setConstitution(30);

    Knight Cav1("Rodrigo", 5);
    Character *Char1 = &Cav1;
    Thief Lad1("Leonardo", 5);
    Character *Char2 = &Lad1;
    Cav1.setStrength(50);
    Cav1.setDexterity(20);
    Cav1.setSpeed(10);

    Team TT1("Churrasqueira",blue);
    Team TT2("Fanta",red);


    TT1.addChar(CharK1);
    TT1.addChar(CharK2);
    TT1.addChar(CharW2);
    TT1.addChar(Char1);

    TT2.addChar(CharT1);
    TT2.addChar(CharT2);
    TT2.addChar(CharW1);
    TT2.addChar(Char2);


    HealthPotion LHP("Large Health Potion", 150, 300);
    HealthPotion MHP("Medium Health Potion", 100, 150);
    HealthPotion SHP("Small Health Potion", 50, 50);

    ManaPotion SMP("Small Mana Potion", 125, 100);
    Armor Armadura1("Knight Armor", 4000, 19, 20);
    Armor Armadura2("Thief Armor", 3000, 15, 10);
    Weapon Espada1("Longsword", 1500, 10);
    Weapon Espada2("Longclaw", 2000, 15);
    Weapon Machado1("Hammer", 3000, 20);
    Weapon Machado2("Hammer2", 3500, 50);

    Cav1.myitems.insertItem(Espada1);
    Cav1.myitems.insertItem(Espada2);
    Kn1.myitems.insertItem(Machado1);
    Kn1.myitems.insertItem(Armadura1);

    Kn2.myitems.insertItem(Machado2);

    Lad1.myitems.insertItem(LHP);

    Cav1.myitems.equipWeapon(Machado1);
    Cav1.myitems.equipWeapon(Espada2);
    Cav1.myitems.equipArmor(Armadura1);

    Cav1.attack(Char2);

    return 0;
}
