#include <stdio.h>
#include <ctype.h>

void letterFrequency (char *text, char letter)
{
    unsigned int i=0, cnt_lower=0, cnt_upper=0;

    while(*(text+i) != '\n'){
    if(isalpha(*(text+i))){ if(tolower(letter) == *(text+i)){ cnt_lower++; }
    if(toupper(letter) == *(text+i)){ cnt_upper++; } } i++; }

    printf("%c -> %.3f%%\n", tolower(letter), (cnt_lower/(float)i)*100);
    printf("%c -> %.3f%%\n", toupper(letter), (cnt_upper/(float)i)*100);
}

int main()
{
    size_t size = 1024; char *text = calloc(size, sizeof(char)); unsigned int i=0; char character=' ';

    while(character != '\n'){ scanf("%c", &character); *(text+i) = character; i++;
    if(i>size){ size*=2; void *temp = realloc(text, size * sizeof(char)); text = temp; } }

    char letter; scanf("%c", &letter); letterFrequency(text, letter); return 0;
}
