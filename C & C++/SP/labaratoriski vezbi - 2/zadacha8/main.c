#include <stdio.h>

int main()
{
    size_t size = 3; char arr[size]; int p=0, mod=0; scanf("%s", arr);

    for(int i=0; i<size; i++)
    {
        if(isalnum(arr[i])) p=mod?0:1; else p=mod?1:0;
        printf("%d", p); if(i==size-1 && !mod){ printf("\n"); i=-1, mod=1; }
    }
}
