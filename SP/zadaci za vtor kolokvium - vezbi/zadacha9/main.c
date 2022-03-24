#include <stdio.h>
#include <stdlib.h>

double recursive(int *Arr, int n, int i)
{
    if(i==n+1){ return 0; }
    return Arr[i] + (1.00/recursive(Arr, n, i+1));
}

int main()
{
    int n; scanf("%d", &n); int Arr[n];
    for(int i=0; i<n; i++){ scanf("%d", &Arr[i]); }
    printf("%lf", recursive(Arr, n, 0));
    return 0;
}
