#include <stdio.h>
#include <ctype.h>
#include <string.h>

void wtf()
{
    FILE *f = fopen("broevi.txt", "w"); char c;
    while((c = getchar()) != EOF){ fputc(c, f); }
    fclose(f);
}

int main()
{
    wtf(); FILE *read = fopen("broevi.txt", "r"); int max=0, flag=0, size=1024; char string[size];

    while(fgets(string, size, read) != NULL)
    {
        char temp[size], number[size]; strcpy(temp, string); char *num = strtok(temp, " ");

        while(num!=NULL){
            if((int)(*(num+0) - '0')>max && flag){ max = (int)(*(num+0) - '0'); strcpy(number, num); number[strcspn(number,"\n")] = 0; }
            if(!flag){ flag=1;} num = strtok(NULL, " "); }

        if(*(string+0) != '0'){ puts(number); max = 0, flag=0; }
    }

    fclose(read); return 0;
}
