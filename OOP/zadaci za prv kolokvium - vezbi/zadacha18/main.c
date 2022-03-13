#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ski_lift { char name[15]; int max_occupance; bool active; };
typedef struct ski_lift ski_lift;

struct ski_center { char name_of_center[20], country[20]; ski_lift arr[20]; int num; };
typedef struct ski_center ski_center;

void maxCapacity(ski_center *s_c, int n)
{
    int max=0, max_active=0, pos_i;
    for(int i=0; i<n; i++){ int sum=0,active=0;
        for(int j=0; j<s_c[i].num; j++){ if(s_c[i].arr[j].active) { active++; sum+=s_c[i].arr[j].max_occupance; } }
    sum==max?(active>max_active?max_active=active,max=sum,pos_i=i:0):(sum>max?max=sum,pos_i=i:0); }

    printf("%s\n%s\n%d", s_c[pos_i].name_of_center,s_c[pos_i].country,max);
}

int main()
{
	int n; scanf("%d", &n); ski_center s_c[n];

	for (int i=0; i<n; i++){ scanf("%s%s%d", s_c[i].name_of_center, s_c[i].country, &s_c[i].num);
		for(int j=0; j<s_c[i].num; j++){ scanf("%s%d%d",s_c[i].arr[j].name,&s_c[i].arr[j].max_occupance,&s_c[i].arr[j].active); } }

    maxCapacity(s_c,n); return 0;
}
