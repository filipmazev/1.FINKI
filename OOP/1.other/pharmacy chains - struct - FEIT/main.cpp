#include <iostream>
#include <cstring>

using namespace std;

struct Pharmacy
{
    string location; int n_employees; bool sunday;

    void setter(string l, int n_e, bool s)
    {
        location = l; n_employees = n_e; sunday = s;
    }

    void print()
    {
        cout<<"Lokacija: "<<location<<endl<<"Broj na vraboteni: "<<n_employees<<endl;
        cout<<"Aptekata "; if(!sunday){ cout<<"ne "; } cout<<"raboti vo nedela"<<endl;
    }
};

struct Chain
{
    string name; int num; Pharmacy arr[10];

    void setter(string na, int n, Pharmacy a[10])
    {
        name=na; num=n; for(int i=0; i<n; i++){ arr[i] = a[i]; }
    }

    void print()
    {
        cout<<"Ime: "<<name<<", broj na farmacii: "<<num<<endl;
        for(int i=0; i<num; i++){ arr[i].print(); }
    }

    friend ostream &operator << (ostream &out, Chain &adder)
    {
        for(int i=0; i<adder.num; i++)
        {
            if(adder.arr[i].sunday == true)
            {
                out<<"Ime: "<<adder.name<<", broj na farmacii: "<<adder.num<<endl; adder.arr[i].print();
            }
        }
        return out;
    }
};

void print_largest(Chain *p, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Najgolemata "<<p[i].name<<" apteka e: "<<endl;
        for(int j=0; j<p[i].num; j++)
        {
            bool diff=true;

            for(int k=0; k<p[i].num-j-1; k++)
            {
                int compare_1 = p[i].arr[k].sunday?p[i].arr[k].n_employees:5;
                int compare_2 = p[i].arr[k+1].sunday?p[i].arr[k+1].n_employees:5;
                if(compare_1 < compare_2){ diff = false; break; }
            }

            if(diff==true){ p[i].arr[j].print(); cout<<endl; }
        }
    }
}

int main()
{
    int n; cout<<"Vnesi broj na lanci na apteki: "; cin>>n; Chain *arr; arr = new Chain[n];

    for(int i=0; i<n; i++)
    {
        cout<<"VNES NA LANEC "<<i+1<<endl;
        string name; int num;
        cout<<"Vnesi ime na lanec: "; cin>>name;
        cout<<"Vnesi broj na apteki: "; cin>>num;
        Pharmacy *p; p = new Pharmacy[num];

        for(int j=0; j<num; j++)
        {
            string location; int n_employees; bool sunday;
            cout<<"Lokacija na aptekata "<<j+1<<": "; cin>>location;
            cout<<"Broj na vraboteni: "; cin>>n_employees;
            cout<<"Dali aptekata vraboti vo nedela? 1/0: "; cin>>sunday;
            p[j].setter(location, n_employees, sunday);
        }

        arr[i].setter(name, num, p);
        delete[] p;
    }

    cout<<endl<<"SITE APTEKI OD SITE LANCI:"<<endl<<endl; for(int i=0; i<n; i++){ arr[i].print(); cout<<endl; }
    cout<<"APTEKI KOI RABOTAT VO NEDELA:"<<endl; for(int i=0; i<n; i++){ cout<<arr[i]; } cout<<endl;
    cout<<"NAJGOLEMA APTEKA PO LANEC:"<<endl; print_largest(arr,n);

    return 0;
}
