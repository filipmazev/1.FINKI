#include <iostream>
#include <cstring>

class Worker
{
private:
    char *name, *lastname; int salary;
public:
    Worker(){ this->name = nullptr; this->lastname = nullptr; }

    Worker(char *name, char *lastname, int salary){
    this->name=new char[strlen(name)+1]; this->lastname=new char[strlen(lastname)+1];
    strcpy(this->name,name); strcpy(this->lastname,lastname); this->salary=salary; }

    ~Worker(){}

    int getSalary(){ return this->salary; } void print(){ std::cout<<this->name<<" "<<this->lastname<<" "<<this->salary<<std::endl; }
};

class Factory
{
private:
    Worker *arr; int num;
public:
    Factory(){ this->arr=nullptr; this->num=0; }

    Worker &operator += (const Worker &adder){
    Worker *tmp = new Worker[this->num+1]; for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
    tmp[this->num++] = adder; delete[] this->arr; this->arr = tmp; }

    ~Factory(){ delete[] this->arr; }

    void print(){ for(int i=0; i<this->num; i++){ this->arr[i].print(); } }
    void print_above(int min_salary){ for(int i=0; i<this->num; i++){ if(this->arr[i].getSalary() > min_salary){ this->arr[i].print(); } } }
};

int main()
{
    int n, salary, min_salary; char name[1024], lastame[1024]; std::cin>>n; Factory f;

    for(int i=0; i<n; i++){ std::cin>>name>>lastame>>salary; Worker w(name,lastame,salary); f += w; }

    std::cout<<"Site vraboteni:"<<std::endl; std::cin>>min_salary; f.print();
    std::cout<<"Vraboteni so plata povisoka od "<<min_salary<<" :"<<std::endl; f.print_above(min_salary);

    return 0;
}
