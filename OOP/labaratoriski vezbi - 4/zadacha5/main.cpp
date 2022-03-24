#include <iostream>
#include <cstring>

class Pizza
{
private:
    char pizza_name[15], *ingredients; int price, discount;
public:
    Pizza(){ ingredients = nullptr; }

    Pizza(char n[15], int p, char *i, int d){
    strcpy(pizza_name,n); ingredients = new char[(size_t)(strlen(i)+1)]; strcpy(ingredients,i);
    price = p; discount = d; }

    Pizza(const Pizza &p){ strcpy(pizza_name,p.pizza_name); price=p.price; discount=p.discount;
    ingredients = new char[(size_t)(strlen(p.ingredients)+1)]; strcpy(ingredients,p.ingredients); }

    ~Pizza(){ delete[] ingredients; };

    Pizza &operator = (Pizza &p){
    if(this != &p){ strcpy(pizza_name, p.pizza_name); price=p.price; discount=p.discount;
    delete[]ingredients; ingredients = new char[(size_t)(strlen(p.ingredients)+1)]; strcpy(ingredients,p.ingredients); } return *this; }

    void print(){ std::cout<<pizza_name<<" - "<<ingredients<<", "<<price; }
    bool is_equal(Pizza p){ return (!strcmp(ingredients,p.ingredients)); }

    int getPrice(){ return price; } int getDiscount(){ return discount; }
};

class Pizzeria
{
private:
    char name[15]; Pizza *arr; int num;
public:
    Pizzeria(const char *na){ strcpy(name,na); arr=nullptr; num=0; }

    Pizzeria(char *na, Pizza *a, int n){ strcpy(name,na);; num=n;
    arr = new Pizza[n]; for(int i=0; i<n; i++){ arr[i] = a[i]; } }

    Pizzeria(const Pizzeria &p){ strcpy(name,p.name); num=p.num; arr = new Pizza[num];
    for(int i=0; i<num; i++){ arr[i] = p.arr[i]; } }

    Pizzeria &operator = (const Pizzeria &p){
    if(this != &p){ strcpy(name,p.name); num = p.num; delete[] arr; arr = new Pizza[num];
    for(int i=0; i<num; i++){ arr[i] = p.arr[i]; } } return *this; }

    ~Pizzeria(){ delete[] arr; }

    Pizzeria &operator += (Pizza &adder){
    bool isEqual = false; for(int i=0; i<num; i++){ if(arr[i].is_equal(adder)){ isEqual=true; break; } }
    if(!isEqual){ Pizza *tmp = new Pizza[num+1]; for(int i=0; i<num; i++){ tmp[i] = arr[i]; }
    tmp[num++] = adder; delete[]arr; arr=tmp; } return *this; }

    const char*getName(){ return name; } void setName(const char *n){ strcpy(name,n); }

    void print_w_discount(){
    for (int i=0; i <num; i++){
        if (arr[i].getDiscount() != 0){ arr[i].print();
        std::cout<<" "<<arr[i].getPrice()*(1-arr[i].getDiscount()/100.0)<<std::endl; } } }
};

int main()
{
	int n; char name[15]; std::cin>>name>>n; Pizzeria p1(name);

	for (int i = 0; i < n; i++)
    {
		char pizza_name[100], ingredients[100]; int price, discount;
		std::cin.get(); std::cin.getline(pizza_name, 100); std::cin>>price;
		std::cin.get(); std::cin.getline(ingredients, 100); std::cin>>discount;

		Pizza p(pizza_name, price, ingredients, discount); p1+=p;
	}

	Pizzeria p2 = p1; char pizza_name[100], ingredients[100]; int price, discount;

	std::cin>>name; p2.setName(name);
	std::cin.get(); std::cin.getline(pizza_name, 100); std::cin>>price;
	std::cin.get(); std::cin.getline(ingredients, 100); std::cin>>discount;

	Pizza p(pizza_name, price, ingredients, discount); p2+=p;

	std::cout<<p1.getName()<<std::endl<<"Pici na promocija:"<<std::endl; p1.print_w_discount();
	std::cout<<p2.getName()<<std::endl<<"Pici na promocija:"<<std::endl; p2.print_w_discount(); return 0;
}

