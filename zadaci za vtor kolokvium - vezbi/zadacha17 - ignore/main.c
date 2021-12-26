#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=13; int Arr[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};

    for(int i=0; i<n; i++)
    {
        if(n/2 == i || n/4 == i/2)
        {
            printf("%d", Arr[i]);
        }
    }

    return 0;
}
