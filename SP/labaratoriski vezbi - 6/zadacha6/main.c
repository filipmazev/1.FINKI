#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=101; while(n>100){ scanf("%d", &n); }
    int A[n][n], temp=0, cnt=0, max=0;

    for(int i=0; i<n; i++)
    {
        cnt = n; for(int j=0; j<n; j++)
        {
            scanf("%d", &A[i][j]);
            if(A[i][j]<=temp){ cnt--; } temp = A[i][j];
        }
        if(cnt>max){ max=cnt; } cnt = 0;
    }

    printf("%d", max);

    return 0;
}
