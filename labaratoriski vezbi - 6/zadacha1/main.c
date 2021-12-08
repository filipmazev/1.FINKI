#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n; scanf("%d %d", &m, &n); while(m<=1 || n>100){ scanf("%d %d", &m, &n); }
    int default_value = -1; int Array[m+2][n+2], Transformed_Array[m+2][n+2];

    for(int i=0; i<m+2; i++){ for(int j=0; j<n+2; j++){ Array[i][j] = default_value; Transformed_Array[i][j] = default_value;  } }
    for(int i=1; i<m+1; i++){ for(int j=1; j<n+1; j++){ scanf("%d", &Array[i][j]);  } }

    for(int i=0; i<m+2; i++)
    {
        for(int j=0; j<n+2; j++)
        {
            int cnt = 0; if(Array[i][j] != default_value && Array[i][j] == 0)
            {
                for(int kernel_i=i-1; kernel_i<=i+1; kernel_i++)
                {
                    for(int kernel_j=j-1; kernel_j<=j+1; kernel_j++)
                    {
                        if(Array[kernel_i][kernel_j] == 1){ cnt++; }
                    }
                }
                Transformed_Array[i][j] = cnt;
            }
        }
    }

    for(int i=1; i<m+1; i++){ for(int j=1; j<n+1; j++){ if(Transformed_Array[i][j] == default_value){ printf("* "); } else { printf("%d ", Transformed_Array[i][j]); } } printf("\n"); }

    return 0;
}

