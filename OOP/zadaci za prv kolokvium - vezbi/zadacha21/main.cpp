#include <iostream>
#include <cstring>

struct Dance{ char name[15], place_of_origin[15]; };

struct Dancer{ char firstname[20], lastname[20]; Dance arr[5]; int n; };

void danceing(Dancer *d, int n, char *location)
{
    for(int i=0; i<n; i++){ for(int j=0; j<3; j++){ if(!strcmp(d[i].arr[j].place_of_origin,location)){
    std::cout<<d[i].firstname<<" "<<d[i].lastname<<", "<<d[i].arr[j].name<<std::endl; break; } } }
}

int main()
{
    int n; std::cin>>n; Dancer d[n];

    for(int i=0; i<n; i++){ std::cin>>d[i].firstname>>d[i].lastname;
    for(int j=0; j<3; j++){ std::cin>>d[i].arr[j].name>>d[i].arr[j].place_of_origin; } }

    char location[20]; std::cin>>location; danceing(d, n, location); return 0;
}
