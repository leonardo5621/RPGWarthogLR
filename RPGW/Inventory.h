#ifndef INVENTORY_H
#define INVENTORY_H


class Inventory
{
    public:
        Inventory();
        double getTotalGold();
        int getAvailableSpace();
        void spendGold(double);
        void earnGold(double);
        void setSpaces(int);
        Item *searchItem(std::string);
        Item *searchItem(int);
        void insertItem(Item*);
        void removeItem(std::string);
        void removeItem(int);

    private:

        int spaces;
        double gold;
        Item,bool items
};

#endif // INVENTORY_H
