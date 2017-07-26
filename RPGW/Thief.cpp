#include "Thief.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "Inventory.h"
#include "Character.h"
#include "Knight.h"
#include "Wizard.h"
#include "Team.h"

Thief::Thief(std::string name,int a)
{

            nameT=name;
            Stealth=5; //Stealth é igual a 5 no inicio por padrão

            std::cout<< "STATUS:"<<std::endl;
            std::cout<< "Class: Thief"<<" Name: "<<nameT<<std::endl;
            std::cout<< "XP: "<<this->XP<<std::endl;
            std::cout<< "Stealth: "<<Stealth<<std::endl;
            std::cout<<"Vou te Roubei"<<std::endl<<"\n";
}

 void Thief::addStealth(int S){

            Stealth+=S;
        }

    int Thief::getAttackPoints(){

            int attack;

        attack=(((strength*0.6+dexterity*0.4)*XP)/2)+Stealth;

        if(attack<=1){attack=1;};

        return attack;

    }

    int Thief::getDefensePoints(){

         int defense;

        defense=(((constitution*0.6+dexterity*0.1+speed*0.3)*XP)/3);

        if(defense<1){defense=1;}

        return defense;

    }

    std::string Thief::getname(){

        return nameT;
    }
