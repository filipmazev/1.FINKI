#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Laptop{ char manufacturer[100]; float screen_size_in; bool touch; int price; };
typedef struct Laptop Laptop;

struct ITStore { char store_name[100], location[100]; Laptop l_arr[100]; int n; };
typedef struct ITStore ITStore;

void print(ITStore *arr, int n)
{
    for(int i=0; i<n; i++){
    printf("%s %s\n",arr[i].store_name,arr[i].location);
    for(int j=0; j<arr[i].n; j++){ float s_s = arr[i].l_arr[j].screen_size_in;
    printf("%s ",arr[i].l_arr[j].manufacturer); (s_s-(int)s_s)==0?printf("%d",(int)s_s):printf("%.1f",s_s); printf(" %d\n",arr[i].l_arr[j].price); } }
}

void best_offer(ITStore *arr, int n)
{
    int min=2147483647, pos_i=0, pos_j=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<arr[i].n; j++){
            if(arr[i].l_arr[j].price<min && arr[i].l_arr[j].touch==1){ min = arr[i].l_arr[j].price; pos_i=i,pos_j=j; } } }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\nNajniskata cena iznesuva: %d",arr[pos_i].store_name, arr[pos_i].location, arr[pos_i].l_arr[pos_j].price);
}

int main()
{
	int n; ITStore it_s_arr[100]; scanf("%d", &n);

    for (int i=0; i<n; i++){
		scanf("%s %s %d", it_s_arr[i].store_name, it_s_arr[i].location, &it_s_arr[i].n);
		for (int j=0; j<it_s_arr[i].n; j++){
            scanf("%s %f %d %d", it_s_arr[i].l_arr[j].manufacturer, &it_s_arr[i].l_arr[j].screen_size_in, &it_s_arr[i].l_arr[j].touch, &it_s_arr[i].l_arr[j].price); } }

    print(it_s_arr,n); best_offer(it_s_arr,n); return 0;
}
