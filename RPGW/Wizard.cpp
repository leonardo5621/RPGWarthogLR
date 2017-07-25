#include "Wizard.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Inventory.h"
#include "Character.h"
#include "Knight.h"
#include "Thief.h"

  Wizard::Wizard(std::string name,int a){

            nameW=name;
            Wisdom=5; //Power é igual a 5 no inicio por padrão

            std::cout<< "STATUS:"<<std::endl;
            std::cout<< "Class: Wizard"<<" Name: "<<nameW<<std::endl;
            std::cout<< "XP: "<<this->XP<<std::endl;
            std::cout<< "Wisdom: "<<Wisdom<<std::endl;
            std::cout<<"Eai crianca? quer ver um bagui magico?"<<std::endl<<"\n";

        }

        void Wizard::addWisdom(int w){

            Wisdom+=w;
        }
    int Wizard::getAttackPoints(){

            int attack;

        attack=(((strength*0.6+dexterity*0.4)*XP)/2);

        if(attack<=1){attack=1;};

        return attack;

    }

    int Wizard::getDefensePoints(){

         int defense;

        defense=(((constitution*0.6+dexterity*0.1+speed*0.3)*XP)/3)+(Wisdom/2);

        if(defense<1){defense=1;}

        return defense;

    }

    std::string Wizard::getname(){

        return nameW;
    }
