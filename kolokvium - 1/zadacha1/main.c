#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n; scanf("%d", &n);

    while(n)
    {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        int max = (((a>=b)?a:b)>=c?((a>=b)?a:b):c), min = (((a<=b)?a:b)<=c?((a<=b)?a:b):c);
        printf("%.2f\n",(2*(float)min) - ((float)max/2) + abs(min-a)); n--;
    }

    return 0;
}
