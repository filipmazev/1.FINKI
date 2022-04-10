#include <iostream>
#include <string.h>
#define MAX 5

enum genre {action, comedy, drama};

class Film
{
private:
    char *name{nullptr}; int mem{0}; genre genre_type{(genre)0};
public:
    Film(){ this->name = nullptr; }
    Film(char *name, int mem, genre genre_type):Film(){ this->name = new char[strlen(name)+1]; strcpy(this->name,name); this->mem=mem; this->genre_type=genre_type; }

    Film(const Film &f){ if(this != &f){
    this->name = new char[strlen(f.name)+1]; strcpy(this->name,f.name);
    this->mem=f.mem; this->genre_type=f.genre_type; } }

    Film &operator = (const Film &f){ if(this != &f){
    delete[] this->name; this->name = new char[strlen(f.name)+1]; strcpy(this->name,f.name);
    this->mem=f.mem; this->genre_type=f.genre_type; } return *this; }

    ~Film(){ delete[] this->name; this->name = nullptr; }

    genre getGenre(){ return this->genre_type; } int getMem(){ return this->mem; }

    void print(){ std::cout<<this->mem<<"MB-\""<<this->name<<"\""<<std::endl; }
};

class DVD
{
private:
    Film *arr{nullptr}; int num{0}, dvd_mem{0};
public:
    DVD(){ this->arr=nullptr; this->num=0; this->dvd_mem=0; }

    DVD(int dvd_mem):DVD(){ this->dvd_mem=dvd_mem; }

    DVD(const DVD &d){ if(this != &d){ this->num = d.num; this->dvd_mem=d.dvd_mem;
    delete[] this->arr; this->arr = new Film[this->num]; for(int i=0; i<this->num; i++){ this->arr[i] = d.arr[i]; } } }

    DVD &operator = (const DVD &d){ if(this != &d){ this->num = d.num; this->dvd_mem=d.dvd_mem;
    delete[] this->arr; this->arr = new Film[this->num]; for(int i=0; i<this->num; i++){ this->arr[i] = d.arr[i]; } } return *this; }

    ~DVD(){ delete[] this->arr; this->arr=nullptr; }

    Film getFilm(int i){ return this->arr[i]; } int getNum(){ return num; }

    void add(Film &adder){ int total_mem=0; for(int i=0; i<this->num; i++){ total_mem+=arr[i].getMem(); }
    if((total_mem+adder.getMem()) <= dvd_mem && num < MAX) { Film *tmp = new Film[this->num+1]; for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
    tmp[num++] = adder; delete[] this->arr; this->arr = tmp; } }

    void print_diff_genre(genre genre_cmp){
    for(int i=0; i<this->num; i++){ if(this->arr[i].getGenre()!=genre_cmp){ arr[i].print(); } } }

    double genre_mem(genre genre_cmp){ double total=0, sum=0;
    for(int i=0; i<this->num; i++){ total+=arr[i].getMem(); sum+=genre_cmp==arr[i].getGenre()?arr[i].getMem():0; } return sum/total * 100; }
};

int main()
{
    int testCase, n, mem, genre_type; char name[50]; std::cin>>testCase;

    if (testCase == 1)
    {
        std::cout<<"===== Testiranje na klasata Film ======"<<std::endl; std::cin>>name>>mem>>genre_type;
        Film f(name, mem, (genre)genre_type); f.print();
    }

    else if (testCase == 2)
    {
        std::cout<<"===== Testiranje na klasata DVD ======"<<std::endl; DVD favorite(50); std::cin>>n;
        for (int i=0; i<n; i++){ std::cin>>name>>mem>>genre_type; Film f(name, mem, (genre)genre_type); favorite.add(f); }
        for (int i=0; i<n; i++){ (favorite.getFilm(i)).print(); }
    }

    else if (testCase == 3)
    {
        std::cout<<"===== Testiranje na metodot dodadiFilm() od klasata DVD ======"<<std::endl; DVD favorite(50); std::cin>>n;
        for (int i=0; i<n; i++){ std::cin>>name>>mem>>genre_type; Film f(name, mem, (genre)genre_type); favorite.add(f); }
        for (int i=0; i<favorite.getNum(); i++){ (favorite.getFilm(i)).print(); }
    }

    else if (testCase == 4)
    {
        std::cout<<"===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======"<<std::endl; DVD favorite(50); std::cin>>n;
        for (int i=0; i<n; i++){ std::cin>>name>>mem>>genre_type; Film f(name, mem, (genre) genre_type); favorite.add(f); }
        std::cin>>genre_type; favorite.print_diff_genre((genre) genre_type);
    }

    else if (testCase == 5)
    {
        std::cout<<"===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======"<<std::endl; DVD favorite(50); std::cin>>n;
        for (int i=0; i<n; i++){ std::cin>>name>>mem>>genre_type; Film f(name, mem, (genre) genre_type); favorite.add(f); }
        std::cin>>genre_type; favorite.print_diff_genre((genre) genre_type);
    }

    else if (testCase == 6)
    {
		std::cout<<"===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD ====="<<std::endl; DVD favorite(40); std::cin >> n;
		for (int i = 0; i < n; i++){ std::cin>>name>>mem>>genre_type; Film f(name, mem, (genre) genre_type); favorite.add(f); }
        std::cin>>genre_type; std::cout<<"Procent na filmovi od dadeniot zanr iznesuva: "<<favorite.genre_mem((genre) genre_type)<<"%\n";
	}

    return 0;
}
