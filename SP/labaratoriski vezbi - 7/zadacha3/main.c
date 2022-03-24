#include <stdio.h>
#include <stdlib.h>

void readMatrix(int m, int n, int arr[m][n])
{
    int sum=0, min, position=0;
    for(int j=0; j<n; j++)
    {
        sum=0;
        for(int i=0; i<m; i++)
        {
            sum+=arr[i][j];
        }
        if(j==0){ min=sum; }
        if(sum<min){ min=sum; position=j; }
    }

    printf("%d", position);
}

int main()
{
    int m, n; scanf("%d %d", &m, &n); int A[m][n];
    for(int i=0;i<m; i++){ for(int j=0; j<n;j++){ scanf("%d ", &A[i][j]); } }

    readMatrix(m, n, A); return 0;
}
