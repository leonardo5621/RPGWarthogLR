#ifndef THIEF_H
#define THIEF_H


class Thief : public Character{

        public:

            Thief(std::string,int);
            int getAttackPoints();
            int getDefensePoints();
            void addStealth(int);
            std::string getname();

        protected:

            int Stealth;
            std::string nameT;

    };
#endif // THIEF_H
