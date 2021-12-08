#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=101; while(n>100 || n<3){ scanf("%d", &n); }
    int A[n][n], B[2][2]={0,0,0,0};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &A[i][j]);
            if(j<n/2){ if(i<n/2){ B[0][0]+=A[i][j]; } if(i>n/2){ B[1][0]+=A[i][j]; } }
            if(j>n/2){ if(i<n/2){ B[0][1]+=A[i][j]; } if(i>n/2){ B[1][1]+=A[i][j]; } }
        }
    }

    for(int i=0; i<2; i++){ for(int j=0; j<2; j++) { printf("%d ",B[i][j]); } printf("\n"); }

    return 0;
}
