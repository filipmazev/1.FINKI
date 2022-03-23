#include <iostream>
#define MAX 20

struct _stack
{
    int *arr=nullptr, num;

    _stack init(){ this->num=0; this->arr = new int[this->num]; }

    void push(int element)
    {
        int *tmp = new int[this->num+1];
        for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
        tmp[this->num++]=element; delete[] this->arr; this->arr = tmp;
    }

    void pop()
    {
        int *tmp = new int[--this->num];
        for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
        delete[] this->arr; this->arr = tmp;
    }

    _stack &operator = (_stack &adder)
    {
        delete[] this->arr; this->arr = new int[adder.size()];
        for(int i=0; i<adder.size(); i++){ this->arr[i] = adder.arr[i]; }
        return *this;
    }

    int size(){ return num; }
    int peek(){ return this->arr[num]; }
    bool isEmpty(){ return (num==0); }
    bool isFull(){ return (num == MAX); }
    void print(){ for(int i=0; i<this->num; i++){ std::cout<<this->arr[i]; } }
};

void func(_stack &s)
{
    _stack tmp; tmp.init(); int sum=0;
    for(int i=0; i<s.size(); i++){ sum = s.arr[i] + s.arr[s.size()-i-1]; sum>9?9:sum; tmp.push(sum); }
    s = tmp;
}

int main()
{
    _stack s; int no, element, e; s.init();
    std::cout<<"Vnesete koj broj da se proveri:"; std::cin>>no;

    while(no!=0){ element = no%10; no/=10; s.push(element); }
    func(s); s.print(); return 0;
}
