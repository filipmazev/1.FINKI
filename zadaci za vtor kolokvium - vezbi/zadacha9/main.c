#include <stdio.h>
#include <stdlib.h>

float recursive(int *Arr, int n, int i)
{
    if(i==n-1){ return; }
    return Arr[i] + (1.00/recursive(Arr, n, i+1));
}

int main()
{
    int n; scanf("%d", &n); int Arr[n];
    for(int i=0; i<n; i++){ scanf("%d", &Arr[i]); }
    printf("%f", recursive(Arr, n, 0)); return 0;
}
