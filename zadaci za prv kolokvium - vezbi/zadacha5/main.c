#include <stdio.h>

int main()
{
    int num_1, num_2, i=1; scanf("%d %d", &num_1, &num_2);
    if(num_1 <=0 || num_2 <=0 ){ printf("Invalid input"); return 0; }

    if(num_2>num_1) { int temp=num_1; num_1=num_2; num_2=temp; }

    while(num_2){ if(i%2==0){ if(num_2%10 != num_1%10) { printf("NE"); return 0; } num_2/=10; } num_1/=10; i++; }

    printf("PAREN"); return 0;
}


