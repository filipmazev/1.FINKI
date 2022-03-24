#include <stdio.h>
#include <ctype.h>

void wtf()
{
    FILE *f = fopen("input.txt", "w");char c;
    while((c = getchar()) != EOF) { fputc(c, f); }
    fclose(f);
}

int main()
{
    wtf(); FILE *read = fopen("input.txt", "r"); int cnt=0, Arr[1024];

    while(!feof(read))
    {
        char character = fgetc(read);
        if(isdigit(character)){ Arr[cnt]=character-'0'; cnt++; }

        if(character == '\n')
        {
            printf("%d:",cnt); int temp;

            for(int i=0; i<cnt; i++){
                for(int j=i+1; j<cnt; j++){
            if(Arr[i] > Arr[j]){ temp = Arr[i]; Arr[i] = Arr[j]; Arr[j] = temp; } } }

            for(int i=0; i<cnt; i++){ printf("%d", Arr[i]); } cnt=0; printf("\n");
        }
    }

    return 0;
}
