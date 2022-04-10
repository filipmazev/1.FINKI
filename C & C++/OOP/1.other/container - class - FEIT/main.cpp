#include <iostream>
#define MAX 10

struct stack
{
    int *arr=nullptr; int num; size_t size;

    stack init(){ size=MAX; num=-1; arr = (int*)calloc(size, sizeof(int)); }

    void push(int elemenet){ if(++num>=size){ size*=2; int *tmp = (int*)realloc(arr, size * sizeof(int)); arr=tmp; }  *(arr+num)=elemenet; }

    void pop(){ if(!isEmpty()){ num--; } else { std::cout<<std::endl<<"ERROR_LOG: the stack is empty"<<std::endl; } }

    int peek(){ return arr[num]; }
    bool isEmpty(){ return (num==-1); }
    void print(){ for(int i=0; i<num+1; i++){ std::cout<<arr[i]; } }
};

int fn(stack &s)
{
    stack tmp_1=s, tmp_2; tmp_2.init();

    while(!s.isEmpty()){ tmp_2.push(s.peek()); s.pop(); } s.init();
    while(!tmp_1.isEmpty() || !tmp_2.isEmpty()){ s.push(tmp_1.peek()+tmp_2.peek()); tmp_1.pop(); tmp_2.pop(); }
}

int main()
{
    stack s; int no, element; s.init(); std::cin>>no;
    while(no!=0){ element = no%10; no/=10; s.push(element); }
    fn(s); s.print(); return 0;
}
