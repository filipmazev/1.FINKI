#include <stdio.h>
#include <stdlib.h>

void wf()
{
    FILE *f = fopen("livce.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

void reallocate(char *string, size_t size, size_t var){ void *temp = realloc(string, size * var); string = temp; }

int main()
{
    wf(); FILE *read = fopen ("livce.txt", "r");
    size_t size=1024; char *string = malloc(size * sizeof(char));
    unsigned int i=0; int cnt=0, flag=0, cnt_pos=0, pos, money;
    double *Arr = malloc(size * sizeof(double)), winnings=0, max=0, coeff=1, mult=0, value=0;

    while(!feof(read))
    {
        char character = fgetc(read);
        if(i>=size){ size*=2; reallocate(string, size, sizeof(char)); reallocate(Arr, size, sizeof(double)); }
        if(character == ' ' || character == '\n' || character == '\0')
        {
            free(string); string = malloc(size * sizeof(char));
            if(!flag){ flag=1; cnt=-1; money = value; }
            else if(cnt==2) { coeff*=*(Arr+cnt); winnings = money * coeff;
            if(winnings>max){ max=winnings; } if(value>mult) { mult=value; pos=cnt_pos; } }
            if(character == '\n'){ cnt_pos++; } i=0; cnt++; if(cnt>2){ cnt=0; }
        }
        else { *(string+i) = character; i++; char *temp; value = strtod(string, &temp); } *(Arr+cnt) = value;
    }

    cnt_pos=0; fclose(read); FILE *read_again = fopen ("livce.txt", "r");

    while(!feof(read_again)){
        char character = fgetc(read_again); if(cnt_pos==pos){ printf("%c", character); }
        if(character == '\n'){ cnt_pos++; } }

    printf("%.2lf", winnings); return 0;
}
