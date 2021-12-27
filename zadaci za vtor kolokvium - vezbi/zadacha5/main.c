#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wf()
{
    FILE *f = fopen("livce.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main(void)
{
    int cnt_r=0, cnt_l=0, size_l=0, i=0, pos=0; double total=1,max=0;

    wf(); FILE *read_asses = fopen("livce.txt", "r");
    while(!feof(read_asses)){ if(fgetc(read_asses) == '\n'){ cnt_r++; if(cnt_l>size_l){ size_l=cnt_l; } cnt_l=0; } cnt_l++; }

    fclose(read_asses); FILE *read = fopen("livce.txt", "r"); char *line[cnt_r][size_l];
    while(fgets(line[i], size_l+1, read)){ line[i][strlen(line[i]) - 1] = '\0'; i++; }

    char *temp, string_temp[size_l+1]; double value = strtod(line[0], &temp);

    for(int j=1; j<i; j++)
    {
        char string[size_l+1]; strcpy(string, ""); strcpy(string, line[j]);
        for(int k=0; k<strlen(string); k++)
        {
            strncat(string_temp, &string[k], 1);
            if(string[k] == ' ' || string[k] == '\0' || string[k] == '\n')
            {
                char *temp_2; double mult = strtod(string_temp, &temp_2);
                char value_save[size_l+1]; snprintf(value_save, size_l+1, "%.2lf", mult);

                if(k>=10){ if(mult>max){ max=mult; pos=j; } total*=mult; }
                strcpy(string_temp, "");
            }
        }
    }

    printf("%s", line[pos]); printf("%.2lf", value*total); return 0;
}
