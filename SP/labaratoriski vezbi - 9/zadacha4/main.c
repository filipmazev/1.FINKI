#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void flipString(char *string)
{
    char temp[strlen(string)];
    for(int i=0; i<strlen(string); i++){ temp[strlen(string)-1-i] = *(string+i); }
    for(int i=0; i<strlen(string); i++){ *(string+i) = temp[i]; }
}

void revertString(char *string_1, char *string_2, char *comparator)
{
    int i=0, flag=0, comp=0; char to_print[1024];
    for(int i=0; i<strlen(comparator); i++){ *(comparator+i) = tolower(*(comparator+i)); }
    if(!strcmp(comparator, "pomal")) { comp=1; } else if(strcmp(comparator, "pogolem")){ printf("Invalid comparator\n"); return 0; }

    while(!flag)
    {
        if(!comp){ if( tolower(*(string_1+i)) > tolower(*(string_2+i))){ flag=1; strcpy(to_print, string_1); }
        if(tolower(*(string_2+i) > tolower(*(string_1+i)))){ flag=1; strcpy(to_print, string_2); } }

        else{ if( tolower(*(string_1+i)) < tolower(*(string_2+i))){ flag=1; strcpy(to_print, string_1); }
        if(tolower(*(string_2+i) < tolower(*(string_1+i)))){ flag=1; strcpy(to_print, string_2); } } i++;
    }

    printf("%s\n", to_print);
}

int main()
{
    int n; scanf("%d", &n); char *return_string;
    while(n){ char string_1[1024], string_2[1024], comparator[1024]; scanf("%s %s %s", &string_1, &string_2, &comparator);
    flipString(string_1); flipString(string_2); revertString(string_1, string_2, comparator); n--; } return 0;
}
