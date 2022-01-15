#include <stdio.h>
#include <stdlib.h>

int sum_pos(int *array,int n, int m)
{
    if(m == n){ return 0; }
    return *(array+m) + sum_pos(array, n, m+1);
}

int main()
{
    int n, m; scanf("%d",&n); int array[n];
    for(int i=0;i<n;i++){ scanf("%d",&*(array+i)); }

    scanf("%d",&m); printf("%d", sum_pos(array,n,m)); return 0;
}
