#include <iostream>
#include <ctime>
#include <windows.h>

int PRNG(int lower, int upper){ return (rand() % (upper - lower+1) + lower); }

int main()
{
    Sleep(1000); srand((unsigned)time(NULL)); double runs; std::cin>>runs;
    int points=0, score=0, cnt_hit=0, cnt_miss=0, cnt_bullseye=0, cnt_outer=0, cnt_other=0, cnt_treble=0, cnt_double=0, cnt_single=0;

    for(int i=0; i<runs; i++)
    {
        if(PRNG(1,100) < 60){ cnt_miss++; } else { points=0; cnt_hit++;
        if(PRNG(1,999) == 1){ points=50; cnt_bullseye++; } else if(PRNG(1,110) == 1){ cnt_outer++; points=25; } else { points=PRNG(1,20); cnt_other++; }
        if(PRNG(10,155) == 10){ cnt_treble++; points*=3; } else if(PRNG(1,10) == 1){ cnt_double++; points*=2; } else { cnt_single++; } score+=points; }
    }

    std::cout<<std::endl<<" | FINAL SCORE: "<<score<<"p | AVERAGE POINTS PER THROW: "<<score/runs<<"p"<<std::endl;
    std::cout<<" | TOTAL THROWS: "<<runs<<" | HITS: "<<cnt_hit<<" | MISSES: "<<cnt_miss<<std::endl;
    std::cout<<" | (50p) BULLSEYES: "<<cnt_bullseye<<" | (25p) OUTER BULLSEYES: "<<cnt_outer<<" | OTHER: "<<cnt_other<<std::endl;
    std::cout<<" | (p*1) SINGLE: "<<cnt_single<<" | (p*2) DOUBLE: "<<cnt_double<<" | (p*3) TREBLE: "<<cnt_treble<<std::endl; return 0;
}
