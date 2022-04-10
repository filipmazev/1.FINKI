#include <stdio.h>
#include <stdlib.h>

int checker(int number, int number_original, int status)
{
    if (number == 0){ return number_original; }
    if(number/10>0){ if(((number%10 >= ((number/10)%10))?1:0) == status){ return 0; } }
    return checker(number/10, number_original, ((number%10 >= ((number/10)%10))?1:0));
}

int main()
{
    size_t size=100; int number, check=1, *storage = calloc(size, sizeof(int)); unsigned int i=0;

    while((check = scanf("%d", &number)))
    {
        int status = (((number%10) <= ((number/10)%10))?1:0);
        if(number>=10){  *(storage+i) = checker(number, number, status); i++;
        if(i>=size){ size*=2; void* temp_storage = realloc(storage, size * sizeof(int)); storage = temp_storage; } }
    }

    for(unsigned int j=0; j<i; j++){ if(*(storage+j) != 0) printf("%d\n", *(storage+j)); }

    free(storage); return 0;
}
