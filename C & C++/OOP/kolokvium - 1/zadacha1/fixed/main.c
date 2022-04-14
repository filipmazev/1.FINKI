#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct CertificateCov19
{
    int day, month, year, vax_num;
    char vax_type[50];
} vax;

typedef struct Patient
{
    char name[50];
    int embg;
    vax v_c;
} Patient;

void print(Patient *arr, int num, char *date)
{
    int d, m, y;
    sscanf(date, "%d/%d/%d", &d, &m, &y);

    for(int i=0; i<num; i++)
    {
        if(arr[i].v_c.vax_num == 2 && abs(m - arr[i].v_c.month) == 6)
        {
            printf("Ime: %s - embg: %d\n", arr[i].name, arr[i].embg);
        }
    }
}

int main()
{
    int n; scanf("%d", &n); Patient arr[100]; char date[9];

    for(int i=0; i<n; i++)
    {
        scanf("%s %d %s %s %d",arr[i].name, &arr[i].embg, arr[i].v_c.vax_type, date, &arr[i].v_c.vax_num);
        sscanf(date, "%d/%d/%d", &arr[i].v_c.day, &arr[i].v_c.month, &arr[i].v_c.year);
    }

    scanf("%s", date);
    print(arr, n, date);
}
