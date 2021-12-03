#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; float cost, sum=0.00; char type; scanf("%d", &n);

    while(n){
        scanf("%f %c", &cost, &type);
        switch(type){
        case 'A': cost *= 0.18; break;
        case 'B': cost *= 0.05; break;
        case 'V': cost *= 0; break; }
        sum+=cost; n--; }

    printf("Total tax return is: %.2f", sum*0.15);
}
