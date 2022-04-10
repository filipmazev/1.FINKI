#include<iostream>
#include<cstring>

class Person
{
private:
    char *name, *lastname;
public:
    Person(){ name = nullptr; lastname = nullptr; }
    Person(char *name, char *lastname){
    this->name = new char[strlen(name)+1]; this->lastname = new char[strlen(lastname)+1];
    strcpy(this->name,name); strcpy(this->lastname,lastname); }
    ~Person(){}

    void print(){ std::cout<<this->name<<" "<<this->lastname<<std::endl; }
};

class Date
{
private:
    int year, month, day;
public:
    Date(){}
    Date(int year, int month, int day){
    this->year = year; this->month = month; this->day = day; }
    Date(const Date &d){ this->year = d.year; this->month = d.month; this->day = d.day; }
    ~Date(){}

    void print(){ std::cout<<this->year<<"."<<this->month<<"."<<this->day<<std::endl; }
};

class Car
{
private:
    Person owner; Date date; float price=0;
public:
    Car(){ this->price=0; }
    Car(Person owner, Date date, float price){
    this->owner = owner; this->date = date; this->price = price; }
    ~Car(){}

    float getPrice(){ return this->price; }
    void print(){ this->owner.print(); this->date.print(); std::cout<<"Price: "<<this->price<<std::endl; }
};

void cheaperThan(Car *cars, int numCars, float price){
for(int i=0; i<numCars; i++){ if (cars[i].getPrice() < price){ cars[i].print(); } } }

int main()
{
 	char name[20], lastName[20]; float price, priceLimit; int year, month, day, testCase, numCars; std::cin>>testCase;

	if (testCase == 1)
    {
		std::cin>>name>>lastName>>year>>month>>day>>price;
		Person lik(name, lastName); Date date(year, month, day); Car car(lik, date,  price); car.print();
	}

	else if (testCase == 2)
    {
		std::cin>>name>>lastName>>year>>month>>day>>price;
		Person lik(name, lastName); Date date(Date(year, month, day)); Car car(lik, date,  price); car.print();
    }

	else
    {
		std::cin>>numCars; Car cars[numCars];

		for (int i = 0; i < numCars; i++)
        {
            std::cin>>name>>lastName>>year>>month>>day>>price;
			Person lik(name, lastName); Date date(year, month, day); cars[i] = Car(lik, date,  price);
		}

        std::cin>>priceLimit; cheaperThan(cars, numCars, priceLimit);
	}

	return 0;
}
