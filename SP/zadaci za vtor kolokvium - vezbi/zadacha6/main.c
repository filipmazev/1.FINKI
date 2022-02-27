#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, flag=0, cnt=0; scanf("%d %d", &m, &n); int Arr[m][n];
    for(int i=0; i<m; i++) { for(int j=0; j<n; j++){ scanf("%d", &Arr[i][j]); } }

    for(int i=0; i<m; i++){ flag=0;
        for(int j=0; j<n; j++){
            flag++; if(Arr[i][j]==0){ flag=0; } if(flag==3){ cnt++; break; } } }

    for(int j=0; j<n; j++){ flag=0;
        for(int i=0; i<m; i++){
            flag++; if(Arr[i][j]==0){ flag=0; } if(flag==3){ cnt++; break; } } }

    printf("%d", cnt); return 0;
}
