#include <stdio.h>
#include <stdlib.h>

int recursive_checker(int n)
{
    if(n==0){ return 1; }
    if(n>=10){ if( (n/10)%10 >= n%10 ){ return 0; } }
    recursive_checker(n/10);
}

int main()
{
    int m, n; scanf("%d", &m);

    while(m){ scanf("%d", &n);
    if(recursive_checker(n) == 1){ printf("DA\n"); } else printf("NE\n"); m--; }

    return 0;
}
