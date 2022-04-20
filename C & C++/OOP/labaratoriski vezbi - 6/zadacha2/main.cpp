#include <iostream>

class Square
{
protected:
    double a{0.00};
public:
    Square(){ this->a = 0.00; }

    Square(double a){ this->a = a; }

    Square(const Square& s){ if(this != &s) { this->a = s.a; } }
    Square &operator = (const Square& s){ if(this != &s) { this->a = s.a; } return *this; }

    double perimeter(){ return 4*a; }

    double area(){ return a*a; }

    void print(){ std::cout<<"Kvadrat so dolzina a="<<this->a<<" ima plostina P="<<this->area()<<" i perimetar L="<<this->perimeter()<<std::endl; }

    double getA(){ return this->a; }
};

class Rectangle : protected Square
{
private:
    double x{0.00}, y{0.00};
public:
    Rectangle(){ this->x = 0.00; this->y = 0.00; }

    Rectangle(Square& k, double x, double y){ this->x = k.getA()+x; this->y = k.getA()+y; this->a = (x==y?x:k.getA()); }

    Rectangle(const Rectangle& r){ if(this != &r){ this->x = a+r.x; this->y = a+r.y; this->a = (x==y?x:r.a); } }

    Rectangle &operator = (const Rectangle& r){ if(this != &r){  this->x = a+r.x; this->y = a+r.y; this->a = (x==y?x:r.a); } return *this; }

    ~Rectangle(){}

    double perimeter(){ if(this->x == this->y){ return Square::perimeter(); } else { return 2*(this->x+this->y); } }

    double area(){ if(this->x == this->y){ return Square::area(); } else { return this->x*this->y; } }

    void print(){ if(this->x == this->y){ Square::print(); } else { std::cout<<"Pravoagolnik so strani: "<<this->x<<" i "<<this->y<<" ima plostina P="<<this->area()<<" i perimetar L="<<this->perimeter()<<std::endl; } }
};

int main()
{
	int n; double a, x, y; Square* square_arr; Rectangle* rectangle_arr; std::cin>>n;
    square_arr = new Square[n]; rectangle_arr = new Rectangle[n];

	for (int i=0; i<n; i++){ std::cin>>a; square_arr[i] = Square(a); }

	for (int i=0; i<n; i++){ std::cin>>x>>y; rectangle_arr[i]=Rectangle(square_arr[i],x,y); }

	int testCase; std::cin>>testCase;

	if (testCase==1){ std::cout<<"===Testiranje na klasata Kvadrat==="<<std::endl; for (int i=0; i<n; i++){ square_arr[i].print(); } }

	else { std::cout<<"===Testiranje na klasata Pravoagolnik==="<<std::endl; for (int i=0; i<n; i++){ rectangle_arr[i].print(); } }
}
