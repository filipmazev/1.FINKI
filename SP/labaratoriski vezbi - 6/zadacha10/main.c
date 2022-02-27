#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=101, cnt=0; while(n>100){ scanf("%d", &n); } int A[n], A2[n], k;

    for(int i=0; i<n; i++){ scanf("%d", &A[i]); } scanf("%d", &k);

    for(int i=0; i<n; i++){ if(A[i]<k){ A2[cnt] = A[i]; cnt++; } }
    for(int i=0; i<n; i++){ if(A[i]>=k){ A2[cnt] = A[i]; cnt++; } }

    for(int i=0; i<n; i++){ printf("%d ",A2[i]); } return 0;
}
