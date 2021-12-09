#include <stdio.h>
#include <ctype.h>

void writeToFile()
{
    FILE *f = fopen("text.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main()
{
    writeToFile();
    char character; FILE *read = fopen("text.txt", "r");
    int cnt_upper=0, cnt_lower=0, cnt_total=0;

    while(!feof(read)){ character = fgetc(read);
    if(isalpha(character)){ cnt_total++; if(isupper(character)==0){ cnt_lower++; } else cnt_upper++; } }

    printf("%.4lf\n%.4lf", cnt_upper/(float)cnt_total, cnt_lower/(float)cnt_total);

    fclose(read); return 0;
}
