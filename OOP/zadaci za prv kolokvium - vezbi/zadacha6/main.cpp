#include<iostream>
#include <cstring>

struct Train { char path[50]; int km, passangers; };

struct TrainStation{ char city[20]; Train trains[30]; int train_amount; };

void shortestPath(TrainStation *t_s, int n, char *city)
{
    int min_km=9259, pos_i, pos_j;

    for(int i=0; i<n; i++){
        for(int j=0; j<t_s[i].train_amount; j++){
            if(!(strncmp(t_s[i].trains[j].path, city, strlen(city)))){
                t_s[i].trains[j].km<=min_km?0,(min_km = t_s[i].trains[j].km, pos_i = i, pos_j = j):0; } } }
    std::cout<<"Najkratka relacija: "<<t_s[pos_i].trains[pos_j].path<<" ("<<t_s[pos_i].trains[pos_j].km<<" km)"<<std::endl;
}

int main()
{
    int n; std::cin>>n; TrainStation t_s[n+1];

    for (int i=0;i<n;i++){ char t_s_city[20]; int train_amount; std::cin>>t_s[i].city>>t_s[i].train_amount;
        for(int j=0; j<t_s[i].train_amount; j++){ char path[50]; int km, passangers;
            std::cin>>t_s[i].trains[j].path>>t_s[i].trains[j].km>>t_s[i].trains[j].passangers; } }

    char city[25]; std::cin>>city; shortestPath(t_s,n,city); return 0;
}
