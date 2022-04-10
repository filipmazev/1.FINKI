#include <stdio.h>
#include <ctype.h>
#include <string.h>

void writeToFile()
{
    FILE *f = fopen("text.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); } fclose(f);
}

int main()
{
    writeToFile(); FILE *read = fopen("text.txt", "r");
    char character, prev=' ', vowels[]={'a','e','i','o','u'}; unsigned int i=0, cnt=0;

    while(!feof(read))
    {
        character = tolower(fgetc(read)); int flag_1=0, flag_2=0;

        for(unsigned int k=0; k<sizeof(vowels)/sizeof(char); k++){
            if(character == vowels[k]) { flag_1=1; } if(prev == vowels[k]) { flag_2=1; } }

        if(flag_1 == 1 && flag_2 == 1){ printf("%c%c\n", prev, character); cnt++; } prev = character;
    }

    printf("%d", cnt); fclose(read); return 0;
}
