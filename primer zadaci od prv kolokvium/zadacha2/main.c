/* Да се напише програма во која од тастатура
се внесуваат непознат број мали букви сѐ додека
не се внесе знак што не е мала буква. За секој пар
последователни букви, во нов ред треба да се испечати
секвенца од буквите во абецеден редослед што се наоѓаат
меѓу нив (без нив) проследено со вкупниот број на вакви
букви. Секогаш печатењето се почнува од буквата што се
наоѓа понапред во азбуката кон таа што е поназад. Ако парот
букви е составен од две соседни букви во азбуката,
не се печати ништо. На крај да се испечати вкупниот број
на испечатени секвенци од букви. */
#include <stdio.h>

int main()
{
    char character = 'a', previous_character='a'; int i=0, cnt=0;

    while(!isupper(character))
    {
        scanf("%c", &character);
        int cnt_2 = 0, start = previous_character, end = character;
        int temp=start; if(start<end){ start=end; end=temp; }

        if(start>=((int)'a') && end>=((int)'a')){
        for(int i=end+1; i<start; i++){ printf("%c", i); cnt_2++; }
        if(cnt_2!=0){ printf(" %d",cnt_2); cnt++; } previous_character = character; printf("\n"); }
    }

    printf("%d", cnt);

    return 0;
}
