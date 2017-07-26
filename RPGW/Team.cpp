#include "Team.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Inventory.h"
#include "Character.h"
#include "Knight.h"
#include "Wizard.h"
#include "Thief.h"
#include <sstream>

Team::Team(std::string TeamName,Color col)
{
    nameS=TeamName;
    aux2=1;

    color=col;

    win=0;lose=0;draw=0;
}

std::string Team::getName(){

    return nameS;

}

void Team::removeChar(Character*){


}

void Team::removeChar(int v){


}


std::string Team::toString(){

    std::string cor;

      if(color==0){
        cor=" Team:blue";}else if(color==1){
         cor=" Team:red"; }else if(color==2){
          cor=" Team:yellow";}else if(color==3){
            cor=" Team:white";}else{cor=" Team:black";}

        return nameS+cor;
}

std::string Team::getResults(){

        std::stringstream SW,SL,SD; //Variáveis para conversão int->string
        std::string Result;

        SW<<win;

        Result="Win: "+SW.str();

        SL<<lose;

         Result+=" Lose: "+SL.str();

          SD<<draw<<std::endl;

          Result+=" Draw: "+SD.str();

    return Result;
}

void Team::addChar(Character *CH){

    if(aux2==1){

        aux=0;
        aux2++;
    }

    character[aux]=CH; //Adiciona o endereço do personagem ao vetor

    aux++;

}

double Team::getPoints(){

    double pts=0;
    int a;

    for(a=0;a<aux;a++){

        pts+=character[a]->getHP();

    }

    return pts/aux;

}

int Team::resolveBattle(Team* Tm){


    int Resultado;

    if(this->getPoints()>= Tm->getPoints()){ //verifica se os pontos da equipe atacando é maior que os do oponente

        if(this->getPoints()==Tm->getPoints()){

            draw++;
          Resultado=this->draw;  //em caso de empate
          std::cout<<"We cool"<<std::endl;

        }else{ win++; Resultado=this->win; std::cout<<"Congratulations Hoss!"<<std::endl; } //em caso de vitoria

    }else{ lose++; Resultado=this->lose; std::cout<<"You Suck"<<std::endl; } //em caso de derrota

    return Resultado;

}

 Team::~Team(){

 }
