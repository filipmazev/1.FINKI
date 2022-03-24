#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; scanf("%d", &n); int A[n];

    for(int i=0; i<n; i++){
        scanf("%d", &A[i]); if(A[i] % 2 == 0){ A[i]+=1; } else A[i]-=1; }

    for(int i=0; i<n; i++){ printf("%d ", A[i]); }

    return 0;
}
