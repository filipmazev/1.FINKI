#include <iostream>
#include <vector>

class List
{
private:
    std::vector<int> num_list;
    int elements;
public:
    List() = default; List(std::vector<int> n_l, int e){ elements = e; num_list = n_l; } ~List(){};

    int sum(){ int summation=0; for(int i=0; i<num_list.size(); i++){ summation+=num_list[i]; } return summation; }

    double average(){ return float(sum()) / num_list.size(); }

    void print()
    {
        std::cout<<"List info: "<<num_list.size()<<": ";
        for(int i=0; i<num_list.size(); i++){ std::cout<<num_list[i]<<" "; }
        std::cout<<"sum: "<<sum()<<" average: "<<average()<<std::endl;
    }

    int getNum(){ return num_list.size(); }
};

class ListContainer
{
private:
    std::vector<List> arr;
    int tries=0;
public:
    ListContainer() = default; ~ListContainer(){}; void print();

    void addNewList(List l)
    {
        bool checker=true; tries++;
        for(int i=0; i<arr.size(); i++){ if(l.sum() == arr[i].sum()){ checker=false; break; } }
        if(checker==true){ arr.push_back(l); }
    }

    int sum(){ int summary=0; for(int i=0; i<arr.size(); i++){ summary+=arr[i].sum(); } return summary; }

    double average(){ double avg=0.00; int total=0; for(int i=0; i<arr.size();i++){ total+=arr[i].getNum(); avg+=arr[i].sum(); } return avg/total; }
};

void ListContainer::print()
{
    int cnt_s=0; if(arr.empty()){ std::cout<<"The list is empty"<<std::endl; return; }
    else { for(int i=0; i<arr.size(); i++){ std::cout<<"List number: "<<i+1<<" "; arr[i].print(); cnt_s++; }
    int temp_error=404; std::cout<<"Sum: "<<sum()<<" Average: "<<average()<<std::endl<<"Successful attempts: "<<cnt_s<<" Failed attempts: "<<tries-cnt_s<<std::endl; }
}

int main()
{
	ListContainer lc; int N; std::cin>>N;

	for (int i=0;i<N;i++)
    {
		int n, num; std::vector<int> niza; std::cin>>n;
		for (int j=0;j<n;j++){ std::cin>>num; niza.push_back(num); }
		List l=List(niza,niza.size());
		lc.addNewList(l);
	}

    int testCase; std::cin>>testCase;

    if (testCase==1)
    {
        std::cout<<"Test case for operator ="<<std::endl;
        ListContainer lc1;
        lc1.print();
        std::cout<<lc1.sum()<<" "<<lc.sum()<<std::endl;
        lc1=lc;
        lc1.print();
        std::cout<<lc1.sum()<<" "<<lc.sum()<<std::endl;
    }

    else { lc.print(); } return 0;
}
