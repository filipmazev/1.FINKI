#include <stdio.h>
#include <stdlib.h>

int f(int n, int i, int sum)
{
    if(n==0){ return sum; }
    if(i%2 == 0){ sum+=n%10; }
    f(n/10, i+1, sum);
}

int main()
{
    int n; scanf("%d", &n);
    printf("%d", f(n, 1, 0)); return 0;
}
