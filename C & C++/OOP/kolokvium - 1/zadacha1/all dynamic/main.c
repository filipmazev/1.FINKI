#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

typedef struct CertificateCov19 { int day, month, year, vax_num; char *vax_type; } vax;

typedef struct Patient { char *name, *embg; vax v_c; } Patient;

void print(Patient *arr, int num, char *date)
{
    int d, m, y; sscanf(date, "%d/%d/%d", &d, &m, &y);
    for(int i=0; i<num; i++){ if(arr[i].v_c.vax_num == 2 && abs(m - arr[i].v_c.month) == 6){ printf("Ime: %s - embg: %s\n", arr[i].name, arr[i].embg); } }
}

char *string()
{
    char *str = (char*) calloc(sizeof(char*), 1); int cnt=0; fflush(stdin); char c=' ';
    while(c != '\n'){ scanf("%c", &c); if(c != '\n') { str[cnt] = c; str=(char*)realloc(str, ++cnt * sizeof(char*)); } else{ str[cnt] = NULL; } }
    return str;
}

int main()
{
    size_t size; scanf("%d", &size); size_t n=size; Patient *arr = (Patient*) malloc(sizeof(Patient)*size);

    for(int i=0; i<n; i++)
    {
        arr[i].name = string(); arr[i].embg = string(); arr[i].v_c.vax_type = string();
        sscanf(string(), "%d/%d/%d", &arr[i].v_c.day, &arr[i].v_c.month, &arr[i].v_c.year); scanf("%d",&arr[i].v_c.vax_num);
    }

    print(arr, n, string()); free(arr); return 0;
}
