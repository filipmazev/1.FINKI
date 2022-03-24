#include <stdio.h>
#include <math.h>

int main()
{
    int number, max=0; scanf("%d", &number);
    if(number < 9){ printf("Brojot ne e validen"); return 0; }

    for(int i=number-1; i>=0; i--)
    {
        int temp_i=i, sum=0; while(temp_i){ sum = sum*10+temp_i%10; temp_i/=10; }
        if((sum % (int)(i==0?1:log10(i)+1)) == 0 && i > max){ max = i; }
    }

    printf("%d", max);

    return 0;
}
