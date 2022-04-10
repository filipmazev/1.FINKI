#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    size_t size=1024; char *string=calloc(size, sizeof(char)), ch; unsigned int i=0, x=0, y=0;

    while((ch=getchar())!='\n'){ string[i]=ch; i++; }

    char ***str_arr = (char ***)calloc(size, sizeof(char**)), *word = strtok(string, " ");
    str_arr[0] = (char **)calloc(size, sizeof(char*));

    while(word != NULL)
    {
        if(x>=size){ size*=2; char ***temp = (char ***)realloc(str_arr, sizeof(char **)); str_arr = temp; }
        if(y>=size){ size*=2; char ***temp = (char***)calloc(x, sizeof(char**));
        temp[x] = (char **)realloc(str_arr, sizeof(char *)); str_arr = temp; }

        str_arr[x][y] = (char *)calloc(strlen(word), sizeof(char)); strcpy(str_arr[x][y], word);

        if(word[strlen(word)-1] == '.'){ x++; str_arr[x] = (char **)calloc(y+1,sizeof(char*)); y=0; }

        word = strtok(NULL, " "); if(!isalnum(word)) { y++; }
    }

    printf("%s", str_arr[0][0]);

}
