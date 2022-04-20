#include <iostream>
#include <string.h>

class NBA_Player
{
protected:
    char *name{nullptr}, *team{nullptr};
    double avg_score{0.00}, avg_assists{0.00}, avg_rebounds{0.00};
public:
    NBA_Player(){ this->name = nullptr; this->team = nullptr; this->avg_score = 0.00; this->avg_assists = 0.00; this->avg_rebounds = 0.00; }

    NBA_Player(char *name, char *team, double avg_score, double avg_assists, double avg_rebounds){
        this->name = new char[strlen(name)+1]; strcpy(this->name,name);
        this->team = new char[strlen(team)+1]; strcpy(this->team,team);
        this->avg_score = avg_score; this->avg_assists = avg_assists; this->avg_rebounds = avg_rebounds;
    }

    NBA_Player(const NBA_Player &n_p){
        if(this != &n_p){
            delete[] this->name; this->name = new char[strlen(n_p.name)+1]; strcpy(this->name,n_p.name);
            delete[] this->team; this->team = new char[strlen(n_p.team)+1]; strcpy(this->team, n_p.team);
            this->avg_score = n_p.avg_score; this->avg_assists = n_p.avg_assists; this->avg_rebounds = n_p.avg_rebounds;
        }
    }

    inline NBA_Player &operator = (const NBA_Player &n_p){
        if(this != &n_p){
            delete[] this->name; this->name = new char[strlen(n_p.name)+1]; strcpy(this->name,n_p.name);
            delete[] this->team; this->team = new char[strlen(n_p.team)+1]; strcpy(this->team, n_p.team);
            this->avg_score = n_p.avg_score; this->avg_assists = n_p.avg_assists; this->avg_rebounds = n_p.avg_rebounds;
        } return *this;
    }

    ~NBA_Player(){ delete[] this->name; this->name = nullptr; delete[] this->team; this->team = nullptr; }

    inline double rating() noexcept { return this->avg_score*0.45 + this->avg_assists*0.30 + this->avg_rebounds*0.25; }

    inline void print(){
        std::cout << this->name << " - " << this->team << std::endl << "Points: " << avg_score << std::endl
        << "Assists: " << avg_assists << std::endl << "Rebounds: " << avg_rebounds << std::endl << "Rating: " << rating()<<std::endl;
    }

};

class AllStarPlayer : protected NBA_Player
{
private:
    double avg_AS_score{0.00}, avg_AS_assists{0.00}, avg_AS_rebounds{0.00};
public:
    AllStarPlayer(){ this->avg_AS_score = 0.00; this->avg_AS_assists = 0.00; this->avg_AS_rebounds = 0.00; }

    AllStarPlayer(NBA_Player &n_a, double avg_AS_score, double avg_AS_assists, double avg_AS_rebounds) : NBA_Player(n_a){
        this->avg_AS_score = avg_AS_score; this->avg_AS_assists = avg_AS_assists; this->avg_AS_rebounds = avg_AS_rebounds;
    }

    AllStarPlayer(char *name, char *team, double avg_score, double avg_assists, double avg_rebounds, double avg_AS_score, double avg_AS_assists, double avg_AS_rebounds){
        this->name = new char[strlen(name)+1]; strcpy(this->name,name);
        this->team = new char[strlen(team)+1]; strcpy(this->team,team);
        this->avg_score = avg_score; this->avg_assists = avg_assists; this->avg_rebounds = avg_rebounds;
        this->avg_AS_score = avg_AS_score; this->avg_AS_assists = avg_AS_assists; this->avg_AS_rebounds = avg_AS_rebounds;
    }

    AllStarPlayer(const AllStarPlayer& AS){
        if(this != &AS){
            delete[] this->name; this->name = new char[strlen(AS.name)+1]; strcpy(this->name,AS.name);
            delete[] this->team; this->team = new char[strlen(AS.team)+1]; strcpy(this->team,AS.team);
            this->avg_score = AS.avg_score; this->avg_assists = AS.avg_assists; this->avg_rebounds = AS.avg_rebounds;
            this->avg_AS_score = AS.avg_AS_score; this->avg_AS_assists = AS.avg_AS_assists; this->avg_AS_rebounds = AS.avg_AS_rebounds;
        }
    }

    inline AllStarPlayer& operator = (const AllStarPlayer& AS){
        if(this != &AS){
            delete[] this->name; this->name = new char[strlen(AS.name)+1]; strcpy(this->name,AS.name);
            delete[] this->team; this->team = new char[strlen(AS.team)+1]; strcpy(this->team,AS.team);
            this->avg_score = AS.avg_score; this->avg_assists = AS.avg_assists; this->avg_rebounds = AS.avg_rebounds;
            this->avg_AS_score = AS.avg_AS_score; this->avg_AS_assists = AS.avg_AS_assists; this->avg_AS_rebounds = AS.avg_AS_rebounds;
        } return *this;
    }

    ~AllStarPlayer(){}

    inline double AllStarRating() noexcept { return this->avg_AS_score*0.30 + this->avg_AS_assists*0.40 + this->avg_AS_rebounds*0.30; }
    inline double rating() noexcept { return (NBA_Player::rating() + AllStarRating()) / 2; }
    inline void print(){ NBA_Player::print(); std::cout<<"All Star Rating: "<<this->AllStarRating()<<std::endl<<"New Rating: "<<this->rating()<<std::endl; }
};

int main()
{
    char name[50], team[40];
    double points, assists, rebounds, allStarPoints, allStarAssists, allStarRebounds;

    NBA_Player*  players = new NBA_Player[5];
    AllStarPlayer* asPlayers = new AllStarPlayer[5];
    int n; std::cin>>n;

    if (n == 1){
        std::cout << "NBA PLAYERS:" << std::endl;
        std::cout << "=====================================" << std::endl;
        for (int i = 0; i < 5; ++i) {
          std::cin >> name >> team >> points >> assists >> rebounds;
          players[i] = NBA_Player(name,team,points,assists,rebounds);
          players[i].print();
        }
    }

    else if (n == 2){
        for (int i=0; i < 5; ++i){
            std::cin >> name >> team >> points >> assists >> rebounds >> allStarPoints >> allStarAssists >> allStarRebounds;
            players[i] = NBA_Player(name,team,points,assists,rebounds);
            asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
        }

        std::cout << "NBA PLAYERS:" << std::endl << "=====================================" << std::endl;
        for (int i=0; i < 5; ++i){ players[i].print(); }

        std::cout << "ALL STAR PLAYERS:" << std::endl << "=====================================" << std::endl;
        for (int i=0; i < 5; ++i) { asPlayers[i].print(); }

    }

    else if (n == 3){
      for (int i=0; i < 5; ++i){
        std::cin >> name >> team >> points >> assists >> rebounds >> allStarPoints >> allStarAssists >> allStarRebounds;
        asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds, allStarPoints,allStarAssists,allStarRebounds);
      }

      std::cout << "ALL STAR PLAYERS:" << std::endl << "=====================================" << std::endl;
      for (int i=0; i < 5; ++i){ asPlayers[i].print(); }
    }

    delete [] players; delete [] asPlayers; return 0;
}
