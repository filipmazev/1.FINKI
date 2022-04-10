#include <iostream>
#include <cstring>

class Participant
{
private:
    char *name; bool gender; int age;
public:
    Participant(){ name = nullptr; };
    Participant(char *n, bool g, int a){ name = new char[(size_t)(strlen(n)+1)]; strcpy(name,n); gender = g, age = a; }
    ~Participant(){};

    Participant &operator > (const Participant &other){ age = this->age>other.age?this->age:other.age; return *this; }

    friend std::ostream &operator << (std::ostream &output, Participant &other){
    std::string gender_p = other.gender?"mashki":"zhenski"; output<<other.name<<std::endl<<gender_p<<std::endl<<other.age<<std::endl;
    return output; }

    int getAge(){ return age; }
};

class Marathon
{
private:
    char location[100]; Participant *arr; int num=0;
public:
    Marathon(){ arr = nullptr; }
    Marathon(char l[100]){ arr = new Participant[1024]; strcpy(location,l); }
    ~Marathon(){};

    Marathon &operator += (Participant &adder){ arr[num++] = adder; }
    float avg_age(); void print_younger(Participant &p);
};

float Marathon::avg_age(){ float avg=0; for(int i=0; i<num; i++) { avg+=arr[i].getAge(); } return avg/num; }

void Marathon::print_younger(Participant &p){ for(int i=0; i<num; i++) { if(arr[i].getAge()<p.getAge()) { std::cout<<arr[i]; } } }

int main()
{
    char ime[100], lokacija[100]; bool maski; int vozrast, n;
    std::cin>>n>>lokacija;

    Marathon m(lokacija);
    Participant **u = new Participant*[n];

    for(int i = 0; i < n; ++i)
    {
        std::cin>>ime>>maski>>vozrast;
    	u[i] = new Participant(ime, maski, vozrast);
        m += *u[i];
    }

	m.print_younger(*u[n - 1]);
    std::cout<<m.avg_age()<<std::endl;

    for(int i = 0; i < n; ++i) { delete u[i]; } delete [] u;
	return 0;
}
