#include <stdio.h>
#include <stdlib.h>

void wf()
{
    FILE *f = fopen("livce.txt", "w"); char c;
    while((c = getchar()) != '#') { fputc(c, f); }
    fclose(f);
}

int main()
{
    wf();

    FILE *f = fopen("livce.txt", "r");

    int suma;
    fscanf(f, "%d", &suma);

    int tip;
    double dobivka = suma, maxkoef = 0, koef;
    char sifra[10];
    char sol[105];

    while(fscanf(f, "%s %d %lf", sifra, &tip, &koef) == 3)
    {
        dobivka *= koef;
        if(koef > maxkoef)
        {
            maxkoef = koef;
            sprintf(sol,"%s %d %.2f", sifra, tip, koef);
        }
    }

    puts(sol);
    printf("%.2f\n", dobivka);

	return 0;
}
