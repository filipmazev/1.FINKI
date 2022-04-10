/* Од тастатура се внесува цел број m, а потоа непознат број цели броеви. Да се
испечатат должините на секвенците составени од најмалку два
последователни броја за кои истовремено важи:
• следниот број е строго поголем од претходниот и
• секој од нив има точно m цифри.
Задачата да се реши без користење на низи. */
#include <stdio.h>
#include <math.h>

int main()
{
    int m, number, num_prev=0, cnt=1; scanf("%d", &m);

    while(scanf("%d", &number)){
    if(number > num_prev && ((int)(number==0?1:log10(number)+1)) == m && ((int)(num_prev==0?1:log10(num_prev)+1)) == m) { cnt++; }
    else { if(cnt>=2) {  printf("%d ", cnt); } cnt=1; } num_prev=number; }

    printf("%d ", cnt);

    return 0;
}

