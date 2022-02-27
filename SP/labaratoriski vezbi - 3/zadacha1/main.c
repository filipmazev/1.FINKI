#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number, sum=0, mult=1; scanf("%d", &number); int digits = ((number==0)?1:log10(number)+1);

    if(digits != 7){ printf("Vneseniot broj ne e 7 cifren!"); return 0; }

    while(digits){ int digit = number / (int)pow(10,digits-1) % 10; printf("%d\n",digit);
    digits--; sum+=digit; mult*=digit; }

    printf("%d\n%d\n", sum, mult);

    return 0;
}
