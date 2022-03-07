#include <stdio.h>
#include <stdlib.h>

typedef struct Ride{ char name[100]; int lenght, student_discount; float price; };
typedef struct Ride Ride;

struct Theme_Park{ char park_name[100], location[100]; Ride arr[100]; int n; };
typedef struct Theme_Park Theme_Park;

void print(Theme_Park *t_p_arr, int n)
{
    for(int i=0; i<n; i++){
        printf("%s %s\n",t_p_arr[i].park_name,t_p_arr[i].location);
        for(int j=0; j<t_p_arr[i].n; j++){
            printf("%s %d %.2f\n",t_p_arr[i].arr[j].name,t_p_arr[i].arr[j].lenght,t_p_arr[i].arr[j].price); } }
}

void print_best_park(Theme_Park *t_p_arr, int n)
{
    char message[]="Najdobar park:"; int max=0, max_lenght=0, pos_i=0;

    for(int i=0; i<n; i++){ int sum_cmp=0, lenght_total=0;
        for(int j=0; j<t_p_arr[i].n; j++){ t_p_arr[i].arr[j].student_discount?sum_cmp++:0; lenght_total += t_p_arr[i].arr[j].lenght; }
        int confirm=lenght_total>max_lenght?(max_lenght=lenght_total),1:0; sum_cmp>max?max=sum_cmp,pos_i=i:(sum_cmp==max&&confirm?max=sum_cmp,pos_i=i:0); }
    printf("%s %s %s\n", message, t_p_arr[pos_i].park_name, t_p_arr[pos_i].location);
}

int main()
{
	int n; Theme_Park t_p_arr[100]; scanf("%d", &n);

    for (int i=0; i<n; i++){
		scanf("%s %s %d", t_p_arr[i].park_name, t_p_arr[i].location, &t_p_arr[i].n);
		for (int j=0; j<t_p_arr[i].n; j++){
            scanf("%s %d %f %d", t_p_arr[i].arr[j].name, &t_p_arr[i].arr[j].lenght, &t_p_arr[i].arr[j].price, &t_p_arr[i].arr[j].student_discount); } }

    print(t_p_arr,n); print_best_park(t_p_arr,n); return 0;
}
