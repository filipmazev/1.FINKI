#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m, n; scanf("%d %d", &m, &n);
    int Matrix[m][n], sum_left=0, sum_right=0, Arr[m][n], mod=0; if(n%2==0){ mod=1; }

    for(int i=0; i<m; i++)
    {
        sum_left=0, sum_right=0;
        for(int j=0; j<n; j++)
        {
            scanf("%d", &Matrix[i][j]); Arr[i][j] = Matrix[i][j];
            if(j<(n/2)){ sum_left+=Matrix[i][j]; }
            if(j>(n/2)-mod){ sum_right+=Matrix[i][j]; }
        }
        Arr[i][n/2] = abs(sum_left-sum_right);
        if(mod){ Arr[i][(n/2)-mod] = Arr[i][n/2]; }
    }

    for(int i=0; i<m; i++)
    { for(int j=0; j<n; j++){ printf("%d ", Arr[i][j]); }
    printf("\n"); } return 0;
}
