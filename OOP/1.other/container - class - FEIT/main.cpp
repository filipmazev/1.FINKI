#include <iostream>
#define MAX 3

class vector
{
private:
    int *arr=nullptr; int num; size_t mem;
public:
    vector(){ mem=MAX; num=-1; arr = new int[mem]; }
    ~vector(){ if(arr!=nullptr){ arr=nullptr; delete[] arr; } }

    vector operator = (vector &other){
    while(!empty()){ pop_back(); } this->arr = new int[other.size()+1];
    for(unsigned int i=0; i<other.size()+1; i++){ push_back(other.arr[i]); } }

    friend std::ostream &operator << (std::ostream &output, vector &other){
    for(unsigned int i=0; i<other.size()+1; i++){ output<<other.arr[i]; } return output; }

    void push_back(int elemenet){ if(++num>=mem){ mem*=2; int *tmp = (int*)realloc(arr, mem*sizeof(int)); arr=tmp; tmp=nullptr; delete[] tmp; } *(arr+num)=elemenet; }
    void pop_back(){ if(!empty()){ num--; } else { throw std::bad_alloc{}; } }
    size_t size(){ return (size_t)num; }
    bool empty(){ return (num==-1); }
    int back(){ return arr[num]; }
    int front(){ return arr[0]; }
};

int fn(vector &s)
{
    vector tmp_1, tmp_2; tmp_1 = s;
    while(!s.empty()){ tmp_2.push_back(s.back()); s.pop_back(); }
    while(!tmp_1.empty() || !tmp_2.empty()){ s.push_back(tmp_1.back()+tmp_2.back()); tmp_1.pop_back(); tmp_2.pop_back(); }
}

int main()
{
    vector int_stack; int number; std::cin>>number;
    while(number){ int_stack.push_back(number%10); number/=10; }
    fn(int_stack); std::cout<<int_stack; return 0;
}
