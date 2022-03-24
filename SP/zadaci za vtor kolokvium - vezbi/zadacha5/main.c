#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wf()
{
    FILE *f = fopen("livce.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main()
{
    wf(); FILE *read = fopen("livce.txt", "r");
    int money, type; fscanf(read, "%d", &money); double mult, max=0, sum=1; char code[1024], save[1024];

    while(fscanf(read, "%s %d %lf", code, &type, &mult) == 3){
        sum*=mult; if(sum>max){ max=sum; sprintf(save, "%s %d %.2lf", code, type, mult); } }

    printf("%.2lf\n%s", money*sum, save); return 0;
}
