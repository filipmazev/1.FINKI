#include <iostream>

struct Player { char playername[15]; int level, points; };

struct Computer_Game{ char name[20]; Player arr[30]; int n; };

void bestPlayer(Computer_Game *game_list, int n)
{
    int max_players=0, pos_i=0, pos_j=0;

    for (int i=0; i<n; i++){ int max_points=0, max_level=0;
        if(!(max_players<game_list[i].n?(max_players=game_list[i].n),0:1)){ for(int j=0; j<game_list[i].n; j++){
            int points = game_list[i].arr[j].points, level = game_list[i].arr[j].level;
            points>=max_points?(level>max_level||points>max_points?(max_level=level,max_points=points,pos_i=i,pos_j=j):0):0; } } }

    std::cout<<"Najdobar igrac e igracot so korisnicko ime "<<game_list[pos_i].arr[pos_j].playername<<" koj ja igra igrata "<<game_list[pos_i].name<<std::endl;
}

int main()
{
    int n; char name[20]; std::cin>>n; Computer_Game game_list[n];

    for (int i=0; i<n; i++){
    std::cin>>game_list[i].name>>game_list[i].n;
        for(int j=0; j<game_list[i].n; j++){
        std::cin>>game_list[i].arr[j].playername>>game_list[i].arr[j].level>>game_list[i].arr[j].points; } }

    bestPlayer(game_list,n);
    return 0;
}
