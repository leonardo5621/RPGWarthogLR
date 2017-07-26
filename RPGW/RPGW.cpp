#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

enum Color{

  blue,red,yellow,green,white,black
};

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

Character::Character()
{
            HP=100;
            XP=1;
}

    std::string Character::getname(){

        return alias;
    }

    void Character::attack(Character *Ch2){

        int Al; //Aleatório
        int damage;

        srand(time(0));

        Al=(rand()%1000)+1;

        if(Al>=100/Ch2->getXp()){ //Chance de acertar o ataque

                damage = this->getAttackPoints()- Ch2->getDefensePoints() + ((rand()%11)-5);

            if(damage<=1){damage=1;}

            std::cout<< this->getname()<<" Atacou "<< Ch2->getname()<< std::endl<< "\n";

            std::cout<< Ch2->getname()<<" Perdeu "<<damage<<" Pontos de vida"<< std::endl<<"\n";

            Ch2->addHP(-damage);

        }else{ std::cout<<"ERROU!!!"<<std::endl<<"\n";} //Caso contrário o personagem erra

    }

    void Character::addXP(int a){

        XP+=a;

    }

    void Character::addHP(int hp){

        HP+=hp;
    }

    int Character::getXp(){

        return XP;
    }

     void Character::setSpeed(int s){

        speed=s;

    }

    void Character::setStrength(int S){

      if(S>(100-speed)){ //Verifica se não passou do limite de 100 pontos

        std::cout<< this->getname()<<" nao tem pontos suficientes"<<std::endl;
        strength=0;
      }else{
             strength=S;
      }

    }

    void Character::setDexterity(int d){

       if(d>(100-speed-strength)){ //Verifica se não passou do limite de 100 pontos


           std::cout<< this->getname()<<" nao tem pontos suficientes"<<std::endl;

           dexterity=0;

       }else{

       dexterity=d;

       }
    }

    void Character::setConstitution(int C){

        if(C>(100-speed-strength-dexterity)){ //Verifica se não passou do limite de 100 pontos

            std::cout<< this->getname()<<" nao tem pontos suficientes"<<std::endl;

            constitution=0;

        }else{
        constitution=C;
        }
    }

    int Character::getHP(){

        return HP;
    }


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
        //Character searchChar(std::string);
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

Team::Team(std::string TeamName,Color col)
{
    nameS=TeamName;
    aux2=1;

    color=col;

    win=0;lose=0;draw=0;
}

std::string Team::getName(){

    return nameS;

}

void Team::removeChar(Character*){


}

void Team::removeChar(int v){


}


std::string Team::toString(){

    std::string cor;

      if(color==0){
        cor=" Team:blue";}else if(color==1){
         cor=" Team:red"; }else if(color==2){
          cor=" Team:yellow";}else if(color==3){
            cor=" Team:white";}else{cor=" Team:black";}

        return nameS+cor;
}

std::string Team::getResults(){

        std::stringstream SW,SL,SD;
        std::string Result;

        SW<<win;

        Result="Win: "+SW.str();

        SL<<lose;

         Result+=" Lose: "+SL.str();

          SD<<draw<<std::endl;

          Result+=" Draw: "+SD.str();

    return Result;
}

void Team::addChar(Character *CH){

    if(aux2==1){

        aux=0;
        aux2++;
    }

    character[aux]=CH;

    aux++;

}

double Team::getPoints(){

    double pts=0;
    int a;

    for(a=0;a<aux;a++){

        pts+=character[a]->getHP();

    }

    return pts/aux;

}

int Team::resolveBattle(Team* Tm){


    int Resultado;

    if(this->getPoints()>= Tm->getPoints()){ //verifica se os pontos da equipe atacando é maior que os do oponente

        if(this->getPoints()==Tm->getPoints()){

            draw++;
          Resultado=this->draw;  //em caso de empate
          std::cout<<"We cool"<<std::endl;

        }else{ win++; Resultado=this->win; std::cout<<"Congratulations Hoss!"<<std::endl; } //em caso de vitoria

    }else{ lose++; Resultado=this->lose; std::cout<<"You Suck"<<std::endl; } //em caso de derrota

    return Resultado;

}

 Team::~Team(){

 }

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

    Wizard::Wizard(std::string name,int a){

            nameW=name;
            Wisdom=5; //Power é igual a 5 no inicio por padrão

            std::cout<< "STATUS:"<<std::endl;
            std::cout<< "Class: Wizard"<<" Name: "<<nameW<<std::endl;
            std::cout<< "XP: "<<this->XP<<std::endl;
            std::cout<< "Wisdom: "<<Wisdom<<std::endl;
            std::cout<<"Eai crianca? quer ver um bagui magico?"<<std::endl<<"\n";

        }

        void Wizard::addWisdom(int w){

            Wisdom+=w;
        }
    int Wizard::getAttackPoints(){

            int attack;

        attack=(((strength*0.6+dexterity*0.4)*XP)/2);

        if(attack<=1){attack=1;};

        return attack;

    }

    int Wizard::getDefensePoints(){

         int defense;

        defense=(((constitution*0.6+dexterity*0.1+speed*0.3)*XP)/3)+(Wisdom/2);

        if(defense<1){defense=1;}

        return defense;

    }

    std::string Wizard::getname(){

        return nameW;
    }

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

     Knight::Knight(std::string name,int a){

            nameK=name;
            power=5; //Power é igual a 5 no inicio por padrão

            std::cout<< "STATUS:"<<std::endl;
            std::cout<< "Class: Knight"<<" Name: "<<nameK<<std::endl;
            std::cout<< "XP: "<<this->XP<<std::endl;
            std::cout<< "Power: "<<power<<std::endl;
            std::cout<<"I am a Knitgh and I gotta a fricking big sword"<<std::endl<<"\n";

        }

    int Knight::getAttackPoints(){

            int attack;

        attack=(((strength*0.6+dexterity*0.4)*XP)/2);

        if(attack<=1){attack=1;};

        return attack;

    }

    int Knight::getDefensePoints(){

         int defense;

        defense=(((constitution*0.6+dexterity*0.1+speed*0.3)*XP)/3)+power;

        if(defense<1){defense=1;}

        return defense;

    }

    void Knight::addPower(int p){

        power+=p;
    }

    std::string Knight::getname(){

        return nameK;
    }

    class Thief : public Character
{
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
    Thief::Thief(std::string name,int a)
{

            nameT=name;
            Stealth=5; //Stealth é igual a 5 no inicio por padrão

            std::cout<< "STATUS:"<<std::endl;
            std::cout<< "Class: Thief"<<" Name: "<<nameT<<std::endl;
            std::cout<< "XP: "<<this->XP<<std::endl;
            std::cout<< "Stealth: "<<Stealth<<std::endl;
            std::cout<<"Vou te Roubei"<<std::endl<<"\n";
}

 void Thief::addStealth(int S){

            Stealth+=S;
        }

    int Thief::getAttackPoints(){

            int attack;

        attack=(((strength*0.6+dexterity*0.4)*XP)/2)+Stealth;

        if(attack<=1){attack=1;};

        return attack;

    }

    int Thief::getDefensePoints(){

         int defense;

        defense=(((constitution*0.6+dexterity*0.1+speed*0.3)*XP)/3);

        if(defense<1){defense=1;}

        return defense;

    }

    std::string Thief::getname(){

        return nameT;
    }


int main()
{
    std::cout<<"Bem-vindo Ao nosso RPG \n"<<std::endl;
    std::cout<<"By: Rodrigo(mito),Leonardo \n"<<std::endl;

    Knight Kn1("Zeca",3);
    Knight Kn2("JailsonMendes",4);
    Thief Th1("Azauri",1);
    Thief Th2("Humberto",6);

    Character *CharK1=&Kn1;
    Character *CharK2=&Kn2;
    Character *CharT1=&Th1;
    Character *CharT2=&Th2;


   Team TT1("Churrasqueira",blue);
    Team TT2("Fanta",red);

    TT1.addChar(CharK1);
    TT1.addChar(CharK2);

    TT2.addChar(CharT1);
    TT2.addChar(CharT2);

    TT1.resolveBattle(&TT2);

    std::cout<<TT1.getResults()<<std::endl;



    return 0;
}
