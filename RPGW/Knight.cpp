#include "Knight.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Inventory.h"
#include "Character.h"
#include "Knight.h"
#include "Wizard.h"
#include "Thief.h"
#include <sstream>


  Knight::Knight(std::string name,int a){

            nameK=name;
            power=5; //Power é igual a 5 no inicio por padrão

            std::cout<< "STATUS:"<<std::endl;
            std::cout<< "Class: Knight"<<" Name: "<<nameK<<std::endl;
            std::cout<< "XP: "<<this->XP<<std::endl;
            std::cout<< "Power: "<<power<<std::endl;
            std::cout<<"I am a Knitgh and I gotta a fricking big sword"<<std::endl<<"\n";

        }

    int Knight::getAttackPoints(){

            int attack;

        attack=(((strength*0.6+dexterity*0.4)*XP)/2);

        if(attack<=1){attack=1;};

        return attack;

    }

    int Knight::getDefensePoints(){

         int defense;

        defense=(((constitution*0.6+dexterity*0.1+speed*0.3)*XP)/3)+power;

        if(defense<1){defense=1;}

        return defense;

    }

    void Knight::addPower(int p){

        power+=p;
    }

    std::string Knight::getname(){

        return nameK;
    }
