#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t size = ((int)'Z' - (int)'A') + 1; char Alphabet[size];
    char character; int move, position; scanf("%c %d", &character, &move);

    for(int i=0; i<size; i++){
        Alphabet[i] = (char)((int)'A' + i);
        if(Alphabet[i] == character){ position = i; } }

    while(position+move>size){ move -= size; }

    printf("%c", Alphabet[position+move]); return 0;
}
