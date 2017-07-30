#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H
#include "Item.h"
#include "Potion.h"
#include <iostream>
#include "Character.h"

class HealthPotion: public Potion
{
    public:
        HealthPotion(std::string, double, int);
        virtual HealthPotion* clone()const;
        ~HealthPotion();
        void use();
        void WhoUses(Character *);
    private:
        Character *User;
};

#endif // HEALTHPOTION_H
