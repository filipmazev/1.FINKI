#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number_1, number_2=0, cnt=0; scanf("%d", &number_1);
    int digits = ((number_1==0)?1:log10(number_1)+1);

    while(digits){ int digit = number_1 / (int)pow(10,digits-1) % 10;
    if(digit==5){ cnt++; digit+=1; } number_2 = number_2 * 10 + digit; digits--; }

    if(cnt<2){ printf("Error"); return 0; }

    int tmp=number_1; if(number_1<number_2){ number_1 = number_2; number_2 = tmp; }
    printf("%.04lf%%",  ((number_1 - number_2) / (float)tmp) * 100 );

    return 0;
}
