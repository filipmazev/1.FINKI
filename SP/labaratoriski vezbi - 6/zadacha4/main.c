#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, dif_1=0, dif_2=0; scanf("%d",&n); int A[n][n];

    for(int i=0; i<n; i++){ for(int j=0; j<n; j++){ scanf("%d", &A[i][j]);} }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int compare_1= i==j?A[i][j]:0; int compare_2= i+j==n-1?A[i][j]:0;
            int compare_3= j==0?A[i][j]:0; int compare_4= j==n-1?A[i][j]:0;
            dif_1 += compare_1 - compare_2; dif_2 += compare_3 - compare_4; } }

    printf("%d\n%d", dif_1, dif_2); return 0;
}
