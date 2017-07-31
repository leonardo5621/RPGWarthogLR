/* Feito por Rodrigo de Abreu Boni e Leonardo Rodrigues*/
/* EESC-USP */
/// Trabalho do Warthog ///

///Feito com muita QUALIDADE E SINCRONIA///

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

    /// 8 Objetos Character ///
    Knight K1("Rodrigo", 5);
    K1.setStrength(40);
    K1.setDexterity(20);
    K1.setSpeed(10);
    K1.setConstitution(10);
    Character *Char1 = &K1;

    Knight K2("Leonardo", 5);
    K2.setStrength(45);
    K2.setDexterity(15);
    K2.setSpeed(15);
    K2.setConstitution(5);
    Character *Char2 = &K2;

    Knight K3("Joao", 5);
    K3.setStrength(40);
    K3.setDexterity(20);
    K3.setSpeed(10);
    K3.setConstitution(10);
    Character *Char3 = &K3;

     Wizard W1("JailsonMendes", 5);
    W1.setStrength(20);
    W1.setDexterity(25);
    W1.setSpeed(20);
    W1.setConstitution(25);
    Character *Char4 = &W1;

     Wizard W2("PauloGuina", 5);
    W2.setStrength(27);
    W2.setDexterity(15);
    W2.setSpeed(24);
    W2.setConstitution(25);
    Character *Char5 = &W2;

    Wizard W3("aCriatividadeAcabou", 5);
    W3.setStrength(30);
    W3.setDexterity(15);
    W3.setSpeed(17);
    W3.setConstitution(35);
    Character *Char6 = &W3;

    Thief T1("Baidu", 5);
    T1.setStrength(10);
    T1.setDexterity(15);
    T1.setSpeed(40);
    T1.setConstitution(25);
    Character *Char7 = &T1;

    Thief T2("DeMenor", 5);
    T2.setStrength(10);
    T2.setDexterity(15);
    T2.setSpeed(40);
    T2.setConstitution(25);
    Character *Char8 = &T2;

    ///Alguns Itens///

     HealthPotion LHP("Large Health Potion", 150, 300);
    HealthPotion MHP("Medium Health Potion", 100, 150);
    HealthPotion SHP("Small Health Potion", 50, 50);

    ManaPotion SMP("Small Mana Potion", 125, 100);
    Armor Armadura1("Knight Armor", 4000, 19, 20);
    Armor Armadura2("Thief Armor", 3000, 15, 10);
    Armor Armadura3("ArmoredTitan",5000,30,25);
    Weapon Espada1("Longsword", 1500, 10);
    Weapon Espada2("Longclaw", 2000, 15);
    Weapon Machado1("Hammer", 3000, 20);
    Weapon Machado2("Hammer2", 3500, 50);
    Weapon Dagger("Oblivion", 4000, 60);

    K1.myitems.insertItem(Espada1);
    K2.myitems.insertItem(Espada2);
    K3.myitems.insertItem(Machado1);

    W1.myitems.insertItem(Armadura1);
    W2.myitems.insertItem(Machado2);
    W3.myitems.insertItem(LHP);

    T1.myitems.insertItem(Armadura3);
    T2.myitems.insertItem(Dagger);

    K3.myitems.equipWeapon(Machado1);
    K2.myitems.equipWeapon(Espada2);
    W1.myitems.equipArmor(Armadura1);
    T1.myitems.equipArmor(Armadura3);
    T2.myitems.equipWeapon(Dagger);

    ///Times///

    Team TT1("Churrasqueira",blue);
    Team TT2("Fanta",red);

    TT1.addChar(Char3);
    TT1.addChar(Char8);
    TT1.addChar(Char1);
    TT1.addChar(Char4);

    TT2.addChar(Char5);
    TT2.addChar(Char6);
    TT2.addChar(Char7);
    TT2.addChar(Char2);

    std::cout<<"\n"<<"ROUND ONE"<<std::endl<<"\n";
    std::cout<<"\n"<<"FIGHT!!"<<std::endl<<"\n";

    Char1->attack(Char2);
    Char7->attack(Char3);
    Char8->attack(Char6);
    Char5->attack(Char4);
    Char3->attack(Char5);
    Char2->attack(Char8);
    Char4->attack(Char7);
    Char6->attack(Char1);

    TT1.resolveBattle(&TT2);


    std::cout<<"\n"<<"GET READY TO THE NEXT BATLLE!!!"<<std::endl<<"\n";


    return 0;
}
