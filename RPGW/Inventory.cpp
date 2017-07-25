#include "Inventory.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Inventory::Inventory()
{
    spaces=0;
    gold=100;
}

double Inventory::getTotalGold(){

    return gold;
}

int Inventory::getAvailableSpace(){

    return spaces;
}

void Inventory::earnGold(int gg){

    gold+=gg;
}

void Inventory::spendGold(int g){

    gold+=g;
}
