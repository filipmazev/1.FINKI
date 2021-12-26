#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n, move; scanf("%d %d%*c", &n, &move); int limit = ((int)'z' - (int)'a') + 1;

    while(n)
    {
        char string[1024]; scanf("%[^\n]%*c", string);

        for(int j=0; j<(int)strlen(string); j++)
        {
            char character = *(string+j);

            if(isalpha(character))
            {
                int pos = (((int)toupper(character) - (int)'A') + move) + 1; while(pos>limit){ pos-=limit; }
                int start = ((int)'A') - 1; if(islower(character)){ start = ((int)'a') - 1; }
                character = (char) (start+pos);
            }
                printf("%c", character);
        }
    printf("\n"); n--;
    }
    return 0;
}
