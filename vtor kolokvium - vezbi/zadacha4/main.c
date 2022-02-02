#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    size_t size=1024; char *string=calloc(size, sizeof(char)), ch; unsigned int i=0, x=0, y=0;

    while((ch=getchar())!='\n'){ string[i]=ch; i++; } char temp[size]; strcpy(temp, string);

    char ***str_arr = (char ***)calloc(size, sizeof(char**)), *word = strtok(string, " ");

    str_arr[0] = (char **)calloc(size, sizeof(char*)); int y_arr[size];

    while(word != NULL)
    {
        if(isupper(word[0]) && y)
        {
            str_arr[x][y] = (char *)calloc(strlen(word), sizeof(char));

            for(int z=0; z<strlen(word); z++)
            {
                if(isalpha(word[z])){ str_arr[x][y][z] = word[z]; }
            }
        }

        if(!isspace(word)){ y++; }

        if(word[strlen(word)-1] == '.'){  x++; str_arr[x] = (char **)calloc(size,sizeof(char*)); y=0; }

        word = strtok(NULL, " ");
    }

    return 0;
}
