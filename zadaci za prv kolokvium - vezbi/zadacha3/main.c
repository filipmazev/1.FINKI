#include <stdio.h>

int main()
{
    int number, max=0, largest_number=0;
    scanf("%d", &number);

    for(int i=number-1; i>0; i--)
    {
        int sum=0;
        for(int j=i; j>0; j--)
        {
            if(i%j==0){ sum+=j; if(sum>max){ max=sum; largest_number=i; } }
        }
    }

    printf("%d", largest_number);

    return 0;
}
