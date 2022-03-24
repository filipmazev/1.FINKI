#include <stdio.h>
#include <stdlib.h>

float max(float *arr, int n)
{
    float max=0;
    for(int i=0; i<n; i++){
        if(arr[i] > max){ max=arr[i]; } }
    return max;
}

float min(float *arr, int n)
{
    float min=max(arr, n);
    for(int i=0; i<n; i++){
        if(arr[i] < min){ min=arr[i]; } }
    return min;
}

void normalize(float *arr, int n)
{
    float mini=min(arr,n), maxi=max(arr,n);

    for(int i=0; i<n; i++){
        float x = arr[i];
        x = (x-mini) / (maxi - mini); arr[i] = x; }
}

int main ()
{
    float niza [200];
    int i, n;

    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        scanf("%f", &niza[i]);
    }

    printf("MAX -> %.3f\n", max(niza,n));
    printf("MIN -> %.3f\n", min(niza,n));

    normalize(niza,n);

    for (i=0; i<n; i++)
    {
        printf("%.3f ", niza[i]);
    }

    return 0;
}
