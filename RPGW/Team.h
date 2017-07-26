#ifndef TEAM_H
#define TEAM_H


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
        //Character searchChar(std::string); Erro no compilador
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
