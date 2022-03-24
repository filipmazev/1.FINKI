#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, max=0; scanf("%d", &n); int save[n];

    for(int i=0; i<n; i++){ scanf("%d", &save[i]);
        for(int j=i; j>=0; j--){
            if(abs(save[j] - save[i]) > max ){ max = abs(save[i] - save[j]); } } }

    printf("Najgolema razlika: %d", max);

    return 0;
}
