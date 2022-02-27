#include <stdio.h>
#include <stdlib.h>

void triagolnik(int n, int i)
{
    if(n==0){ return 0; }
    if(i>n){ n--; i=1; printf("\n"); }
    if(n!=0){ printf("%d ", i); }
    triagolnik(n, i+1);
}

int main()
{
    int n; scanf("%d",&n); triagolnik(n, 1);
    return 0;
}
