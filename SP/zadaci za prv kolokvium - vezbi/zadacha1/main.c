#include <stdio.h>

int main()
{
    int start, end, cnt=0;
    scanf("%d %d", &start, &end); int min=end;

    for(int i=start; i<=end; i++)
    {
        int num=i, flag=0;
            while(num){ if(num%2!=0){ flag=1; } num/=10; }
        if(flag==0){ if(i<min){ min=i; } cnt++; }
    }

    if(cnt == 0){ printf("NE"); return 0;} printf("%d", min);

    return 0;
}
