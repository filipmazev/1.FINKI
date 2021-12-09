#include <stdio.h>
#include <stdlib.h>

double max(double *arr, int n)
{
    double max=0;
    for(int i=0; i<n;i++){ if(arr[i] > max){ max=arr[i]; } }
    return max;
}

double min(double *arr, int n)
{
    double min=max(arr, n);
    for(int i=0; i<n;i++){ if(arr[i] < min){ min=arr[i]; } }
    return min;
}

void normalize(double *arr, int n)
{
    double mini = min(arr,n), maxi = max(arr,n);
    for(int i=0; i<n; i++){ arr[i] = (arr[i] - mini) / (maxi-mini);
    printf("%.3lf ", arr[i]); }
}

int main()
{
    float *niza[200];
    int i,n;

    scanf("%d", &n);

    for (i=0;i<n;i++) { scanf("%lf", &niza[i]); }

    printf("MAX -> %.3f\n", max(niza,n));
    printf("MIN -> %.3f\n", min(niza,n));

    normalize(niza,n);

return 0;
}
