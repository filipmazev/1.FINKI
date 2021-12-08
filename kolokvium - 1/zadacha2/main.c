#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, n; scanf("%d %d", &x, &n);

    while(n)
    {
        int number; scanf("%d", &number); if(number>9){
        int div = pow(10,(int)(number==0?1:log10(number)+1)-1), digit = (number/div) % 10;
        printf("%d", (((number - (digit*div)) * 10) + digit));
        if((((number - (digit*div)) * 10) + digit) % x == 0){ printf("DA\n"); } else { printf("NE\n"); } } n--;
    }

    return 0;
}
