#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int move, limit = ((int)'z' - (int)'a') + 1;

    char character; scanf("%c", &character); scanf("%d", &move);

    int pos = (((int)toupper(character) - (int)'A') + move) + 1; while(pos>limit){ pos-=limit; }
    int start = ((int)'A') - 1; if(islower(character)){ start = ((int)'a') - 1; }
    printf("%c", (char) (start+pos)); return 0;
}
