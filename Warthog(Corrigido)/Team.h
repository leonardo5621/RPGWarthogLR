#ifndef TEAM_H
#define TEAM_H
#include "Character.h"

enum Color{
  blue,red,yellow,green,white,black
};

class Team
{
    public:
        Team(std::string,Color);
        std::string getName();
        std::string getResults();
        std::string toString();
        int resolveBattle(Team*);
        void addChar(Character*);
        void removeChar(Character*);
        void removeChar(int);
        Character searchChar(std::string);
        double getPoints();
        ~Team();

    private:

        std::string nameS;
        Color color;
        int win;
        int lose;
        int draw;
        int aux;
        Character *character[];
        int aux2;

};

#endif // TEAM_H
