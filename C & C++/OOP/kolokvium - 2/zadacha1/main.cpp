#include <iostream>
#include <string.h>
using namespace std;

constexpr auto default_increase = 5;
constexpr auto default_discount = 10;

class Sneakers
{
private:
    char model[50]; int size; float price;
public:
    Sneakers(const char *model = "", int size = 38, float price = 1000) : size(size), price(price)
    {
        strncpy(this->model, model, 49);
        this -> model[49] = 0;
    }

    friend istream &operator>>(istream &in, Sneakers &s)
    {
        return in >> s.model >> s.size >> s.price;
    }

    friend ostream &operator<<(ostream &out, const Sneakers &s)
    {
        return out << "Model: " << s.model << " Size: " << s.size << " Price: " << s.price;
    }

    Sneakers &operator+=(float increment)
    {
        price += increment;
        return *this;
    }

    Sneakers &operator*=(float coefficient)
    {
        price *= coefficient;
        return *this;
    }

    bool operator==(Sneakers &s)
    {
        return strcmp(this->model, s.model) == 0 && this->size == s.size;
    }

    char *getModel()
    {
        return model;
    }

    int getSize() const
    {
        return size;
    }

    void setSize(int size)
    {
        this->size = size;
    }

    float getPrice() const
    {
        return price;
    }

    void setPrice(float price)
    {
        this->price = price;
    }
};

class SneakersShop{
protected:
    char name[50]; Sneakers* arr{nullptr}; int num{0}, price_increase {default_increase};
public:
    SneakersShop(){}
    SneakersShop(char* name){ strcpy(this->name, name); }

    ~SneakersShop(){
        if(this->arr != nullptr){ delete[] this->arr; this->arr = nullptr; }
    }

    SneakersShop& operator += (Sneakers ss){
        Sneakers* tmp = new Sneakers [this->num+1];
        for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
        tmp[this->num++] = ss;
        delete[] this->arr; this->arr = new Sneakers[this->num]; this->arr = tmp;
        return *this;
    }

    float checkItemAvailability(char* model, int size){
        for(int i=0; i<this->num; i++){
            if( strcmp(this->arr[i].getModel(), model) == 0 && this->arr[i].getSize() == size){ return this->arr[i].getPrice(); }
        }
        return 0;
    }

    int operator ++ (int increase){
        this->price_increase = increase;
        for(int i=0; i<this->num; i++){
            this->arr[i].setPrice( this->arr[i].getPrice() + increase );
        }
    }

    friend std::ostream& operator << (std::ostream& out, const SneakersShop& obj){
        out<<"Sneakers shop: "<<obj.name<<endl<<"List of sneakers:"<<endl;
        if(obj.num == 0){ cout<<"EMPTY"<<endl; }
        else{
            for(int i=0; i<obj.num; i++){
                std::cout<<i+1<<". Model: "<<obj.arr[i].getModel()<<" Size: "<<obj.arr[i].getSize()<<" Price: "<<obj.arr[i].getPrice()<<endl;
            }
        }
        return out;
    }
};

class OnlineSneakersShop : public SneakersShop{
protected:
    char url[100]; int discount{default_discount};
public:
    OnlineSneakersShop(){}
    OnlineSneakersShop(char* name, char* url) : SneakersShop(name){
        strcpy(this->url, url);
    }

    float checkItemAvailability(char* model, int size){
        return SneakersShop::checkItemAvailability(model, size);
    }

    ~OnlineSneakersShop(){}

    friend std::ostream& operator << (std::ostream& out, const OnlineSneakersShop& obj){
        out<<"Online sneakers shop: "<<obj.name<<" URL: "<<obj.url<<endl<<"List of sneakers:"<<endl;
        if(obj.num == 0){ cout<<"EMPTY"<<endl; }
        else{
            for(int i=0; i<obj.num; i++){
                std::cout<<i+1<<". Model: "<<obj.arr[i].getModel()<<" Size: "<<obj.arr[i].getSize()<<" Price: "<<obj.arr[i].getPrice()<<endl;
            }
        }
        return out;
    }
};

void printShop(SneakersShop *shop)
{
    OnlineSneakersShop *casted = dynamic_cast<OnlineSneakersShop *>(shop);
    if (casted)
    {
        cout << (*casted);
    }
    else
    {
        cout << (*shop);
    }
}

int main()
{
    int testCase; cin >> testCase; char name[100]; char url[100];

    if (testCase == 1)
    {
        cout << "TESTING CLASS SneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
    }

    else if (testCase == 2)
    {
        cout << "TESTING CLASS OnlineSneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
    }

    else if (testCase == 3)
    {
        cout << "TESTING CLASS SneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    }

    else if (testCase == 4)
    {
        cout << "TESTING CLASS OnlineSneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    }

    else if (testCase == 5)
    {
        cout << "TESTING METHOD checkItemAvailability" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0)
        {
            shop = new SneakersShop(name);
        }
        else
        {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        char model[100];
        int size;
        cin >> model >> size;
        cout << "Price for model " << model << " with size: " << size << " is: "
             << shop->checkItemAvailability(model, size) << endl;
    }

    else if (testCase == 6)
    {
        cout << "TESTING OPERATOR ++" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0)
        {
            shop = new SneakersShop(name);
        }
        else
        {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);
    }

    else if (testCase == 7)
    {
        cout << "TESTING OPERATOR ++ AND CHANGE OF STATIC MEMBER" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0)
        {
            shop = new SneakersShop(name);
        }
        else
        {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

        cout <<"CHANGING INCREASE PERCENTAGE IN SneakersShop" << endl;
        SneakersShop::setIncreasePercentage(17);

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

    }

    return 0;
}
