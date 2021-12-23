#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 100

void wtf()
{
    FILE *f = fopen("broevi.txt", "w"); char c;
    while((c = getchar()) != EOF){ fputc(c, f); }
    fclose(f);
}

int main()
{
    wtf(); FILE *read = fopen("broevi.txt", "r");
    int number=0, cnt=0, max=0, max_number=0;

    while(!feof(read))
    {
        char character = fgetc(read); if(isdigit(character)){number = number * 10 + character - '0'; }
        else{ if(cnt){ int digit = (number/(int)(pow(10,((int)((number==0)?1:log10(number))))));
                if(digit > max){ max=digit; max_number = number; } } number=0; cnt++; }
        if(character == '\n'){ printf("%d \n", max_number); cnt=0; max=0; }
    } return 0;
}
