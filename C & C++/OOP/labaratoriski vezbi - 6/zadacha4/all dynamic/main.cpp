#include <iostream>
#include <stdio.h>
#include <string.h>

char *string();

class real_estate
{
protected:
    char* address{nullptr}; int surface_area{0}, price{0};
public:
    real_estate(){ this->address = nullptr; this->surface_area = 0; this->price = 0; }

    real_estate(char *address, int surface_area, int price){
        this->address = new char[strlen(address)+1]; strcpy(this->address, address);
        this->surface_area = surface_area; this->price = price;
    }

    real_estate(real_estate& r_e){
        if(this != &r_e){
            delete[] this->address; this->address = new char[strlen(r_e.address)+1]; strcpy(this->address, r_e.address);
            this->surface_area = r_e.surface_area; this->price = r_e.price;
        }
    }

    real_estate &operator = (real_estate& r_e) noexcept {
        if(this != &r_e){
            delete[] this->address; this->address = new char[strlen(r_e.address)+1]; strcpy(this->address, r_e.address);
            this->surface_area = r_e.surface_area; this->price = r_e.price;
        } return *this;
    }

    inline friend std::istream& operator >> (std::istream& input, real_estate& r_e) noexcept {
        r_e.address = string(); input>>r_e.surface_area>>r_e.price; return input;
    }

    void print(){ std::cout<<this->address<<", Kvadratura: "<<this->surface_area<<", Cena po Kvadrat: "<<this->price; }
    double tax(){ return (this->price*this->surface_area)*0.05; }
    char* getAddress(){ return this->address; }

    ~real_estate(){ delete[] this->address; this->address = nullptr; }
};

class Vila : protected real_estate
{
private:
    int luxary_tax{0};
public:
    Vila() : real_estate(){ this->luxary_tax = 0; }
    Vila(int luxary_tax) : real_estate(){ this->luxary_tax = luxary_tax; }

    inline friend std::istream& operator >> (std::istream& input, Vila& v) noexcept { v.address = string(); input>>v.surface_area>>v.price>>v.luxary_tax; return input; }

    void print(){ real_estate::print(); std::cout<<", Danok na luksuz: "<<this->luxary_tax; }
    double tax(){ return real_estate::tax() + ((this->price*this->surface_area)*this->luxary_tax)/100; }
    char* getAddress(){ real_estate::getAddress(); }

    ~Vila(){}
};

inline char *string() {
    char *str = (char*) calloc(sizeof(char*), 1); int cnt=0; fflush(stdin); char c=' ';
    while(c != '\n'){ scanf("%c", &c);
    if(c != '\n') { str[cnt] = c; str=(char*)realloc(str, ++cnt * sizeof(char*)); } else{ str[cnt] = NULL; } }
    return str;
}

int main()
{
    real_estate property; Vila v;
    std::cin>>property>>v;
    property.print(); std::cout<<std::endl<<"Danok za: "<<property.getAddress()<<", e: "<<property.tax()<<std::endl;
    v.print(); std::cout<<std::endl<<"Danok za: "<<v.getAddress()<<", e: "<<v.tax()<<std::endl;
    return 0;
}
