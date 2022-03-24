#include <iostream>
#include <cstring>

class IceCream
{
private:
    char *name, ingr[100]; float price; int discount=0;
public:
    IceCream(){ name = nullptr; discount=0; }
    IceCream(char *name, char *ingr, float price){
    this->name = new char[strlen(name)+1]; strcpy(this->name,name); strcpy(this->ingr,ingr); this->price=price; }

    IceCream(const IceCream &o){
    this->name = new char[strlen(o.name)+1]; strcpy(this->name,o.name); strcpy(this->ingr,o.ingr); this->price=o.price; this->discount=o.discount; }

    ~IceCream(){ delete[] name; }

    IceCream &operator = (const IceCream &add){
    this->name = new char[strlen(add.name)+1]; strcpy(this->name,add.name);
    strcpy(this->ingr,add.ingr); this->price = add.price; this->discount = add.discount; return *this; }

    IceCream &operator ++ (){ this->discount += 5; return *this; }

    friend std::ostream &operator << (std::ostream &output, const IceCream &ic)
    {
        output<<ic.name<<": "<<ic.ingr<<" "<<ic.price<<" ";
        if (ic.discount > 0){  output<<"("<<ic.price*(100 - ic.discount)/100<<")"; }
        return output;
    }

    IceCream operator + (const char *extra)
    {
        char *newName = new char[strlen(this->name)+strlen(extra)+3];
        strcat(newName, this->name); strcat(newName, " + "); strcat(newName, extra);
        IceCream ic(newName, this->ingr, this->price+10); ic.setDiscount(discount); return ic;
    }

    int setDiscount(int discount){ this->discount=discount; }
    void setName(char *name){ this->name = new char[strlen(name)+1]; strcpy(this->name,name); }
};

class IceCreamShop
{
private:
    char name[50]; IceCream *arr; int num;
public:
    IceCreamShop(){ this->num=0; this->arr=nullptr; }
    IceCreamShop(char* name){ this->arr=new IceCream[this->num]; this->arr = new IceCream[this->num]; strcpy(this->name, name); }

    IceCreamShop(const IceCreamShop &ics) {
    strcpy(this->name, ics.name); this->num = ics.num; this->arr = new IceCream[num];
    for (int i=0; i<this->num; i++){ this->arr[i] = ics.arr[i]; } }

    ~IceCreamShop(){ delete [] arr; }

    IceCreamShop &operator = (const IceCreamShop &ics)
    {
        if (this == &ics) { return *this; } delete [] arr;
        strcpy(this->name, ics.name); this->num = ics.num; this->arr = new IceCream[num];
        for (int i=0; i<this->num; i++){ this->arr[i] = ics.arr[i]; } return *this;
    }

    IceCreamShop &operator += (IceCream &ic)
    {
        IceCream *tmp = arr; arr = new IceCream[this->num+1];
        for (int i=0; i<this->num; i++) { arr[i] = tmp[i]; }
        arr[this->num] = ic; ++this->num; delete [] tmp; return *this;
    }

    friend std::ostream &operator << (std::ostream &out, const IceCreamShop &ics){
    std::cout<<ics.name<<std::endl; for (int i=0; i<ics.num; i++) { out << ics.arr[i] <<std::endl; } return out; }

};

int main()
{
    char name[100], ingr[100]; float price; int discount, testCase; std::cin>>testCase; std::cin.get();

    if(testCase == 1)
    {
        std::cout<<"====== TESTING IceCream CLASS ======"<<std::endl;
        std::cin.getline(name,100); std::cin.getline(ingr,100); std::cin>>price>>discount;

        std::cout<<"CONSTRUCTOR"<<std::endl;
        IceCream ic1(name, ingr, price); ic1.setDiscount(discount);

        std::cin.get(); std::cin.getline(name,100); std::cin.getline(ingr,100); std::cin>>price>>discount;
        IceCream ic2(name, ingr, price); ic2.setDiscount(discount);

        std::cout<<"OPERATOR <<"<<std::endl;
        std::cout<<ic1<<std::endl<<ic2<<std::endl;

        std::cout<<"OPERATOR ++"<<std::endl;
        ++ic1; std::cout<<ic1<<std::endl;

        std::cout<<"OPERATOR +"<<std::endl;
        IceCream ic3 = ic2 + "chocolate"; std::cout<<ic3<<std::endl;
    }

    else if(testCase == 2)
    {
        std::cout<<"====== TESTING IceCream CONSTRUCTORS ======"<<std::endl;
        std::cin.getline(name,100); std::cin.getline(ingr,100); std::cin>>price;

        std::cout<<"CONSTRUCTOR"<<std::endl;
        IceCream ic1(name, ingr, price);
        std::cout<<ic1<<std::endl;

        std::cout<<"COPY CONSTRUCTOR" << std::endl;
        IceCream ic2(ic1); std::cin.get(); std::cin.getline(name,100); ic2.setName(name);
        std::cout<<ic1<<std::endl<< ic2<<std::endl;

        std::cout<<"OPERATOR ="<<std::endl;
        ic1 = ic2; std::cin.getline(name,100); ic2.setName(name);
        std::cout<<ic1<<std::endl<<ic2<<std::endl;

        std::cin>>discount; ic1.setDiscount(discount);
    }

    else if(testCase == 3)
    {
        std::cout<<"====== TESTING IceCreamShop ======"<<std::endl;
        char icsName[50]; std::cin.getline(icsName,100);

        std::cout<<"CONSTRUCTOR"<<std::endl;
        IceCreamShop ics(icsName); int n; std::cin>>n;

        std::cout<<"OPERATOR +="<<std::endl;

        for(int i=0; i<n; i++)
        {
            std::cin.get(); std::cin.getline(name,100); std::cin.getline(ingr,100);  std::cin>>price;
            IceCream ic(name, ingr, price); ics += ic;
        }

        std::cout<<ics;
    }

    else if(testCase == 4)
    {
        std::cout<<"====== TESTING IceCreamShop CONSTRUCTORS ======"<<std::endl;
        char icsName[50]; std::cin.getline(icsName,100);
        IceCreamShop ics(icsName); int n; std::cin>>n;

        for(int i=0; i<n; i++)
        {
            std::cin.get(); std::cin.getline(name,100); std::cin.getline(ingr,100); std::cin >> price;
            IceCream ic(name, ingr, price); ics += ic;
        }

        IceCream x("FINKI fruits", "strawberry ice cream, raspberry ice cream, blueberry ice cream", 60);
        IceCreamShop icp = ics; ics+=x;
        std::cout<<ics<<std::endl<<icp<<std::endl;
    }

    return 0;
}
