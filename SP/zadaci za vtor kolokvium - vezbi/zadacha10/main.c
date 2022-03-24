#include <stdio.h>
#include <stdlib.h>

void wf()
{
    FILE *f = fopen("podatoci.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main()
{
    int flag_1=1, flag_2=0; wf(); FILE *read = fopen("podatoci.txt", "r"); scanf("%*c");
    char string[1024]; scanf("%[^\n]", string); char comp1 = *(string+0), comp2 = *(string+1);

    while(!feof(read))
    {
        char character = fgetc(read);
        if(character == comp2){ flag_2=1; }
        if(flag_1 == 0 && flag_2 == 0) { printf("%c", character); }
        if(character == comp1){ flag_1=0;  }
        if(character=='\n'){ flag_1=1; flag_2=0; printf("\n"); }
    } return 0;
}
