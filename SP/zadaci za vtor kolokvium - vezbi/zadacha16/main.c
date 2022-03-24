#include <stdio.h>
#include <stdlib.h>

int max_rec(int num)
{
    if(num==0){ return 0; }
    return num%10>max_rec(num/10)?num%10:max_rec(num/10);
}

int main()
{
    int num; while(scanf("%d", &num)){ printf("%d\n", max_rec(num)); }
}
