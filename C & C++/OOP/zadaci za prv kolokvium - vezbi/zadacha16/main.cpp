#include <stdio.h>
#include <string.h>
#define WEEKS 4
#define DAYS 5

struct Work_Week{ int work_hours[DAYS], week_num; };
typedef struct Work_Week Work_Week;

struct Worker{ char name[50]; Work_Week arr[4]; };
typedef struct Worker Worker;

int maxWeek(Worker *w)
{
    int maxi=0, pos=0;
    for(int i=0; i<WEEKS; i++){ int sum=0;
        for(int j=0; j<DAYS; j++){ sum+=w[0].arr[i].work_hours[j]; }
            if(sum>maxi){ maxi=sum; pos=i; } }
    return pos+1;
}

void table(Worker *w, int n)
{
    printf("Rab\t"); for(int i=0; i<WEEKS; i++){ printf("%d\t",i+1); } printf("Vkupno\n");
    for(int i=0; i<n; i++){ int total=0; printf("%s\t",w[i].name);
        for(int j=0; j<WEEKS; j++){ int sum=0;
            for(int k=0; k<DAYS; k++) { sum+=w[i].arr[j].work_hours[k]; } printf("%d\t", sum); total+=sum; }
        printf("%d\n", total); }
}

int main()
{
    int n; scanf("%d", &n); Worker workers[n];

    for (int i = 0; i<n; ++i){ scanf("%s", workers[i].name);
        for (int j=0; j<WEEKS; ++j){
            for (int k=0; k<DAYS; ++k){ scanf("%d", &workers[i].arr[j].work_hours[k]); } } }

    printf("TABLE\n"); table(workers, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", workers[n/2].name);
    printf("%d\n", maxWeek(&workers[n / 2]));
    return 0;
}

/* C++
#include <iostream>
#define WEEKS 4
#define DAYS 5

struct Work_Week{ int work_hours[DAYS], week_num; };

struct Worker{ char name[50]; Work_Week arr[4]; };

int maxWeek(Worker *w)
{
    int maxi=0, pos=0;
    for(int i=0; i<WEEKS; i++){ int sum=0;
        for(int j=0; j<DAYS; j++){ sum+=w[0].arr[i].work_hours[j]; }
            if(sum>maxi){ maxi=sum; pos=i; } }
    return pos+1;
}

void table(Worker *w, int n)
{
    std::cout<<"Rab \t"; for(int i=0; i<WEEKS; i++){ std::cout<<i+1<<"\t"; } std::cout<<"Vkupno\t"<<std::endl;
    for(int i=0; i<n; i++){ int total=0; std::cout<<w[i].name<<"\t";
        for(int j=0; j<WEEKS; j++){ int sum=0;
            for(int k=0; k<DAYS; k++) { sum+=w[i].arr[j].work_hours[k]; } std::cout<<sum<<"\t"; total+=sum; }
        std::cout<<total<<"\t"<<std::endl; }
}

int main()
{
    int n; std::cin>>n; Worker workers[n];

    for (int i = 0; i<n; ++i){ std::cin>>workers[i].name;
        for (int j=0; j<WEEKS; ++j){
            for (int k=0; k<DAYS; ++k){ std::cin>>workers[i].arr[j].work_hours[k]; } } }

    std::cout<<"TABLE"<<std::endl; table(workers, n);
    std::cout<<"MAX NEDELA NA RABOTNIK: "<<workers[n/2].name<<std::endl;
    std::cout<<maxWeek(&workers[n / 2])<<std::endl;
    return 0;
} */
