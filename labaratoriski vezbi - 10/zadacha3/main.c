#include <stdio.h>
#include <ctype.h>

void writeToFile() {
    FILE *f = fopen("text.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f); }

int main()
{
    writeToFile(); size_t buffer = 1024;
    char character; FILE *read = fopen("text.txt", "r");
    int cnt_words=0, max=0, cnt_line=0, line=0, words_total=0;

    while(!feof(read))
    {
        character = fgetc(read);
        if(character == ' ' || character == '\t' || character == '\n' || character == '\0'){ cnt_words++; }
        if(character == '\n' || character == '\0'){ cnt_line++; printf("%d\n", cnt_words);
            if(cnt_words>max){ max=cnt_words; line=cnt_line; } words_total+=cnt_words; cnt_words=0; }
    }

    printf("%.2lf\n", words_total/(float)cnt_line); fclose(read); cnt_line=1;

    FILE *read_again = fopen("text.txt", "r");
    while(!feof(read_again))
    {
        character = fgetc(read_again);
        if(character == '\n' || character == '\0' || character == '\t'){ cnt_line++; }
        if(cnt_line==line){
            if(isalpha(character)){ if(isupper(character)==0) { character = toupper(character); } else character = tolower(character); }
            if(character != '\n') { printf("%c", character); } }
    }

    fclose(read); return 0;
}
