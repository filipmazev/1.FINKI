#include <iostream>

class vector
{
private:
    int *arr{nullptr}; int num{0};
public:
    vector(){ this->num=0; this->arr = nullptr; }
    ~vector(){ delete[] this->arr; this->arr=nullptr; }

    vector(const vector &other){ if(this != &other){ this->num = other.num;
    this->arr; this->arr = new int[this->num]; for(int i=0; i<this->num; i++){ this->arr[i] = other.arr[i]; } } }

    vector &operator = (vector &other){ if(this != &other){ this->num = other.num;
    delete[] this->arr; this->arr = new int[this->num]; for(int i=0; i<this->num; i++){ this->arr[i] = other.arr[i]; } } return *this; }

    int &operator[](int index){ return this->arr[index]; }

    friend std::ostream &operator << (std::ostream &output, vector &other){
    for(unsigned int i=0; i<other.size(); i++){ output<<other.arr[i]; } return output; }

    void push_back(int element){
    int *tmp = new int[this->num+1]; for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
    tmp[num++] = element; delete[] this->arr; this->arr = tmp; }

    void pop_back(){
    if(!empty()){ int *tmp = new int[--this->num]; for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
    delete[] this->arr; this->arr = tmp; } else{ throw std::bad_alloc{}; } }

    void erase(int pos){ if(pos<this->num){
    for(int i=0; i<this->num; i++){ if(i==pos){ --this->num;
    for(int j=i; j<this->num; j++){ this->arr[j] = this->arr[j+1]; } break; } } } }

    size_t size(){ return (size_t)this->num; }
    bool empty(){ return (this->num==0); }
    int back(){ return this->arr[this->num-1]; }
    int front(){ return this->arr[0]; }
};

int fn(vector &prim)
{
    vector tmp_1, tmp_2; tmp_1 = prim;
    while(!prim.empty()){ tmp_2.push_back(prim.back()); prim.pop_back(); }
    while(!tmp_1.empty() || !tmp_2.empty()){ prim.push_back(tmp_1.back()+tmp_2.back()); tmp_1.pop_back(); tmp_2.pop_back(); }
}

int main()
{
    vector int_stack; int number; std::cin>>number;

    while(number){ int_stack.push_back(number%10); number/=10; }
    fn(int_stack); std::cout<<int_stack<<std::endl; return 0;
}
