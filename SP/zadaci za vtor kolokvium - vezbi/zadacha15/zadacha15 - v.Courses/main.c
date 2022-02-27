#include <stdio.h>
#include <stdlib.h>

int pow_div(int n){ if(n<10){ return 1; } return 10 * pow_div(n/10); }
int digits(int n){ int cnt=0; while(n){cnt++; n/=10; } return cnt; }

int reverse(int num)
{
   if(num==0){ return 0; }
   return (((num%10==9?7:num%10) * pow_div(num)) + reverse(num/10));
}

int main()
{
    int num, Arr[1024], cnt=0, temp=0;

    while(scanf("%d", &num))
    {
        if(digits(num) != digits(reverse(reverse(num)))){ Arr[cnt] = num; }
        else { Arr[cnt] = reverse(reverse(num)); } cnt++;
    }

    for(int i=0; i<cnt; i++){ for(int j=i+1; j<cnt; j++){
    if(Arr[i] > Arr[j] ){ temp = Arr[i]; Arr[i] = Arr[j] ; Arr[j] = temp; } } }

    while(cnt>5){ cnt--; }  for(int i=0; i<cnt; i++){ printf("%d ", Arr[i]); } return 0;
}
