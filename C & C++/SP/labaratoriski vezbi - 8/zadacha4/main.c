#include <stdio.h>
#include <stdlib.h>

int f(int n, int i, int mult)
{
    if(n==0){ return mult; }
    if(i%2 == 0){ mult*=n%10; }
    f(n/10, i+1, mult);
}

int main()
{
    int n; scanf("%d", &n);
    printf("%d", f(n, 1, 1)); return 0;
}
