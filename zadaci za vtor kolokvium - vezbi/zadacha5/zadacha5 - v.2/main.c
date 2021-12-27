#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wf()
{
    FILE *f = fopen("livce.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main()
{
    wf(); FILE *read = fopen("livce.txt", "r");
    char string[1024]; int i=0, cnt=0, flag=0, cnt_pos=0, pos;
    double money, mult=0, max=0, coeff=1, winnings=0;

    while(!feof(read))
    {
        char character = fgetc(read);

        if(character == ' ' || character == '\n' || character == '\0')
        {
            char *temp; double value = strtod(string, &temp);

            if(!flag){ flag=1; cnt=-1; char *temp; money = value; }
            else if(cnt==2){ coeff*=value; winnings = money * coeff;
            if(winnings>max){ max=winnings; } if(value>mult) { mult=value; pos=cnt_pos; } }

            for(int j=0; j<strlen(string); j++) { string[j] = ' '; } i=0; cnt++;
            if(character != ' '){ cnt=0; cnt_pos++; }
        }
        else { string[i] = character; i++; }
    }

    cnt_pos=0; fclose(read); FILE *read_again = fopen ("livce.txt", "r");

    while(!feof(read_again))
    {
        char character = fgetc(read_again); if(cnt_pos==pos){ printf("%c", character); }
        if(character == '\n'){ cnt_pos++; }
    }

    printf("%.2lf", winnings); return 0;
}
