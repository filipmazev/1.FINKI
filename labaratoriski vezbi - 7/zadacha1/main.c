#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int n)
{
    for(int i=0; i<n; i++){ printf("%d ", array[i]); } printf("\n");
}

void printFlipped(int A[], int n)
{
    for(int i=0; i<n/2; i++){ int temp = A[i]; A[i] = A[n-1-i]; A[n-1-i] = temp; } printArray(A, n);
}

int main()
{
    int n; scanf("%d", &n); int A[n], cnt=0;

    for(int i=0; i<n; i++){ scanf("%d",&A[i]); } printArray(A, n); printFlipped(A, n);
    for(int i=0; i<n; i+=2){ A[cnt]=A[i]; cnt++; } printArray(A, cnt); printFlipped(A, cnt);

    return 0;
}
