#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; scanf("%d", &n); int A[n], Reverse_Half[n/2], cnt=0;

    for(int i=0; i<n; i++){ scanf("%d",&A[i]); }

    for(int i=0; i<n; i++){ printf("%d ",A[i]); } printf("\n");
    for(int i=n-1; i>=0; i--){ printf("%d ",A[i]); } printf("\n");
    for(int i=n-1; i>=0; i-=2){ Reverse_Half[cnt]=A[i]; cnt++; printf("%d ",A[i]); } printf("\n");
    for(int i=cnt-1; i>=0; i--){ printf("%d ",Reverse_Half[i]); } printf("\n");

    return 0;
}
