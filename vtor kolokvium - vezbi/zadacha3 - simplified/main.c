#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *remove_compare(char *word, char *comp)
{
    for(int i=0; i<strlen(word); i++) {
        for(int j=0; j<strlen(comp); j++){
            if(word[i] == comp[j]) { memmove(&word[i], &word[i + 1], strlen(word) - i); remove_compare(word, comp); } } }
}

int main()
{
    char string[1024]; unsigned int i=0, size=0; char ch;
    while((ch = getchar()) != '\n'){ string[i] = ch; i++; }

    char *word = strtok(string, " "); char **str_arr = calloc(1024, sizeof(char));
    while(word!=NULL){ str_arr[size] = calloc(strlen(word), sizeof(char)); strcpy(str_arr[size], word); word = strtok(NULL, " "); size++; }

    for(int pos=0; pos<size/2; pos++){
        char temp[strlen(str_arr[pos])]; strcpy(temp, str_arr[pos]); remove_compare(temp, "aeiou");
            if(!strcmp(temp, str_arr[size-pos-1])){ printf("%s-%s\n",str_arr[pos], str_arr[size-pos-1]); } }

    return 0;
}
