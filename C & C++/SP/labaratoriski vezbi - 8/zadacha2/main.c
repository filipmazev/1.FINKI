#include <stdio.h>
#include <stdlib.h>

int check(int num, int k, int sum)
{
    if (num == 0) { return sum; }
    int temp=num, div=1; while(temp>10){ div*=10; temp/=10; }
    if((num/div)%10 > k){ printf("%d", num/div%10); sum+=(num/div)%10; }
    return check(num - (num/div) * div, k, sum);
}

int main()
{
    int k, n; scanf("%d %d", &k, &n); int number;

    for(int i=0; i<n; i++){ scanf("%d", &number);
    int sum = check(number, k, 0); printf(" : %d\n",sum); }

    return 0;
}
