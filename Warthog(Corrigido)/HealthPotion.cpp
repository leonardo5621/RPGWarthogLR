#include "HealthPotion.h"
#include "Item.h"
#include "Potion.h"
#include <iostream>
#include "Character.h"

HealthPotion::HealthPotion(std::string name, double price, int restorepts) : Potion(name, price, restorepts)
{
    this->restorepts = restorepts;
}

HealthPotion::~HealthPotion()
{
    // destructor
}

void HealthPotion::use()
{
    User->addHP(restorepts);
}

void HealthPotion::WhoUses(Character* User)
{
    this->User=User;
}

HealthPotion* HealthPotion::clone()const
{
    return new HealthPotion(*this);
}
