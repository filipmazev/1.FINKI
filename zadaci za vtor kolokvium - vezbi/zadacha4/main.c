#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n; scanf("%d %d", &m, &n); int Arr[m][n];
    for(int i=0; i<m; i++){ for(int j=0; j<n; j++){ scanf("%d", &Arr[i][j]); } }
    int pos_1, pos_2; scanf("%d %d", &pos_1, &pos_2);

    int quadrants[4]={0,0,0,0};

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int kv = (i<pos_1)?(j>=pos_2?1:2):(j<pos_2?3:4);
                quadrants[kv-1]+=Arr[i][j]; } }

    for(int i=0; i<4; i++){ printf("%d ", quadrants[i]); } return 0;
}
