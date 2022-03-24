#include <iostream>
using namespace std;

class Circle
{
private:
    float radius; const float pi=3.14;
public:
    Circle(){}; Circle(float r){ radius = r; }; ~Circle(){};

    float P(){ return 2*radius*pi; }
    float L(){ return pi*(radius*radius); }
    bool is_equal(){ Circle c(radius); return c.P() == c.L(); }
};

int main()
{
	float r; cin>>r; Circle c(r);
	cout<<c.P()<<endl<<c.L()<<endl<<c.is_equal()<<endl;
	return 0;
}
