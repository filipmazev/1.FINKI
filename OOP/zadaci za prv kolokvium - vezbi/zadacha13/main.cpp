#include <iostream>
#include <string.h>

class Lift
{
private:
    char *location; int price;
public:
    Lift(){ this->location = nullptr; }
    Lift(char *location, int price){ this->location = new char[(size_t)(strlen(location))]; strcpy(this->location,location);
    this->price = price; }
    ~Lift(){ delete[] this->location; }

    char *getLocation(){ return this->location; } int getPrice(){ return this->price; }
    void setLocation(char *location){  this->location = new char[(size_t)(strlen(location))]; strcpy(this->location,location); }
    void setPrice(int price){ this->price=price; }
};

class Mountain_Lodge
{
private:
    char name[15], class_type; int price[2]; bool has_lift; Lift l;
public:
    Mountain_Lodge(){}
    Mountain_Lodge(char *name, int price[2], char class_type, bool has_lift){
    strcpy(this->name,name); this->class_type = class_type; for(int i=0;i<2;i++){ this->price[i]=price[i]; } this->has_lift=has_lift; }
    ~Mountain_Lodge(){}

    void setLift(Lift &l){ this->l.setLocation(l.getLocation()); this->l.setPrice(l.getPrice()); }

    Mountain_Lodge &operator = (Mountain_Lodge &ml){
    if(ml.has_lift){ this->l.setLocation(ml.l.getLocation()); this->l.setPrice(ml.l.getPrice()); }
    strcpy(this->name, ml.name); this->class_type = ml.class_type; for(int i=0;i<2;i++){ this->price[i]=ml.price[i]; } this->has_lift=ml.has_lift; return *this; }

    Mountain_Lodge &operator -- (){ if(isalpha(this->class_type)) { if((int)((char)((int)(toupper(this->class_type)) + 1)) <= (int)('F'))
    { this->class_type = (char)((int)(this->class_type) + 1); } } return *this; }

    int operator <= (char comp){ return ((int)toupper(this->class_type) >= (int)toupper(comp)); }

    friend std::ostream &operator << (std::ostream &out, Mountain_Lodge &other){
    out<<other.name<<" klasa:"<<other.class_type; if(other.has_lift){ out<<" so Zichara"; } return out<<std::endl; }

    void print(){ std::cout<<std::endl<<"A: "<<this->l.getLocation()<<" "<<this->l.getPrice(); }

    void calculate_price(int day, int month, int &total_price)
    { total_price = ((this->has_lift?this->l.getPrice():0) + (month>=4||(month <= 9 && day == 1)?price[0]:price[1])); }
};

int main()
{
    Mountain_Lodge m; char name_of_lodge[15], location_of_lift[30], class_type; int price[12], daily_lift_ticket; bool has_lift;
    std::cin>>name_of_lodge; for (int i=0;i<2;i++){ std::cin>>price[i]; } std::cin>>class_type>>has_lift;

    if (has_lift)
    {
        std::cin>>location_of_lift>>daily_lift_ticket;
        Mountain_Lodge ml(name_of_lodge,price,class_type,has_lift);
        Lift l(location_of_lift,daily_lift_ticket);
        ml.setLift(l); m=ml;
    }

    else { Mountain_Lodge *tmp=new Mountain_Lodge(name_of_lodge,price,class_type,has_lift); m=*tmp; }

    --m; --m; int total_price, day, month; std::cin>>day>>month;

    try
    {
        if (day > 31 || day <= 0 || month > 12 || month <= 0){ throw 404; }
        else { m.calculate_price(day,month,total_price);
        std::cout<<"Informacii za PlaninarskiDomot:"<<std::endl<<m;
        if (m<='D'){ std::cout<<"Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n"; }
        std::cout<<"Cenata za "<<day<<"."<<month<<" e "<<total_price; }
    }

    catch (int) { std::cout<<"Mesecot ili denot e greshno vnesen!"; return 0; }
}
