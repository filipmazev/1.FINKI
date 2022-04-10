#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, rez, cnt=0, min, max=0; scanf("%d", &n);

    while(n)
    {
        int a,b,c; max=0, min=0; scanf("%d %d %d", &a, &b, &c);

        if(a>=b && a>=c){ max=a; } if(b>=a && b>=c){ max=b; } if(c>=a && c>=b){ max=c; }
        min = max; if(a<min){ min=a; } if(b<min){ min=b; } if(c<min){ min=c; }

        float rez = (2*(float)min) - ((float)max/2) + abs(min-a);
        printf("%.2f\n",rez);n--;
    }

    return 0;
}
