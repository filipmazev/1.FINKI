#include <stdio.h>
#include <ctype.h>

int pow_div(int n){ if(n<10){ return 1; } return 10 * pow_div(n/10); }

void wtf()
{
    FILE *f = fopen("broevi.txt", "w"); char c;
    while((c = getchar()) != EOF){ fputc(c, f); }
    fclose(f);
}

int main()
{
    wtf(); FILE *read = fopen("broevi.txt", "r"); int number=0, cnt=0, max=0, max_number=0, num_org;

    while(!feof(read))
    {
        char character = fgetc(read);
        if(isdigit(character)){ number = number * 10 + character - '0'; num_org=number; }
        else{ if(cnt){ int digit = (number/pow_div(number));
                if(digit > max){ max=digit; max_number = number; } } number=0; cnt++; }
        if(character == '\n' && num_org){ printf("%d \n", max_number); cnt=0; max=0; }
    } return 0;
}
