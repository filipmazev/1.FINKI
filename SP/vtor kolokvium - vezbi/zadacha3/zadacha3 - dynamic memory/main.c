#include <stdio.h>
#include <stdlib.h>

void *remove_compare(char *word, char *comp)
{
    for(int i=0; i<strlen(word); i++) {
        for(int j=0; j<strlen(comp); j++){
            if(word[i] == comp[j]) { memmove(&word[i], &word[i + 1], strlen(word) - i); remove_compare(word, comp); } } }
}

int main()
{
    size_t size=1024; char *string = calloc(size, sizeof(char)); unsigned int i=0, j=0; char ch;

    while((ch = getchar()) != '\n'){
    if(i>=size){ size*=2; char *temp = realloc(string, size * sizeof(char)); string = temp; } *(string+i) = ch; i++; }

    char *word; word = strtok(string, " "); size_t lenght=size; char **str_arr = calloc(lenght, sizeof(char));

    while(word!=NULL){ if(j>=lenght){ lenght*=2; char **temp = realloc(str_arr, lenght * sizeof(char)); str_arr = temp; }
        str_arr[j] = calloc(strlen(word), sizeof(char)); strcpy(str_arr[j], word); word = strtok(NULL, " "); j++; }

    for(int pos=0; pos<j/2; pos++){
        char temp[strlen(str_arr[pos])]; strcpy(temp, str_arr[pos]); remove_compare(temp, "aeiou");
            if(!strcmp(temp, str_arr[j-pos-1])){ printf("%s-%s\n",str_arr[pos], str_arr[j-pos-1]); } }

    return 0;
}
