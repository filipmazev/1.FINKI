#include <iostream>
#include <string.h>
#define REG_LENGHT 5

class Automobile
{
private:
    char* brand{ nullptr }; int* registry{ nullptr }, max_speed{ 0 };
public:
    Automobile() { this->brand = nullptr; this->registry = nullptr; this->max_speed = 0; }

    Automobile(char* brand, int* registry, int max_speed) {
        this->max_speed = max_speed; this->brand = new char[strlen(brand) + 1]; this->registry = new int[REG_LENGHT];
        strcpy_s(this->brand, strlen(brand) + 1, brand); for (int i = 0; i < REG_LENGHT; i++) { this->registry[i] = registry[i]; }
    }

    Automobile(const Automobile& a) {
        if (this != &a) {
            delete[] this->brand; delete[] this->registry;
            this->brand = new char[strlen(a.brand) + 1]; this->registry = new int[REG_LENGHT];
            strcpy_s(this->brand, strlen(a.brand) + 1, a.brand); for (int i = 0; i < REG_LENGHT; i++) { this->registry[i] = a.registry[i]; } this->max_speed = a.max_speed;
        }
    }

    inline Automobile& operator = (const Automobile& a) {
        if (this != &a) {
            delete[] this->brand; delete[] this->registry;
            this->brand = new char[strlen(a.brand) + 1]; this->registry = new int[REG_LENGHT];
            strcpy_s(this->brand, strlen(a.brand) + 1, a.brand); for (int i = 0; i < REG_LENGHT; i++) { this->registry[i] = a.registry[i]; } this->max_speed = a.max_speed;
        }
        return *this;
    }

    inline friend bool operator == (const Automobile& curr, const Automobile& comp) noexcept
    {
        for (size_t i = 0; i < REG_LENGHT; i++) { if (curr.registry[i] == comp.registry[i]) { return false; } }
        return ((strcmp(curr.brand, comp.brand) == 0) && curr.max_speed != comp.max_speed);
    }

    inline friend std::ostream& operator << (std::ostream& out, const Automobile& a)
    {
        out << "Marka\t" << a.brand << "\tRegistracija[ "; for (size_t i = 0; i < REG_LENGHT; i++) { out << a.registry[i] << " "; } out << "] ";
        return out;
    }

    int getSpeed() { return this->max_speed; }

    ~Automobile() { delete[] this->brand; this->brand = nullptr; delete[] this->registry; this->registry = nullptr; }
};

class RentACar
{
private:
    char* name{ nullptr }; Automobile* arr{ nullptr }; int num{ 0 };
public:
    RentACar() { this->name = nullptr; this->arr = nullptr; this->num = 0; }

    RentACar(char* name) { this->name = new char[strlen(name) + 1]; strcpy_s(this->name, strlen(name) + 1, name); }

    RentACar(const RentACar& r) {
        if (this != &r) {
            delete[] this->name; this->name = new char[strlen(r.name) + 1];
            delete[] this->arr; this->arr = new Automobile[r.num];
            this->num = r.num; this->name = r.name; for (size_t i = 0; i < r.num; i++) { this->arr[i] = r.arr[i]; }
        }
    }

    inline RentACar& operator = (const RentACar& r) {
        if (this != &r) {
            delete[] this->name; this->name = new char[strlen(r.name) + 1];
            delete[] this->arr; this->arr = new Automobile[r.num];
            this->num = r.num; this->name = r.name; for (size_t i = 0; i < r.num; i++) { this->arr[i] = r.arr[i]; }
        }
        return *this;
    }

    inline RentACar& operator += (const Automobile a) {
        Automobile* tmp = new Automobile[this->num + 1];
        for (size_t i = 0; i < this->num; i++) { tmp[i] = this->arr[i]; }
        tmp[this->num++] = a; delete[] this->arr; this->arr = new Automobile[this->num]; this->arr = tmp;
        return *this;
    }

    inline RentACar& operator -= (const Automobile a) {
        for (size_t i = 0; i < this->num; i++) {
            if (this->arr[i] == a) {
                --this->num; for (size_t j = i; j < this->num; j++) { this->arr[j] = this->arr[j + 1]; }
            }
        } return *this;
    }

    void printAboveSpeed(int speed) {
        for (size_t i = 0; i < this->num; i++)
        {
            if (this->arr[i].getSpeed() > speed) { std::cout << this->name << std::endl << this->arr[i] << std::endl; }
        }
    };

    ~RentACar() { delete[] this->arr; this->arr = nullptr; delete[] this->name; this->name = nullptr; }
};

int main()
{
    char* name = new char[10]; strcpy_s(name, strlen("FINKI-Car") + 1, "FINKI-Car"); RentACar agencija(name);
    int n; std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        char marka[100]; int regisracija[5], maximumBrzina; std::cin >> marka;

        for (int i = 0; i < 5; i++) { std::cin >> regisracija[i]; } std::cin >> maximumBrzina;

        Automobile nov = Automobile(marka, regisracija, maximumBrzina);

        agencija += nov;
    }

    char marka[100]; int regisracija[5], maximumBrzina; std::cin >> marka;

    for (int i = 0; i < 5; i++) { std::cin >> regisracija[i]; } std::cin >> maximumBrzina;

    Automobile greshka = Automobile(marka, regisracija, maximumBrzina);

    agencija -= greshka;

    agencija.printAboveSpeed(150);

    return 0;
}

