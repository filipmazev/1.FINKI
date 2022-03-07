#include <iostream>
#include <cstring>
using namespace std;

class Guitar
{
private:
    char serial[25], type[40]; double buy_price; int manufacturing_year;
public:
    Guitar(char *type="",char * serial ="",int manufacturing_year=0,double buy_price =0){
    strcpy(this->type,type); strcpy(this->serial,serial);
    this->manufacturing_year = manufacturing_year; this->buy_price = buy_price; }

    Guitar(const Guitar &g)
    {
        strcpy(this->type,g.type); strcpy(this->serial,g.serial);
        this->manufacturing_year = g.manufacturing_year; this->buy_price = g.buy_price;
    }

    Guitar & operator=(const Guitar &g)
    {
        strcpy(this->type,g.type); strcpy(this->serial,g.serial);
        this->manufacturing_year = g.manufacturing_year; this->buy_price = g.buy_price;
        return *this;
    }

    ~Guitar(){}

    bool is_equal(Guitar &g){ return strcmp(this->serial,g.serial)==0; }

    void pecati(){ cout<<serial<<" "<<type<<" "<<buy_price<<endl; }

    double getBuy_Price(){ return buy_price; }
    char *getType(){ return type; } char *getSerial(){ return serial; }
    int getYear(){ return manufacturing_year; }
};

class Warehouse
{
private:
    char location[60], name[50];
    int opening_year, num;
    Guitar *arr;
public:
    Warehouse(char * name="", char * location="", int opening_year=0){
        strcpy(this->location,location); strcpy(this->name,name);
        this->opening_year = opening_year; arr = NULL; num = 0; }

    Warehouse(const Warehouse &w)
    {
        strcpy(this->location,w.location); strcpy(this->name,w.name);
        this->opening_year = w.opening_year; arr = new Guitar[w.num];
        for(int i =0;i<w.num;i++){ arr[i] = w.arr[i]; }
        num = w.num;
    }

    Warehouse & operator=(const Warehouse &w)
    {
        delete [] arr; strcpy(this->location,w.location); strcpy(this->name,w.name); this->opening_year = w.opening_year;

        arr = new Guitar[w.num];
        for(int i =0;i<w.num;i++){ arr[i] = w.arr[i]; }
        num = w.num; return *this;
    }

    ~Warehouse(){delete [] arr;}

    double values(){ double sum=0; for(int i=0;i<num;i++){ sum+=arr[i].getBuy_Price(); } return sum; }

    void add(Guitar & g)
    {
        Guitar * tmp = new Guitar[num +1];
        for(int i=0;i<num;i++) { tmp[i] = arr[i]; } tmp[num++]=g;
        delete [] arr; arr=tmp;
    }

    void sell(Guitar & g)
    {
        int cnt=0, j=0;
        for(int i=0;i<num;i++){ if(arr[i].is_equal(g)==false) { cnt++; } }
        Guitar *tmp = new Guitar[cnt];
        for(int i=0;i<num;i++) { if(arr[i].is_equal(g)==false){ tmp[j] = arr[i]; j++; }}

        delete [] arr; arr = tmp; num = cnt;
    }

    void print(bool is_new)
    {
        cout<<name<<" "<<location<<endl;
        for(int i=0;i<num;i++){
            if(is_new==true&&arr[i].getYear()>opening_year){ arr[i].pecati(); }
            else if(is_new==false){ arr[i].pecati(); } }
    }
};

int main()
{
    int testCase, n, year; float price; char serial[50],type[50]; cin>>testCase;

	if(testCase == 1)
    {
        cout<<"===== Testiranje na klasata Gitara ======"<<endl;
        cin>>type>>serial>>year>>price; Guitar g(type,serial,year,price);
		cout<<g.getType()<<endl<<g.getSerial()<<endl<<g.getYear()<<endl<<g.getBuy_Price()<<endl;
    }

    else if(testCase == 2)
    {
        cout<<"===== Testiranje na klasata Magacin so metodot print() ======"<<endl;
		Warehouse wh("Magacin1","Lokacija1");
        wh.print(false);
	}

    else if(testCase == 3)
    {
        cout<<"===== Testiranje na klasata Magacin so metodot dodadi() ======"<<endl;
        Warehouse wh("Magacin1","Lokacija1",2005); cin>>n;

			for (int i=0;i<n;i++){
                cin>>type>>serial>>year>>price; Guitar g(type,serial,year,price);
                cout<<"gitara dodadi"<<endl; wh.add(g); }

        wh.print(true);
    }

    else if(testCase == 4)
    {
        cout<<"===== Testiranje na klasata Magacin so metodot prodadi() ======"<<endl;
        Warehouse wh("Magacin1","Lokacija1",2012); cin>>n; Guitar del;

			for (int i=0;i<n;i++){
                cin>>type>>serial>>year>>price; Guitar g(type,serial,year,price);
                if(i==2) { del=g; } cout<<"gitara dodadi"<<endl; wh.add(g); }

        wh.print(false); wh.sell(del); wh.print(false);
    }

    else if(testCase == 5)
    {
        cout<<"===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======"<<endl;
        Warehouse wh("Magacin1","Lokacija1",2011); cin>>n; Guitar del;

			for (int i=0;i<n;i++){
                cin>>type>>serial>>year>>price; Guitar g(type,serial,year,price);
                if(i==2) { del=g; } cout<<"gitara dodadi"<<endl; wh.add(g); }

        wh.print(true); wh.sell(del); cout<<"Po brisenje:"<<endl; Warehouse wh2; wh2=wh; wh2.print(true);
    }

    else if(testCase == 6)
    {
        cout<<"===== Testiranje na klasata Magacin so metodot vrednost()======"<<endl;
        Warehouse wh("Magacin1","Lokacija1",2011); cin>>n; Guitar del;

        for (int i=0;i<n;i++){ cin>>type>>serial>>year>>price; Guitar g(type,serial,year,price); if(i==2) { del=g; } wh.add(g); }

        cout<<wh.values()<<endl; wh.sell(del);
        cout<<"Po brisenje:"<<endl<<wh.values(); Warehouse wh2; wh2=wh;
    }

    return 0;
}
