#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; scanf("%d", &n); int A[n*2][n*2];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n*2; j++)
        {
            if(j>n-1){ scanf("%d", &A[i+n][j-n]); }
            else { scanf("%d", &A[i][j]); }
        }
    }

    for(int i=0; i<n*2; i++)
    { for(int j=0; j<n; j++){ printf("%d ", A[i][j]); }
        printf("\n"); } return 0;
}
