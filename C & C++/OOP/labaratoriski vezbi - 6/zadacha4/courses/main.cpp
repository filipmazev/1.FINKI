#include <iostream>
#include <string.h>

class real_estate
{
protected:
    std::string address; int surface_area{0}, price{0};
public:
    real_estate(){ this->surface_area = 0; this->price = 0; }

    real_estate(std::string address, int surface_area, int price){
        this->address = address;
        this->surface_area = surface_area; this->price = price;
    }

    real_estate(real_estate& r_e){
        if(this != &r_e){ this->address = r_e.address; this->surface_area = r_e.surface_area; this->price = r_e.price; }
    }

    real_estate &operator = (real_estate& r_e) noexcept {
        if(this != &r_e){ this->address = r_e.address; this->surface_area = r_e.surface_area; this->price = r_e.price; } return *this;
    }

    inline friend std::istream& operator >> (std::istream& input, real_estate& r_e) noexcept {
         input>>r_e.address>>r_e.surface_area>>r_e.price; return input;
    }

    void print(){ std::cout<<this->address<<", Kvadratura: "<<this->surface_area<<", Cena po Kvadrat: "<<this->price; }
    double tax(){ return (this->price*this->surface_area)*0.05; }
    std::string getAddress(){ return this->address; }

    ~real_estate(){}
};

class Vila : protected real_estate
{
private:
    int luxary_tax{0};
public:
    Vila() : real_estate(){ this->luxary_tax = 0; }
    Vila(int luxary_tax) : real_estate(){ this->luxary_tax = luxary_tax; }

    inline friend std::istream& operator >> (std::istream& input, Vila& v) noexcept { input>>v.address>>v.surface_area>>v.price>>v.luxary_tax; return input; }

    void print(){ real_estate::print(); std::cout<<", Danok na luksuz: "<<this->luxary_tax; }
    double tax(){ return real_estate::tax() + ((this->price*this->surface_area)*this->luxary_tax)/100; }
    std::string getAddress(){ return this->address; }

    ~Vila(){}
};

int main()
{
    real_estate property; Vila v;
    std::cin>>property>>v;
    property.print(); std::cout<<std::endl<<"Danok za: "<<property.getAddress()<<", e: "<<property.tax()<<std::endl;
    v.print(); std::cout<<std::endl<<"Danok za: "<<v.getAddress()<<", e: "<<v.tax()<<std::endl;
    return 0;
}
