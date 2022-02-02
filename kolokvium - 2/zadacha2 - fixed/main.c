#include<stdio.h>
#include<ctype.h>
#include<string.h>

void wtf()
{
    FILE *f = fopen("input.txt", "w");char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main()
{
    wtf(); FILE *read = fopen("input.txt", "r");
    size_t size=1024; char *string = calloc(size, sizeof(char)); int w=0;

    while(fgets(string, size, read) != NULL)
    {
        char temp[strlen(string)-1]; strcpy(temp, string); int b=0, w=0;

        for(int i=0; i<strlen(temp); i++){ if(isalnum(temp[i])){ b++; } }

        char *word = strtok(temp, " ,-'");
        while(word!=NULL){ if(!isspace(word[0])) { w++; } word = strtok(NULL, " ,-'"); }

        printf("%d, %d: ", b, w); printf("%s", string);
    }

    return 0;
}
