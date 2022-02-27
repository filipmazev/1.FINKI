#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m; double avg=0; scanf("%d %d", &n, &m); int Matrix[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &Matrix[i][j]); avg+=Matrix[i][j]; } }

    avg/=n*m; int Matrix_j[n][m], start=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(Matrix[0][j]>=avg){ if(!start){start=j;} Matrix_j[i][j] = Matrix[i][j]; } } }

    for(int i=0; i<n; i++){
        if(Matrix_j[i][start]<avg){ continue; }
            for(int j=start; j<m; j++){
                printf("%d ", Matrix_j[i][j]); }
        printf("\n"); } return 0;
}
