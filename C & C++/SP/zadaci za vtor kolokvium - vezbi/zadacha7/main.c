#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int rows, columbs; scanf("%d %d", &rows, &columbs);
    int Matrix[rows][columbs], Arr_Dif[rows]; double Arr_Avg[rows];

    for(int i=0; i<rows; i++){ double sum = 0;
        for(int j=0; j<columbs; j++){
            scanf("%d", &Matrix[i][j]); sum+=Matrix[i][j]; }
        Arr_Avg[i] = sum / columbs; }

    for(int i=0; i<rows; i++){ double diff=-1; int member;
        for(int j=0; j<columbs; j++){
            if(fabs(Matrix[i][j]-Arr_Avg[i]) > diff){
                diff = fabs(Matrix[i][j]-Arr_Avg[i]); member = Matrix[i][j]; } }
        Arr_Dif[i] = member; }

    for(int i=0; i<rows; i++) { printf("%d ", Arr_Dif[i]); } return 0;
}
