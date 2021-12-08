#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_of_arrays; scanf("%d", &num_of_arrays);

    while(num_of_arrays)
    {
        int size=101, k, temp; while(size>100){ scanf("%d", &size); }
        int A[size]; for(int i=0; i<size; i++){ scanf("%d", &A[i]); }

        scanf("%d", &k); for(int i=0; i<size; i++){
            if((i+1) % k == 0) { temp = A[i]; A[i] = A[i-1]; A[i-1] = temp; } }

        for(int i=0; i<size; i++){ printf("%d ", A[i]); } printf("\n");

        num_of_arrays--;
    }

    return 0;
}
