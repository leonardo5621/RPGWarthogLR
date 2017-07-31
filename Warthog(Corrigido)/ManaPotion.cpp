#include "ManaPotion.h"
#include "Item.h"
#include "Potion.h"
#include <iostream>
#include "Character.h"

ManaPotion::ManaPotion(std::string name, double price, int restorepts) : Potion(name, price, restorepts)
{
    this->restorepts = restorepts;
}

ManaPotion::~ManaPotion()
{
    // destructor
}

void ManaPotion::WhoUses(Character* User)
{
    this->User=User;
}

void ManaPotion::use()
{
    User->addMP(restorepts);
}

ManaPotion* ManaPotion::clone()const
{
    return new ManaPotion(*this);
}
