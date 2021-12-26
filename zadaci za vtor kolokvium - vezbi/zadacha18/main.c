#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; scanf("%d", &n);
    double Matrix[n][n], sum_d1=0, sum_d2=0, Matrix_B[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%lf", &Matrix[i][j]); Matrix_B[i][j]=0;
            if(i>j){ sum_d1+=Matrix[i][j]; }
            if(i+j>n-1){ sum_d2+=Matrix[i][j]; }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j){ Matrix_B[i][j]+=sum_d1; }
            if(i+j==n-1){ Matrix_B[i][j]+=sum_d2; }
            printf("%.1lf ",Matrix_B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
