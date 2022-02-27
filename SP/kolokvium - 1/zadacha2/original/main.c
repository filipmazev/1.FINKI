#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, n; scanf("%d %d", &x, &n);

    for(int i=0; i<n; i++)
    {
        int number; scanf("%d", &number);
        int div =  (int)pow(10, ((int)(number==0?1:log10(number)+1))-1), digit = (number / div) % 10;
        int number_2 = (div/(int)pow(10, ((int)(number==0?1:log10(number)+1))-2)) * ((number) - (digit*div)) + digit;
		if(number_2 % x == 0){ printf("DA\n"); } else { printf("NE\n"); }
    }

    return 0;
}
