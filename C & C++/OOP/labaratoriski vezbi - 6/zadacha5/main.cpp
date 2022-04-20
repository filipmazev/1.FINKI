#include <iostream>
#include <string.h>

class Team
{
protected:
    char *name{nullptr}; int wins{0}, losses{0};
public:
    Team(){ this->name = nullptr; this->wins = 0; this->losses = 0; }
    ~Team(){ delete[] this->name; this->name = nullptr; }
};

class Foodball_Team : protected Team
{
private:
    int red_card{0}, yellow_card{0}, ties{0};
public:
    Foodball_Team(){ this->red_card = 0; this->yellow_card = 0; this-> ties = 0; }

    Foodball_Team(char *name, int wins, int losses, int red_card, int yellow_card, int ties){
        this->name = new char[strlen(name)+1]; strcpy(this->name,name);
        this->wins = wins; this->losses = losses; this->red_card = red_card; this->yellow_card = yellow_card; this->ties = ties;
    }

    void print(){ std::cout<<"Ime: "<<this->name<<" Pobedi: "<<this->wins<<" Porazi: "<<this->losses<<" Nereseni: "<<this->ties<<" Poeni: "<<points()<<std::endl; }
    int points(){ return 3*this->wins + this->ties; }

    ~Foodball_Team(){}
};

int main()
{
	char name[15]; int wins, losses, red_card, yellow_card, ties;
	std::cin>>name>>wins>>losses>>red_card>>yellow_card>>ties;
	Foodball_Team f1(name,wins,losses,red_card,yellow_card,ties); f1.print();
	return 0;
}
