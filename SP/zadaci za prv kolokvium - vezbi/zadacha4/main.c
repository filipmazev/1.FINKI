#include <stdio.h>
#include <ctype.h>

int main()
{
    char c='.'; int broj=0, sum=0;

    while(c!='!')
    {
        scanf("%c", &c);
        if(isdigit(c)){ broj = broj*10 + c - '0';  }
        else { sum+=broj; broj = 0; }
    }

    printf("%d", sum);

    return 0;
}
