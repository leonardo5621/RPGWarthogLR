#include "Team.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Inventory.h"
#include "Character.h"
#include "Knight.h"
#include "Wizard.h"
#include <sstream>

Team::Team(std::string TeamName,Color col)
{
    nameS=TeamName;

    character=new Character[4];

    color=col;

    win=0;lose=0;draw=0;
}

std::string Team::toString(){

    std::string cor;

    if(color==0){
        cor=" Team:blue";}else if(collor==1){
        cor=" Team:red"; }else if(collor==2){
        cor=" Team:yellow";}else if(collor==3){
        cor=" Team:white";}else{cor=" Team:black";}

        return nameS+cor;
}

std::string Team::getResults(){

        std::stringstream SS;
        std::string Result;

        SS<<win<<std::endl;

        Result="Win: "+SS.str();

        SS<<lose<<std::endl;

         Result+=" Lose: "+SS.str();

          SS<<draw<<std::endl;

          Result+=" Draw: "+SS.str();


}

void Team::addChar(Character *CH){

    if(character[0]==NULL){

        aux=0;
    }

    character[aux]=CH;

    aux++;

}

double Team::getPoints(){

    double pts= (character[0]->getHP()+character[1]->getHP()+character[2]->getHP()+character[3]->getHP())/4;

    return pts;

}

int Team::resolveBattle(&Team){


    Team *TB=&Team;
    int Resultado;

    if(this->getPoints()>=TB->getPoints()){

        if(this->getPoints()==TB->getPoints()){

          Resultado=this->draw + 1;

        }else{ Resultado=this->win + 1;}
    }else{ Resultado=this->lose +1;}

    return Resultado;

}

 Team::~Team(){

    delete[] character;
 }
