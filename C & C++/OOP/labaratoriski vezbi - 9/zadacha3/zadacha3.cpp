#include <iostream>
#include <string.h>

constexpr auto DEFAULT_DENSITY = 0.8;
constexpr auto DEFAULT_MASS = 0.2;
constexpr auto REG_SIZE = 8;

class Mass {
public:
    inline virtual double getMass() = 0;
    inline virtual void print() = 0;
};

class Package : public Mass {
protected:
    double volume{ double() }; int quantity{ int() };
public:
    Package() {}
    Package(double volume, int quantity) { this->volume = volume; this->quantity = quantity; }
    Package(const Package& p) { if (this != &p) { this->volume = p.volume; this->quantity = p.quantity; } }
    inline Package& operator = (const Package& p) noexcept { if (this != &p) { this->volume = p.volume; this->quantity = p.quantity; } return *this; }
    ~Package() {}

    static double density; static double mass;
    inline double getMass() noexcept { return (this->volume * density + mass); }
};

double Package::density = DEFAULT_DENSITY;
double Package::mass = DEFAULT_MASS;

class Juices : public Package {
private:
    bool fizzy{ bool() };
public:
    Juices() : Package() {}
    Juices(double volume, int quantity, bool fizzy) : Package(volume, quantity) { this->fizzy = fizzy; }
    Juices(const Juices& j) : Package(j.volume, j.quantity) { if (this != &j) { this->fizzy = j.fizzy; } }
    inline Juices& operator = (const Juices& j) { if (this != &j) { this->volume = j.volume; this->quantity = j.quantity; this->fizzy = j.fizzy; } return *this; }
    ~Juices() {}

    inline void print() noexcept { std::cout << "Paket sok" << std::endl; std::cout << "kolicina " << this->quantity << ", so po " << this->volume * density << " l(dm3)" << std::endl; }
    inline double getMass() noexcept { return (quantity * ((this->volume * density + mass))) + (this->fizzy == false ? (0.1 * quantity) : 0); }
};

class Wines : public Package {
private:
    double percent{ double() };
public:
    Wines() : Package() {}
    Wines(double volume, int quantity, double percent) : Package(volume, quantity) { this->percent = percent; }
    Wines(const Wines& w) : Package(w.volume, w.quantity) { if (this != &w) { this->percent = w.percent; } }
    inline Wines& operator = (const Wines& w) { if (this != &w) { this->volume = w.volume; this->quantity = w.quantity; this->percent = w.percent; } return *this; }
    ~Wines() {}

    inline void print() noexcept { std::cout << "Paket vino" << std::endl; std::cout << "kolicina " << this->quantity << ", " << this->percent * 100 << "% alkohol od po " << this->volume * density << " l(dm3)" << std::endl; }
    inline double getMass() noexcept { return (quantity * ((this->volume * density + mass))) * (0.9 + this->percent); }
};

class Truck {
private:
    char* name{ nullptr }, * registration{ nullptr }; Mass** ptr_arr{ nullptr }; int num{ 0 };
public:
    Truck() {}

    Truck(char* name) { this->name = new char[strlen(name) + 1]; strcpy(this->name, name); }

    Truck(char* registration, char* name) {
        this->name = new char[strlen(name) + 1]; strcpy(this->name, name);
        this->registration = new char[strlen(registration) + 1]; strcpy(this->registration, registration);
    }

    Truck(const Truck& t) {
        if (this != &t) {
            this->num = t.num;
            delete[] this->name; this->name = new char[strlen(t.name) + 1]; strcpy(this->name, t.name);
            delete[] this->registration; this->registration = new char[strlen(t.registration) + 1]; strcpy(this->registration, t.registration);
        }
    }

    Truck& operator = (const Truck& t) {
        if (this != &t) {
            this->num = t.num;
            delete[] this->name; this->name = new char[strlen(t.name) + 1]; strcpy(this->name, t.name);
            delete[] this->registration; this->registration = new char[strlen(t.registration) + 1]; strcpy(this->registration, t.registration);
        } return *this;
    }

    ~Truck() { if (this->ptr_arr != nullptr) { delete[] this->ptr_arr; this->ptr_arr = nullptr; } }

    inline void push_back(Mass* element) {
        Mass** tmp = new Mass * [this->num + 1];
        for (int i = 0; i < this->num; i++) { tmp[i] = this->ptr_arr[i]; }
        tmp[this->num++] = element; delete[] this->ptr_arr; this->ptr_arr = new Mass * [this->num]; this->ptr_arr = tmp;
    }

    inline Truck send(char* registration, char* name) {
        Truck tmp(registration, name); int pos = 0; double _max = 0.00;
        for (int i = 0; i < this->num; i++) { if (this->ptr_arr[i]->getMass() > _max) { _max = this->ptr_arr[i]->getMass(); pos = i; } }
        for (int i = 0; i < this->num; i++) { if (i != pos) { tmp.push_back(this->ptr_arr[i]); } }
        return tmp;
    }

    inline double getTotalMass() { double sum = 0.00; for (int i = 0; i < this->num; i++) { sum += this->ptr_arr[i]->getMass(); } return sum; }

    inline void print() {
        std::cout << "Kamion so registracija " << this->registration << " i vozac " << this->name << " prenesuva: " << std::endl;
        for (int i = 0; i < this->num; i++) { this->ptr_arr[i]->print(); }
    }

    inline void _register(char* registration) { this->registration = registration; }
};

int main() {
    char name[20], registration[9]; double volume, percent; int quantity; bool fizzy;

    std::cin >> registration >> name;

    try {
        if ((isalpha(registration[0])) && (isalpha(registration[strlen(registration) - 1]))
            && (isalpha(registration[1])) && (isalpha(registration[strlen(registration) - 2]) && (strlen(registration) == REG_SIZE))) {

            Truck A(registration, name); Mass** d = new Mass * [5];

            std::cin >> volume >> quantity >> fizzy;
            d[0] = new Juices(volume, quantity, fizzy);

            std::cin >> volume >> quantity >> percent;
            d[1] = new Wines(volume, quantity, percent);

            std::cin >> volume >> quantity >> percent;
            d[2] = new Wines(volume, quantity, percent);

            std::cin >> volume >> quantity >> fizzy;
            d[3] = new Juices(volume, quantity, fizzy);

            std::cin >> volume >> quantity >> percent;
            d[4] = new Wines(volume, quantity, percent);

            A.push_back(d[0]); A.push_back(d[1]); A.push_back(d[2]); A.push_back(d[3]); A.push_back(d[4]);
            A.print(); std::cout << "Vkupna masa: " << A.getTotalMass() << std::endl;

            std::cin >> registration >> name;
            try {
                if ((isalpha(registration[0])) && (isalpha(registration[strlen(registration) - 1]))
                    && (isalpha(registration[1])) && (isalpha(registration[strlen(registration) - 2]) && (strlen(registration) == REG_SIZE))) {

                    Truck B = A.send(registration, name);
                    B.print(); std::cout << "Vkupna masa: " << B.getTotalMass() << std::endl;
                }
                else { throw(404); }
            }

            catch (int error_code) { std::cout << "Pogresno vnesena registracija" << std::endl; }
        }

        else { throw(404); }
    }

    catch (int error_code) { std::cout << "Pogresno vnesena registracija" << std::endl; }

    return 0;
}


