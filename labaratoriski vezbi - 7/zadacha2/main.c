#include <stdio.h>
#include <stdlib.h>

void Christmas_Tree(int n)
{
    int space=n/2, stars=1;
    for(int i=0; i<=n/2; i++)
    {
        int temp_space = space; while(temp_space){ printf(" "); temp_space--; }
        int temp_stars = stars; while(temp_stars){ printf("*"); temp_stars--; }
        printf("\n"); space--; stars+=2;
    }
}

int main()
{
    int n; scanf("%d", &n); Christmas_Tree(n);
    return 0;
}
