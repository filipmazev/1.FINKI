#include <stdio.h>
#include <ctype.h>

// ne menuvaj ovde
void wtf()
{
    FILE *f = fopen("dat.txt", "w"); char c;
    while((c = getchar()) != EOF) { fputc(c, f); }
    fclose(f);
}

int main()
{
    wtf(); FILE *read = fopen("dat.txt", "r");
    int cnt_digit=0, cnt_total=0, i=0, max=0, pos=0, last_pos=0, last_pos_test=0, flag=0, Arr_List[1024];

    while(!feof(read))
    {
        char character = fgetc(read); cnt_total++;
        if(isdigit(character)){ last_pos++; Arr_List[i]=last_pos; cnt_digit++; }
        if(cnt_total>=max && cnt_digit>=2){ pos=i; max=cnt_total; }
        if(character == '\n'){ i++; cnt_digit=0; cnt_total=0; last_pos=0; }
    }

    fclose(read); FILE *read_again = fopen("dat.txt", "r"); i=0;

    while(!feof(read_again))
    {
        char character = fgetc(read_again);
        if(i==pos){
            if(isdigit(character)){ flag=1; last_pos_test++; }
            if(flag){ printf("%c", character); }
            if(last_pos_test == Arr_List[pos]){ break; } }
        if(character == '\n'){ i++; }
    }

    return 0;
}
