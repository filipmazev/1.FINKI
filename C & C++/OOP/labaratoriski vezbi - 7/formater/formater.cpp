#include <iostream>
#include <string.h>

#define DEFAULT_SIZE 1024

class String_Instrument
{
protected:
    char* name{ nullptr }; int strings_cnt{ int() }; double price{ double() };
public:
    String_Instrument() {}

    String_Instrument(char* name, int strings_cnt, double price) {
        this->name = new char[strlen(name) + 1]; strcpy_s(this->name, strlen(name), name); //courses: strcpy(this->name, name);
        this->strings_cnt = strings_cnt; this->price = price;
    }

    String_Instrument(const String_Instrument& instrument) {
        if (this != &instrument) {
            this->name = new char[strlen(instrument.name) + 1];  strcpy_s(this->name, strlen(instrument.name), instrument.name); //courses: strcpy(this->name, instrument.name);
            this->strings_cnt = instrument.strings_cnt; this->price = instrument.price;
        }
    }

    inline friend bool operator == (String_Instrument& cmp1, String_Instrument& cmp2) noexcept { return cmp1.strings_cnt == cmp2.strings_cnt; }

    friend std::ostream& operator << (std::ostream& out, String_Instrument& instrument) { out << instrument.name << " " << instrument.strings_cnt << " " << instrument.price; return out << std::endl; }

    int getStrings_Cnt() { return this->strings_cnt; }

    inline virtual double instrument_price() = 0;

    ~String_Instrument() { if (this->name != nullptr) { delete[] this->name; this->name = nullptr; } }
};

class Mandolin : public String_Instrument
{
private:
    char* form{ nullptr };
public:
    Mandolin() : String_Instrument() {}

    Mandolin(char* name, int strings_cnt, double price, char* form) : String_Instrument(name, strings_cnt, price) {
        this->form = new char[strlen(form) + 1]; strcpy_s(this->form, strlen(form), form); //courses: strcpy(this->form, form);
    }

    Mandolin(const Mandolin& m) : String_Instrument(m.name, m.strings_cnt, m.price) {
        if (this != &m) { this->form = new char[strlen(m.form) + 1]; strcpy_s(this->form, strlen(m.form), m.form); } //courses: strcpy(this->form, m.form);
    }

    inline double instrument_price() noexcept { return strcmp(this->form, "Neapolitan") == 0 ? this->price + this->price * 0.15 : this->price; }

    ~Mandolin() { if (this->form != nullptr) { delete[] this->form; this->form = nullptr; } }
};

class Violin : public String_Instrument
{
private:
    double _size{ double() };
public:
    Violin() : String_Instrument() {}

    Violin(char* name, int strings_cnt, double price, double _size) : String_Instrument(name, strings_cnt, price) { this->_size = _size; }

    Violin(const Violin& v) : String_Instrument(v.name, v.strings_cnt, v.price) { if (this != &v) { this->_size = v._size; } }

    inline double instrument_price() noexcept { return this->price + (this->_size == 0.25 ? this->price * 0.10 : (this->_size == 1.00 ? this->price * 0.20 : 0)); }

    ~Violin() {}
};

void print_instruments(String_Instrument& instrument, String_Instrument** ptr_arr, int n) {
    for (unsigned int i = 0; i < n; i++) { *ptr_arr[i] == instrument ? (std::cout << ptr_arr[i]->instrument_price() << std::endl), 0 : 0; }
}

int main()
{
    char* name = new char[DEFAULT_SIZE], * form = new char[DEFAULT_SIZE]; int strings_cnt, n; double price;

    std::cin >> name >> strings_cnt >> price >> form; Mandolin m(name, strings_cnt, price, form); std::cin >> n;

    String_Instrument** ptr_arr = new String_Instrument * [2 * n];

    for (unsigned int i = 0; i < n; ++i) {
        std::cin >> name >> strings_cnt >> price >> form;
        ptr_arr[i] = new Mandolin(name, strings_cnt, price, form);
    }

    for (unsigned int i = 0; i < n; ++i) {
        double _size; std::cin >> name >> strings_cnt >> price >> _size;
        ptr_arr[n + i] = new Violin(name, strings_cnt, price, _size);
    }

    print_instruments(m, ptr_arr, 2 * n);

    for (unsigned int i = 0; i < 2 * n; ++i) { delete ptr_arr[i]; } delete[] ptr_arr; return 0;
}
