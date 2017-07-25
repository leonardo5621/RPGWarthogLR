#ifndef WIZARD_H
#define WIZARD_H


class Wizard : public Character{

        public:

            Wizard(std::string,int);
            int getAttackPoints();
            int getDefensePoints();
            void addWisdom(int);
            std::string getname();

        protected:

            int Wisdom;
            std::string nameW;

    };

#endif // WIZARD_H
