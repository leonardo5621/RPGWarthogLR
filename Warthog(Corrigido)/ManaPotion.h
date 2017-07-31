#ifndef MANAPOTION_H
#define MANAPOTION_H
#include "Item.h"
#include "Potion.h"
#include <iostream>
#include "Character.h"

class ManaPotion: public Potion
{
    public:
        ManaPotion(std::string, double, int);
        virtual ManaPotion* clone()const;
        ~ManaPotion();
        void use();
        void WhoUses(Character *);
    private:
        Character *User;
};

#endif // MANAPOTION_H
