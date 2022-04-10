#include <iostream>
using namespace std;

class Angle
{
private:
    int deg, minutes, sec;
public:
    Angle(){}; ~Angle(){};

    int set_deg(int d){ deg = d; } int set_minutes(int m){ minutes = m; } int set_sec(int s){ sec = s; }
    int getSeconds(){ return sec; }

    int to_sec(){ return sec + (deg*3600) + (minutes*60); }
};

bool checker(int deg, int minutes, int sec)
{
    return !(deg>360 || minutes > 60 || minutes <= 0 || deg <= 0 || sec < 0);
}

bool changeOfSeconds(Angle a, int sec){ return a.getSeconds()!=sec; }

int main()
{
    Angle a1; int deg, minutes, sec; cin>>deg>>minutes>>sec;

    if (checker(deg, minutes, sec))
    {
    	a1.set_deg(deg); a1.set_minutes(minutes); a1.set_sec(sec);
        cout<<a1.to_sec();
        if (changeOfSeconds(a1,sec)){
        cout<<"Ne smeete da gi menuvate sekundite vo ramkite na klasata!"<<endl; }
    }

    else { cout<<"Nevalidni vrednosti za agol"; }

    return 0;
}
