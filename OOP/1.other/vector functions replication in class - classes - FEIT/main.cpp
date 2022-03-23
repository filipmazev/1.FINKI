#include <iostream>
#define MAX 1024

struct stack
{
    int *arr=nullptr, num;

    stack init(){ this->num=0; this->arr = new int[this->num]; }

    void push(int element)
    {
        if(!isFull()){
        int *tmp = new int[this->num+1];
        for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
        tmp[this->num++]=element; delete[] this->arr; this->arr = tmp; }
        else { std::cout<<std::endl<<"ERROR 01 | the stack is full"<<std::endl; }
    }

    void pop()
    {
        if(!isEmpty()){
        int *tmp = new int[--this->num];
        for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
        delete[] this->arr; this->arr = tmp; }
        else { std::cout<<std::endl<<"ERROR 02 | the stack is empty"<<std::endl; }
    }

    int size(){ return num; }
    int peek(){ return this->arr[num]; }
    bool isEmpty(){ return (num==0); }
    bool isFull(){ return (num == MAX); }
    void print(){ for(int i=0; i<this->num; i++){ std::cout<<this->arr[i]; } }
};

void func(stack &s)
{
    stack tmp; tmp.init();
    for(int i=0; i<s.size(); i++)
    { int sum = s.arr[i] + s.arr[s.size()-i-1]; sum=sum>9?9:sum; tmp.push(sum); }
    s = tmp;
}

int main()
{
    stack s; int no, element; s.init();
    std::cout<<"Enter a number: "; std::cin>>no;

    while(no!=0){ element = no%10; no/=10; s.push(element); }
    func(s); s.print(); return 0;
}
