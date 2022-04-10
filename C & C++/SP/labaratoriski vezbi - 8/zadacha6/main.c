#include <stdio.h>
#include <stdlib.h>

int nzd(int a, int b)
{
    if(a==0){ return b; }
    return nzd(b%a, a);
}

int main()
{
    int a, b; scanf("%d %d", &a, &b);
    printf("%d", nzd(a, b)); return 0;
}
