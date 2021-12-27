#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int reverse(int num)
{
   if(num==0){ return 0; }
   return (((num%10==9?7:num%10) * ((int)pow(10, (int)(num==0?1:log10(num))))) + reverse(num/10));
}

int main()
{
    int num, Arr[1024], cnt=0, temp=0;

    while(scanf("%d", &num))
    {
        int transformed = reverse(reverse(num));
        if(((int)(num==0?1:log10(num)+1)) != ((int)(transformed==0?1:log10(transformed)+1))){ Arr[cnt] = num; }
        else { Arr[cnt] = reverse(reverse(num)); } cnt++;
    }

    for(int i=0; i<cnt; i++){ for(int j=i+1; j<cnt; j++){
    if(Arr[i] > Arr[j] ){ temp = Arr[i]; Arr[i] = Arr[j] ; Arr[j] = temp; } } }

    while(cnt>5){ cnt--; }  for(int i=0; i<cnt; i++){ printf("%d ", Arr[i]); } return 0;
}
