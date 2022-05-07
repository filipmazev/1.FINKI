#include <iostream>
#include <string.h>
#include <math.h>

#define PI 3.14
#define SIZE 1024

class Toy {
public:
    virtual float getVolume() = 0;
    virtual float getMass() = 0;
    virtual float getArea() = 0;
};

class Form : public Toy {
protected:
    char* color{ nullptr };
    int density{ int() };
public:
    Form() {}

    Form(char* color, int density) {
        this->color = new char[strlen(color) + 1]; strcpy(this->color, color);
        this->density = density;
    }

    Form(const Form& f) {
        if (this != &f) {
            this->color = new char[strlen(f.color) + 1]; strcpy(this->color, f.color);
            this->density = f.density;
        }
    }

    ~Form() { if (this->color != nullptr) { delete[] this->color; this->color = nullptr; } }
};

class Sphere : public Form {
protected:
    int radius{ int() };
public:
    Sphere() {}

    Sphere(char* color, int density, int radius) : Form(color, density) {
        this->radius = radius;
    }

    Sphere(const Sphere& s) : Form(s.color, s.density) {
        this->radius = s.radius;
    }

    float getVolume() { return (4.0 / 3.0) * (PI * pow(radius, 3)); }
    float getMass() { return this->getVolume() * density; }
    float getArea() { return 4 * PI * pow(radius, 2); }

    ~Sphere() {}
};

class Cubeoid : public Form {
protected:
    int x{ int() }, y{ int() }, z{ int() };
public:
    Cubeoid() {}

    Cubeoid(char* color, int density, int x, int y, int z) : Form(color, density) {
        this->x = x; this->y = y; this->z = z;
    }

    Cubeoid(const Cubeoid& c) : Form(c.color, c.density) {
        this->x = c.x; this->y = c.y; this->z = c.z;
    }

    float getVolume() { return x * y * z; }
    float getMass() { return this->getVolume() * density; }
    float getArea() { return 2 * x * z + 2 * x * y + 2 * z * y; }

    ~Cubeoid() {}
};


int main() {
    int n; std::cin >> n; Toy** ptr_arr = new Toy * [n]; int test_case; float sum = 0.00;

    for (int i = 0; i < n; i++) {
        std::cin >> test_case;

        if (test_case == 1) {
            char* color = new char[SIZE]; float density; int r;
            std::cin >> color >> density >> r; ptr_arr[i] = new Sphere(color, density, r);
        }

        if (test_case == 2) {
            char* color = new char[SIZE]; float density; int x, y, z;
            std::cin >> color >> density >> x >> y >> z; ptr_arr[i] = new Cubeoid(color, density, x, y, z);
        }
    }

    Toy* Petra; char* color = new char[SIZE]; float density; int x, y, z;
    std::cin >> color >> density >> x >> y >> z; Petra = new Cubeoid(color, density, x, y, z);

    float max_volume = 0.00, min_area = ptr_arr[0]->getArea();

    for (int i = 0; i < n; i++) {
        sum += ptr_arr[i]->getMass();
        if (ptr_arr[i]->getVolume() > max_volume) { max_volume = ptr_arr[i]->getVolume(); }
        if (ptr_arr[i]->getArea() < min_area) { min_area = ptr_arr[i]->getArea(); }
    }

    if (sum > Petra->getMass()) { std::cout << "DA" << std::endl; }
    else { std::cout << "NE" << std::endl; }
    std::cout << "Razlikata e: " << abs(max_volume - Petra->getVolume()) << std::endl;
    std::cout << "Razlikata e: " << abs(min_area - Petra->getArea()) << std::endl;

    return 0;
}

