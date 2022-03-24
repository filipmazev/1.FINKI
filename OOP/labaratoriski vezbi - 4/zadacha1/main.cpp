#include <iostream>

class List
{
private:
    int *arr, num;
public:
    List(){ arr=nullptr; num=0; }
    List(int *arr, int num){ this->num=num; this->arr = new int[num]; for(int i=0; i<num; i++){ this->arr=arr; } }
    List(const List &other){ this->num=other.num; this->arr = new int[num]; for(int i=0; i<num; i++){ this->arr[i]=other.arr[i]; } }
    List &operator = (const List &other){ this->num=other.num; this->arr = new int[num]; for(int i=0; i<num; i++){ this->arr[i]=other.arr[i]; } return *this; }
    ~List(){ if(this->arr!=nullptr){ this->arr = nullptr; delete[] arr; } }

    int sum(){ int summery=0; for(int i=0; i<this->num; i++){ summery+=this->arr[i]; } return summery; }
    double average(){ return sum()/(double)this->num; }
    int getNum(){ return num; }

    void print(){ std::cout<<"List info: "<<this->num<<": "; for(int i=0; i<this->num; i++){ std::cout<<this->arr[i]<<" "; } std::cout<<"sum: "<<sum()<<" average: "<<average()<<std::endl; }
};

class ListContainer
{
private:
    List *l_arr; int num, failed;
public:
    ListContainer(){ this->num=0; this->failed=0; this->l_arr = nullptr; }
    ListContainer(List *l_arr, int num){ this->num=num; this->l_arr = new List[this->num]; for(int i=0; i<num; i++){ this->l_arr[i] = l_arr[i]; } }
    ListContainer(const ListContainer &other){ this->num=other.num; this->l_arr=new List[num]; for(int i=0; i<num; i++){ this->l_arr[i] = other.l_arr[i]; } this->failed=other.failed; }
    ListContainer &operator = (const ListContainer &other){ this->num=other.num; this->l_arr=new List[num]; for(int i=0; i<num; i++){ this->l_arr[i] = other.l_arr[i]; } this->failed=other.failed; return *this; }
    ~ListContainer(){ if(this->l_arr!=nullptr){ this->l_arr = nullptr; delete[] l_arr; } }

    void addNewList(List &l)
    {
        List *tmp = new List[num+1];
        for(int i=0; i<num; i++){ if(l.sum() == this->l_arr[i].sum()){ failed++; return; } tmp[i] = this->l_arr[i]; }
        tmp[num++] = l; delete[] this->l_arr; this->l_arr = tmp;
    }

    int sum(){ int summary=0; for(int i=0; i<this->num; i++){ summary+=this->l_arr[i].sum(); } return summary; }
    double average(){ double avg=0.00; int total=0; for(int i=0; i<this->num; i++){ total+=this->l_arr[i].getNum(); avg+=this->l_arr[i].sum(); } return avg/total; }

    void print()
    {
        if(!this->num){ std::cout<<"The list is empty"<<std::endl; return; }
        else { for(int i=0; i<this->num; i++){ std::cout<<"List number: "<<i+1<<" "; this->l_arr[i].print(); }
        std::cout<<"Sum: "<<sum()<<" Average: "<<average()<<std::endl<<"Successful attempts: "<<this->num<<" Failed attempts: "<<this->failed<<std::endl; }
    }
};

int main()
{
	ListContainer lc; int N; std::cin>>N;
	for (int i=0;i<N;i++){ int n, arr[100]; std::cin>>n; for (int j=0;j<n;j++){ std::cin>>arr[j]; } List l = List(arr,n); lc.addNewList(l); } int testCase; std::cin>>testCase;

    if (testCase==1)
    {
        std::cout<<"Test case for operator ="<<std::endl;
        ListContainer lc1; lc1.print(); std::cout<<lc1.sum()<<" "<<lc.sum()<<std::endl;
        lc1=lc; lc1.print(); std::cout<<lc1.sum()<<" "<<lc.sum()<<std::endl; lc1.sum(); lc1.average();
    }

    else { lc.print(); } return 0;
}
