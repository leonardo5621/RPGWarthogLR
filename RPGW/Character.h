#ifndef CHARACTER_H
#define CHARACTER_H


class Character
{
    public:
        Character();
        virtual std::string getname();
        virtual void attack(Character*);
        void addXP(int xp);
        void setSpeed(int s);
        void setStrength(int S);
        void setDexterity(int d);
        void setConstitution(int C);
        int getXp();
        void addHP(int hp);
        int getHP();
    private:
        std::string alias;
        int HP;
        int MP;
    protected:
        virtual int getDefensePoints()=0;
        virtual int getAttackPoints()=0;
        int XP;
        int strength;
        int speed;
        int dexterity;
        int constitution;
};

#endif // CHARACTER_H
