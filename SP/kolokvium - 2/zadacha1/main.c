#include <stdio.h>
#include <stdlib.h>

int diff(int num)
{
    int temp=num/10, rez=1; if(num == 0){ return 0; }
    while(temp){ if(temp%10 == num%10){ rez=0; break; } temp/=10; }
    return diff(num/10) + rez;
}

int sort(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(arr[j]>arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    for(int i=0; i<n; i++) { printf("%d\n", arr[i]); }
}

int main()
{
    int x, num; scanf("%d", &x);
    int size; scanf("%d", &size); int arr[100], i=0, temp=size;

    while(size){ scanf("%d", &num); if(diff(num)==x){  arr[i] = num; i++; } size--; }

    sort(arr, i); return 0;
}
