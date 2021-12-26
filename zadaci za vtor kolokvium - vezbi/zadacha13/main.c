#include <stdio.h>
#include <stdlib.h>

int main()
{
    int comp, m, n; scanf("%d %d %d", &comp, &m, &n); int Matrix[m][n], Arr[m];

    for(int i=0; i<m; i++)
    {   int sum=0;
        for(int j=0; j<n; j++)
        {
            scanf("%d", &Matrix[i][j]); sum+=Matrix[i][j];
        }
        Arr[i] = sum>comp?1:(sum<comp?-1:0);
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++){ printf("%d ", Arr[i]); }
    printf("\n"); } return 0;
}
