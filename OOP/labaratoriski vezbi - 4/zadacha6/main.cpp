#include <iostream>
#include <cstring>

enum Type {LINUX, UNIX, WINDOWS};

class OperatingSystem
{
private:
    char *os_name; float os_version, os_size; Type os_type;
public:
    OperatingSystem(){ os_name = nullptr; }

    OperatingSystem(char *os_name, float os_version, Type os_type, float os_size){
    this->os_name = new char[strlen(os_name)+1]; strcpy(this->os_name,os_name);
    this->os_version = os_version; this->os_type = os_type; this->os_size = os_size; }

    OperatingSystem(const OperatingSystem &o){
    this->os_name = new char[strlen(o.os_name)+1]; strcpy(this->os_name,o.os_name);
    this->os_version = o.os_version; this->os_type = o.os_type; this->os_size = o.os_size; }

    OperatingSystem &operator = (const OperatingSystem &add){
    this->os_name = new char[strlen(add.os_name)+1]; strcpy(this->os_name,add.os_name);
    this->os_version = add.os_version; this->os_type = add.os_type; this->os_size = add.os_size; return *this; }

    ~OperatingSystem(){ delete[] os_name; }

    float get_os_version(){ return this->os_version; }

    void print(){ std::cout<<"Ime: "<<this->os_name<<" Verzija: "<<this->os_version<<" Tip: "<<this->os_type<<" Golemina:"<<this->os_size<<"GB"<<std::endl; }
    bool version_comp(const OperatingSystem &o){ return (this->os_version == o.os_version); }
    bool os_family_comp(const OperatingSystem &o){ return ((strcmp(this->os_name,o.os_name)==0) && this->os_type==o.os_type); }
    bool isEqual(const OperatingSystem &o){ return (version_comp(o) && os_family_comp(o) && this->os_size==o.os_size); }
};

class Repo
{
private:
    char *repo_name; OperatingSystem *arr; int num=0;
public:
    Repo(){ num=0; repo_name=nullptr; arr=nullptr; }
    Repo(char *repo_name){ this->repo_name=new char[strlen(repo_name)+1]; strcpy(this->repo_name,repo_name); arr = new OperatingSystem[this->num]; }
    ~Repo(){ delete[] repo_name; delete[] arr; }

    void push(OperatingSystem &adder)
    {
        OperatingSystem *tmp = new OperatingSystem[num+1]; bool flag=false;

        for(int i=0; i<this->num; i++)
        { tmp[i] = (this->arr[i].os_family_comp(adder) && arr[i].get_os_version() < adder.get_os_version())?(flag=true),adder:this->arr[i]; }
        if(flag==false){ tmp[num++] = adder; } delete[] this->arr; this->arr = tmp;
    }

    void rm(const OperatingSystem &rem){
        for(int i=0; i<this->num; i++){
            if(this->arr[i].isEqual(rem)){ --this->num;
                for(int j=i; j<this->num; j++){ this->arr[j] = this->arr[j+1]; } break; } } }

    void show(){ std::cout<<"Repozitorium: "<<this->repo_name<<std::endl; for(int i=0; i<this->num; i++){ this->arr[i].print(); } }
};

int main()
{
    char repo_name[20], os_name[20]; int os_amount, os_type; float os_version, os_size;
    std::cin>>repo_name>>os_amount; Repo git=Repo(repo_name);

    for (int i=0; i<os_amount; i++)
    {
        std::cin>>os_name>>os_version>>os_type>>os_size;
        OperatingSystem os = OperatingSystem(os_name, os_version, (Type)os_type, os_size);
        git.push(os);
    }

    git.show(); std::cin>>os_name>>os_version>>os_type>>os_size;
    OperatingSystem os = OperatingSystem(os_name, os_version, (Type)os_type, os_size);
    std::cout<<"=====Brishenje na operativen sistem====="<<std::endl;
    git.rm(os); git.show(); return 0;
}
