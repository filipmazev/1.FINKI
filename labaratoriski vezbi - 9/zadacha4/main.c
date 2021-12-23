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
    for(int i=0; i<strlen(comparator); i++){ *(comparator+i) = tolower(*(comparator+i)); } flipString(string_1); flipString(string_2);

    char pomal[1024], pogolem[1024]; strcpy(pomal, string_1); strcpy(pogolem, string_2);
    if( tolower(*(string_1+0)) > tolower(*(string_2+0))){ strcpy(pomal, string_2); strcpy(pogolem, string_1); }

    if(!strcmp(comparator, "pomal")){ printf("%s\n", &pomal); } else if(!strcmp(comparator, "pogolem")) { printf("%s\n", &pogolem); }
    else { printf("Invalid comparator\n"); }
}

int main()
{
    int n; scanf("%d", &n); char *return_string;

    while(n){ char string_1[1024], string_2[1024], comparator[1024]; scanf("%s %s %s", &string_1, &string_2, &comparator);
        revertString(string_1, string_2, comparator); n--; }

    return 0;
}
