#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_of_arrays; scanf("%d", &num_of_arrays);

    while(num_of_arrays){
        int size=101, cnt=0; while(size>100){ scanf("%d", &size); }
        int A[size]; for(int i=0; i<size; i++){ scanf("%d", &A[i]); }

        for(int i=0; i<size/2; i++) { if(A[i] == A[size-i-1]){ cnt+=2; } }
        if(size%2!=0){ cnt+=1; } printf("%.02f%%\n", (float)cnt/size * 100);
        num_of_arrays--;}

    return 0;
}
