#include <iostream>
#include <vector>
using namespace std;

class List
{
private:
    vector<int> num_list;
    int elements;
public:
    List() = default; List(vector<int> n_l, int e){ elements = e; num_list = n_l; } ~List(){};

    int sum(){ int summation=0; for(int i=0; i<num_list.size(); i++){ summation+=num_list[i]; } return summation; }

    double average(){ return float(sum()) / num_list.size(); }

    void print()
    {
        cout<<"List info: "<<num_list.size()<<": ";
        for(int i=0; i<num_list.size(); i++){ cout<<num_list[i]<<" "; }
        cout<<"sum: "<<sum()<<" average: "<<average()<<endl;
    }

    int getNum(){ return num_list.size(); }
};

class ListContainer
{
private:
    vector<List> arr;
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
    int cnt_s=0; if(arr.empty()){ cout<<"The list is empty"<<endl; return; }
    else { for(int i=0; i<arr.size(); i++){ cout<<"List number: "<<i+1<<" "; arr[i].print(); cnt_s++; }
    int temp_error=404; cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl<<"Successful attempts: "<<cnt_s<<" Failed attempts: "<<tries-cnt_s<<endl; }
}

int main()
{
	ListContainer lc; int N; cin>>N;

	for (int i=0;i<N;i++)
    {
		int n, num; vector<int> niza; cin>>n;
		for (int j=0;j<n;j++){ cin>>num; niza.push_back(num); }
		List l=List(niza,niza.size());
		lc.addNewList(l);
	}

    int testCase; cin>>testCase;

    if (testCase==1)
    {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
    }

    else { lc.print(); } return 0;
}
