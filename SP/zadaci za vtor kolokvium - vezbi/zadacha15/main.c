#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    size_t buff=1024; int num, temp=0, *Arr = calloc(buff, sizeof(int)), cnt=0;

    while(scanf("%d", &num))
    {
        if(cnt>=buff){ buff*=2; void *temp = realloc(Arr, buff * sizeof(int)); Arr = temp; }

        size_t size = (int)(num==0?1:log10(num)+1); char num_str[size]; itoa(num, num_str, 10);
        for(size_t i=0; i<size; i++){ if(*(num_str+i) == '9'){ *(num_str+i) = '7'; } }

        char *temp; int value = strtod(num_str, &temp); *(Arr+cnt) = value; cnt++;
    }

    for(size_t i=0; i<cnt; i++){ for(size_t j=i+1; j<cnt; j++){
    if(*(Arr+i) > *(Arr+j)){ temp = *(Arr+i); *(Arr+i) = *(Arr+j); *(Arr+j) = temp; } } }

    while(cnt>5){ cnt--; } for(size_t i=0; i<cnt; i++){ printf("%d ", *(Arr+i)); } return 0;
}
