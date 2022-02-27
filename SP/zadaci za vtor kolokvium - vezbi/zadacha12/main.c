#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int brojPozitivni(int Arr[], int n)
{
   if(n<=0){ return 0; }
   if(Arr[n-1] >= 0) { return 1 + brojPozitivni(Arr, n-1); }
   else return brojPozitivni(Arr, n-1);
}

int main()
{
    int n; scanf("%d", &n); int Arr[n];
    for(int i=0; i<n; i++){ scanf("%d", &Arr[i]); }
    printf("%d", brojPozitivni(Arr, n));
}
