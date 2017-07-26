#ifndef KNIGHT_H
#define KNIGHT_H


 class Knight : public Character{

        public:

            Knight(std::string,int);
            int getAttackPoints();
            int getDefensePoints();
            void addPower(int);
            std::string getname();

        protected:

            int power;
            std::string nameK;

    };


#endif // KNIGHT_H
