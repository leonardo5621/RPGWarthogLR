#include "Character.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Inventory.h"

Character::Character()
{
            HP=100;
            XP=1;
}

    std::string Character::getname(){

        return alias;
    }

    void Character::attack(Character *Ch2){

        int Al; //Aleatório
        int damage;

        srand(time(0));

        Al=(rand()%1000)+1;

        if(Al>=100/Ch2->getXp()){

                damage = this->getAttackPoints()- Ch2->getDefensePoints() + ((rand()%11)-5);

            if(damage<=1){damage=1;}

            std::cout<< this->getname()<<" Atacou "<< Ch2->getname()<< std::endl<< "\n";

            std::cout<< Ch2->getname()<<" Perdeu "<<damage<<" Pontos de vida"<< std::endl;

            Ch2->addHP(-damage);

        }

    }

    void Character::addXP(int a){

        XP+=a;

    }

    void Character::addHP(int hp){

        HP+=hp;
    }

    int Character::getXp(){

        return XP;
    }

     void Character::setSpeed(int s){

        speed=s;

    }

    void Character::setStrength(int S){

      if(S>(100-speed)){

        std::cout<< this->getname()<<" nao tem pontos suficientes"<<std::endl;
        strength=0;
      }else{
             strength=S;
      }

    }

    void Character::setDexterity(int d){

       if(d>(100-speed-strength)){

           std::cout<< this->getname()<<" nao tem pontos suficientes"<<std::endl;

           dexterity=0;

       }else{

       dexterity=d;

       }
    }

    void Character::setConstitution(int C){

        if(C>(100-speed-strength-dexterity)){

            std::cout<< this->getname()<<" nao tem pontos suficientes"<<std::endl;

            constitution=0;

        }else{
        constitution=C;
        }
    }

