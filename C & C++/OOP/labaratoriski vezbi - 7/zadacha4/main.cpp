#include <iostream>

class Vehicle
{
protected:
    double weight{ double() }; int width{ int() }, height{ int() };
public:
    Vehicle() {}
    Vehicle(double weight, int width, int height) { this->weight = weight; this->width = width; this->height = height; }
    Vehicle(const Vehicle& v) { if (this != &v) { this->weight = v.weight; this->width = v.width; this->height = v.height; } }
    void setWeight(double weight) { this->weight = weight; } double getWeight() noexcept { return this->weight; }
    void setHeight(int height) { this->height = height; } int getHeight() noexcept { return this->height; }
    void setWidth(int width) { this->width = width; } int getWidth() noexcept { return this->width; }
    virtual void setVar(int var) = 0; virtual int getVar() = 0;
    inline virtual int return_daily_price() = 0;
    ~Vehicle() {}
};

class Automobile : public Vehicle
{
private:
    int var{ int() };
public:
    Automobile() : Vehicle() {}
    Automobile(double weight, int width, int height, int var) : Vehicle(weight, width, height) { this->var = var; }
    Automobile(const Automobile& a) : Vehicle(a.weight, a.width, a.height) { if (this != &a) { this->var = a.var; } }
    void setVar(int var) { this->var = var; } int getVar() noexcept { return this->var; }
    inline int return_daily_price() noexcept { return var < 5 ? 100 : 130; }
    ~Automobile() {}
};

class Bus : public Vehicle
{
private:
    int var{ int() };
public:
    Bus() : Vehicle() {}
    Bus(double weight, int width, int height, int var) : Vehicle(weight, width, height) { this->var = var; }
    Bus(const Bus& b) : Vehicle(b.weight, b.width, b.height) { if (this != &b) { this->var = b.var; } }
    void setVar(int var) { this->var = var; } int getVar() noexcept { return this->var; }
    inline int return_daily_price() noexcept { return var * 5; }
    ~Bus() {}
};

class Truck : public Vehicle
{
private:
    double var{ double() };
public:
    Truck() : Vehicle() {}
    Truck(double weight, int width, int height, int var) : Vehicle(weight, width, height) { this->var = var; }
    Truck(const Truck& t) : Vehicle(t.weight, t.width, t.height) { if (this != &t) { this->var = t.var; } }
    void setVar(int var) { this->var = var; } int getVar() noexcept { return this->var; }
    inline int return_daily_price() noexcept { return (weight + var) * 0.02; }
    ~Truck() {}
};

class Parking_Lot
{
private:
    Vehicle** ptr_arr{ nullptr }; int num{ 0 };
public:
    Parking_Lot() {}

    inline Parking_Lot& operator += (Vehicle* v) noexcept {
        Vehicle** tmp = new Vehicle * [this->num + 1];
        for (unsigned int i = 0; i < this->num; i++) { tmp[i] = ptr_arr[i]; }
        tmp[this->num++] = v; delete[] this->ptr_arr; this->ptr_arr = new Vehicle * [this->num]; this->ptr_arr = tmp;
        return *this;
    }

    inline double calc_total_weight() noexcept {
        double sum = 0.00;
        for (unsigned int i = 0; i < this->num; i++) {
            sum += ptr_arr[i]->getWeight();
        }
        return sum;
    }

    inline int vehicles_wider_than(int val) noexcept {
        int cnt = 0;
        for (unsigned int i = 0; i < this->num; i++) {
            cnt += ptr_arr[i]->getWidth() > val ? 1 : 0;
        }
        return cnt;
    }

    inline int bigger_capacity_than(Vehicle& v) noexcept {
        int cnt = 0;
        for (unsigned int i = 0; i < this->num; i++) {
            if (dynamic_cast<Truck*>(ptr_arr[i]) != NULL) { cnt += ptr_arr[i]->getVar() > v.getWeight() ? 1 : 0; }
        }
        return cnt;
    }

    inline int return_daily_income() noexcept { int total = 0; for (unsigned int i = 0; i < this->num; i++) { total += ptr_arr[i]->return_daily_price(); } return total; }

    inline void print() {
        int cnt_automobiles = 0, cnt_buses = 0, cnt_trucks = 0;

        for (unsigned int i = 0; i < this->num; i++) {
            cnt_automobiles += dynamic_cast<Automobile*>(ptr_arr[i]) != NULL ? 1 : 0;
            cnt_buses += dynamic_cast<Bus*>(ptr_arr[i]) != NULL ? 1 : 0;
            cnt_trucks += dynamic_cast<Truck*>(ptr_arr[i]) != NULL ? 1 : 0;
        }

        std::cout << "Brojot na avtomobili e " << cnt_automobiles << ", brojot na avtobusi e " << cnt_buses << " i brojot na kamioni e " << cnt_trucks << "." << std::endl;
    }

    ~Parking_Lot() { delete[] this->ptr_arr; this->ptr_arr = nullptr; }
};

int main()
{
    Parking_Lot parking; int n, width, height, var; double weight, max_weight; std::cin >> n;

    for (unsigned int i = 0; i < n; i++) {
        int type; std::cin >> type;

        if (type == 1) {
            std::cin >> weight >> width >> height >> var;
            Automobile* a = new Automobile(weight, width, height, var);
            parking += a;
        }

        if (type == 2) {
            std::cin >> weight >> width >> height >> var;
            parking += new Bus(weight, width, height, var);
        }

        if (type == 3) {
            std::cin >> weight >> width >> height >> var;
            parking += new Truck(weight, width, height, var);
        }
    }

    parking.print();

    std::cout << "\nZarabotkata e " << parking.return_daily_income() << std::endl;
    std::cout << "Vkupnata masa e " << parking.calc_total_weight() << std::endl;
    std::cout << "Brojot poshiroki od 5 e " << parking.vehicles_wider_than(5) << std::endl; Automobile a(1200, 4, 3, 5);
    std::cout << "Brojot na kamioni so nosivost pogolema od avtomobilot e " << parking.bigger_capacity_than(a) << std::endl;
}
