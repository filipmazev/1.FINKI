#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; scanf("%d", &n); int A[n], temp;

    for(int i=0; i<n; i++){ scanf("%d", &A[i]); }

    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(A[j] > A[j+1]) {
                temp = A[j]; A[j] = A[j+1]; A[j+1] = temp; } } }

     for(int i=0; i<n; i++){ printf("%d ", A[i]); }


    return 0;
}
