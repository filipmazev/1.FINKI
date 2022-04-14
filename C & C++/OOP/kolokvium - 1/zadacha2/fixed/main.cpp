#include <iostream>
#include <string.h>

class Flight
{
private:
    char city_start[50], city_end[50];
    float lenght, price;
public:
    Flight(){}
    Flight(char *city_start, char *city_end, float lenght, float price){
    strcpy(this->city_start, city_start); strcpy(this->city_end, city_end);
    this->lenght = lenght; this->price = price; }

    Flight(const Flight &f){
    if(this != &f){ strcpy(this->city_start, f.city_start); strcpy(this->city_end, f.city_end);
    this->lenght = f.lenght; this->price = f.price; } }

    Flight &operator = (const Flight &f){
    if(this != &f){ strcpy(this->city_start, f.city_start); strcpy(this->city_end, f.city_end);
    this->lenght = f.lenght; this->price = f.price; } return *this; }

    ~Flight(){}

    char *getCityStart(){ return this->city_start; }
    char *getCityEnd(){ return this->city_end; }

    void printDuration(){ std::cout<<(int)this->lenght<<"h:"<<((this->lenght - (int)this->lenght)*60)<<"min"; }
    void printFlight(){ std::cout<<this->city_start<<" -> "; printDuration(); std::cout<<" -> "<<this->city_end<<": "<<this->price<<"EUR"; }
};

class Airline
{
private:
    char company_name[50]; Flight *arr{nullptr}; int num{0};
public:
    Airline(){ this->arr=nullptr; this->num=0; }

    Airline(char *company_name){ strcpy(this->company_name, company_name); }

    Airline(char *company_name, Flight *arr, int num){
    this->num = num; delete[] this->arr; this->arr = new Flight[num]; for(int i=0; i<num; i++){ this->arr[i] = arr[i]; }
    strcpy(this->company_name, company_name); }

    Airline(const Airline &a){ if(this != &a){ this->num = a.num;
    delete[] this->arr; this->arr = new Flight[a.num]; for(int i=0; i<a.num; i++){ this->arr[i] = a.arr[i]; }
    strcpy(this->company_name, a.company_name); } }

    Airline &operator = (const Airline &a){ if(this != &a){ this->num = num;
    delete[] this->arr; this->arr = new Flight[a.num]; for(int i=0; i<a.num; i++){ this->arr[i] = a.arr[i]; }
    strcpy(this->company_name, a.company_name); } return *this; }

    ~Airline(){ delete[] this->arr; this->arr = nullptr; }

    void addFlight(Flight f){
    bool same=false; for(int i=0; i<this->num; i++){ if(strcmp(this->arr[i].getCityStart(),f.getCityStart())==0 && strcmp(this->arr[i].getCityEnd(),f.getCityEnd())==0){ same=true; break; } }
    if(same==false) { Flight *tmp = new Flight[this->num+1]; for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
    tmp[this->num++] = f; delete[] this->arr; this->arr = new Flight[this->num]; this->arr = tmp; } }

    Flight* getFlights(){ return this->arr; }
    int getN(){ return this->num; }
};

void searchFlights(Airline a, char *departureCity, char *arrivalCity)
{
    bool check=false;

    for(int i=0; i<a.getN(); i++){
        if((strcmp(a.getFlights()[i].getCityStart(), departureCity)) == 0 && strcmp(a.getFlights()[i].getCityEnd(), arrivalCity) == 0){ a.getFlights()[i].printFlight(); return; } }

    for(int i=0; i<a.getN(); i++){
        for(int j=0; j<a.getN(); j++){
            if(i != j && (strcmp(a.getFlights()[i].getCityEnd(), a.getFlights()[j].getCityStart()) == 0 && strcmp(a.getFlights()[j].getCityEnd(), arrivalCity) == 0))
                { a.getFlights()[i].printFlight(); std::cout<<" 1 stop "; a.getFlights()[j].printFlight(); std::cout<<std::endl; check = true; break; } } }

    if(check==false) { std::cout<<"Nema konekcija pomegju baranite gradovi"; } return;
}

int main(){

    int testCase; std::cin>>testCase;

    if(testCase == 1)
    {
        std::cout<<"====Testing class Flight constructors and additional methods===="<<std::endl;
        Flight f1; char dep[50], arr[50]; double dur, pr; std::cin>>dep>>arr>>dur>>pr;

        Flight f2(dep, arr, dur, pr);
        std::cout<<f2.getCityStart()<<" "<<f2.getCityEnd()<<std::endl<<"Testing OK"<<std::endl;
    }

    else if(testCase == 2)
    {
        std::cout<<"====Testing class Flight methods printDuration() and printFlight()===="<<std::endl;
        char dep[50], arr[50]; double dur, pr; std::cin>>dep>>arr>>dur>>pr;
        Flight f2(dep, arr, dur, pr); f2.printFlight(); std::cout<<std::endl;
    }

    else if(testCase == 3)
    {
        std::cout<<"====Testing class Airplane constructors and methods===="<<std::endl;
        Airline a("Wizzair"); char dep[50], arr[50]; double dur, pr; std::cin>>dep>>arr>>dur>>pr;

        Flight f1(dep, arr, dur, pr); a.addFlight(f1);
        Flight f3 = f1; a.addFlight(f3); a.getFlights()[0].printFlight();
        std::cout<<std::endl<<a.getN()<<std::endl;

        Airline b = a; b.getFlights()[0].printFlight(); std::cout<<std::endl;
        std::cin>>dep>>arr>>dur>>pr; Flight f2(dep, arr, dur, pr); b.addFlight(f2); b.getFlights()[1].printFlight();
        std::cout<<std::endl<<"Testing OK"<<std::endl;
    }

    else if(testCase == 4)
    {
        std::cout<<"====Testing global function===="<<std::endl;
        Airline a("Wizzair"); char dep[50], arr[50]; double dur, pr; int n; std::cin>>n;
        for(int i = 0; i < n; i++){ std::cin>>dep>>arr>>dur>>pr; Flight f(dep, arr, dur, pr); a.addFlight(f); }

        std::cin>>dep>>arr; searchFlights(a, dep, arr);
        std::cout<<std::endl<<"Testing OK"<<std::endl;
    }

    return 0;
}
