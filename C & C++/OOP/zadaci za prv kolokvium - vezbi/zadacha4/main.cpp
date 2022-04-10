#include <iostream>
#include <cstring>

class Passanger
{
private:
    char name[100]; int train_class; bool bike;
public:
    Passanger(){}; Passanger(char n[100], int t_c, bool b){ strcpy(name,n); train_class = t_c; bike = b; } ~Passanger(){};

    char *getName() { return name; }
    int getTrain_Class()const { return train_class; }
    bool getBike()const { return bike; }

    Passanger &operator = (const Passanger &other){
        strcpy(name,other.name); train_class = other.train_class; bike = other.bike; }

    friend std::ostream &operator << (std::ostream &output, Passanger &other){
        output<<other.name<<std::endl<<other.train_class<<std::endl<<other.bike<<std::endl;
        return output<<std::endl; }
};

class Train
{
private:
    char end_destination[100]; Passanger *arr; int num=0, allowed_bikes, org, cnt_1=0, cnt_2=0;
public:
    Train(){ arr = nullptr; }; Train(char e_d[100], int a_b){ strcpy(end_destination,e_d); allowed_bikes = a_b; org = a_b; arr = new Passanger[3]; } ~Train(){};

    Train &operator += (Passanger &adder){ arr[num++] = adder; }

    friend std::ostream &operator << (std::ostream &output, Train &other)
    {
        int class_mod=1; bool diff=false; output<<other.end_destination<<std::endl;

        if(other.org != 0){ for(int i=0; i<other.num; i++){
        other.arr[i].getBike()?(other.arr[i].getTrain_Class()==class_mod?(--other.allowed_bikes<0?(class_mod==1?other.cnt_1++:other.cnt_2++):0),0:0),0:0;
        if(i==(other.num-1) && !diff){ i=0; diff=true; class_mod=2; } } }

        for(int i=0; i<other.num; i++){ if((!other.org?(other.arr[i].getBike()?0:1):1)) output<<other.arr[i]; }

        return output;
    }

    void print_info(){
    std::cout<<"Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<<cnt_1<<std::endl;
    std::cout<<"Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "<<cnt_2<<std::endl; }
};

int main()
{
	Passanger p; char name[100], destination[100]; bool bike; int n, train_class, max_bikes;
	std::cin>>destination>>max_bikes>>n; Train t(destination, max_bikes);

	for (int i=0; i<n; i++)
    {
		std::cin>>name>>train_class>>bike;
		Passanger p(name, train_class, bike);
		t += p;
	}

	std::cout<<t; t.print_info(); return 0;
}
