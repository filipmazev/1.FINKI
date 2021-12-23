#include <stdio.h>
#include <stdlib.h>

int sum_pos(int *arr, int n, int ind)
{
    int sum=0; for(int i=ind; i<n; i++){ sum+=*(arr+i); }
    return sum;
}

int main()
{
    int *arr, n=101, ind=-1, sum=0;

    while(n>100){ scanf("%d", &n); }
    for(int i=0; i<n; i++){ scanf("%d", &*(arr+i)); }

    while(ind<0){ scanf("%d", &ind); } if(ind>n){ return 0; }
    printf("%d", sum_pos(arr, n, ind)); return 0;
}
