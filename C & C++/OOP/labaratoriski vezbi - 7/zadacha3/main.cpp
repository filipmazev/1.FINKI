#include <iostream>
#include <math.h>

#define pi 3.14

enum type { square=1, circle, triangle };

class Shape
{
protected:
    int side{ int() };
public:
    Shape() {}
    Shape(int side) { this->side = side; }

    Shape(const Shape& s){ this->side = s.side; }

    inline virtual double P() = 0;
    inline virtual void print() = 0;
    inline virtual int getType() = 0;

    ~Shape() {}
};

class Square : public Shape
{
public:
    Square() {}

    Square(int side) : Shape(side) { }

    Square(const Square& s) : Shape(s) { }

    inline double P() noexcept { return pow(this->side, 2); }
    inline void print() { std::cout << "Kvadrat so plostina = " << this->P() << std::endl; }
    inline int getType() noexcept { return square; }

    ~Square() {}
};

class Circle : public Shape
{
public:
    Circle() {}

    Circle(int side) : Shape(side) { }

    Circle(const Circle& c) : Shape(c) { }

    inline double P() noexcept { return pi * pow(this->side, 2); }
    inline void print() { std::cout << "Krug so plostina = " << this->P() << std::endl; }
    inline int getType() noexcept { return circle; }

    ~Circle() {}
};

class Triangle : public Shape
{
public:
    Triangle() {}

    Triangle(int side) : Shape(side) { }

    Triangle(const Triangle& t) : Shape(t) { }

    inline double P() noexcept { return (sqrt(3) / 4) * pow(this->side, 2); }
    inline void print() { std::cout << "Triagolnik so plostina = " << this->P() << std::endl; }
    inline int getType() noexcept { return triangle; }

    ~Triangle() {}
};

void checkNumTypes(Shape** ptr_arr, int n) {
    int cnt_square = 0, cnt_circle = 0, cnt_triangle = 0;

    for (int i = 0; i < n; i++) { switch (ptr_arr[i]->getType()) { case 1: cnt_square++; break; case 2: cnt_circle++; break; case 3: cnt_triangle++; break; } }

    std::cout << "Broj na kvadrati vo nizata = " << cnt_square << std::endl;
    std::cout << "Broj na krugovi vo nizata = " << cnt_circle << std::endl;
    std::cout << "Broj na triagolnici vo nizata = " << cnt_triangle << std::endl;
}

int main()
{
    int n, classType, side; std::cin >> n; Shape** ptr_arr = new Shape * [n];

    for (int i = 0; i < n; ++i) {
        std::cin >> classType >> side;

        switch (classType) {
            case 1: ptr_arr[i] = new Square(side); break;
            case 2: ptr_arr[i] = new Circle(side); break;
            case 3: ptr_arr[i] = new Triangle(side); break;
        }
    }

    for (int i = 0; i < n; ++i) { ptr_arr[i]->print(); }

    checkNumTypes(ptr_arr, n); return 0;
}
