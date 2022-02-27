#include <stdio.h>
#include <stdlib.h>

int flip(int n){ int fliped=0; while(n){ fliped=fliped*10+n%10; n/=10; } return fliped; }
int digit_sum(int n){ int sum=0; while(n){ sum+=n%10; n/=10; } return sum; }

void print_range_conditional(int start, int end)
{
    for(int i=start; i<=end; i++)
    {
        if( (i+flip(i)) % digit_sum((i+flip(i))) == 0 ){ printf("%d\n",i); }
    }
}

int main()
{
    int a, b; scanf("%d %d", &a, &b); print_range_conditional(a,b);

    return 0;
}
