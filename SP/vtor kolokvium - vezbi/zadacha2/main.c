#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void write()
{
    FILE *f = fopen("text.txt", "w"); char c;
    while((c = getchar()) != EOF) { fputc(c, f); }
    fclose(f);
}

int main()
{
    write(); FILE *read = fopen("text.txt", "r"); char string[1024]; int j=0;

    while(fgets(string, 1024, read) != '\0')
    {
        for(int i=0; i<strlen(string); i++){
        if(isdigit(string[i])){ j = string[i] - '0' + 1; printf("%c", string[i]); }
        if(!j || !isalnum(string[i])){ printf("%c", string[i]); } else { if(j) { j--; } } }
    }

    return 0;
}
