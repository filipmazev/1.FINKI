#include <stdio.h>
#include <string.h>
#include <ctype.h>

void writeToFile()
{
    FILE *f = fopen("text.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main()
{
    char string[1024], max_string[1024]; int cnt=0, max=0, sum=0, cnt_l=0;
    writeToFile(); FILE *f = fopen("text.txt", "r");

    while (fgets(string, 1024, f) != '\0')
    {
        for(int i=0; i<strlen(string); i++) { if(isspace(string[i])) { cnt++; } }
        if(cnt>max){ max=cnt; strcpy(max_string, string); }
        printf("%d\n", cnt); sum+=cnt; cnt=0; cnt_l++;
    }

    printf("%.2lf\n", (float)sum/cnt_l);

    for(int i=0; i<strlen(max_string); i++){
        printf("%c", isalpha(*(max_string+i))? *(max_string+i)^32:*(max_string+i)); }
}
