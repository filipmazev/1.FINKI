#include <iostream>
#include <cstring>
#define SIZE 3

class Signee
{
private:
    char *name, *lastname, *SSN;
public:
    Signee(){ name=nullptr; lastname=nullptr; SSN=nullptr; }
    Signee(char *name, char *lastname, char *SSN){
    this->name = new char[strlen(name)+1]; this->lastname = new char[strlen(lastname)+1]; this->SSN = new char[strlen(SSN)+1];
    strcpy(this->name,name); strcpy(this->lastname,lastname); strcpy(this->SSN,SSN); }
    ~Signee(){}

    char *getSSN(){ return this->SSN; }
};

class Contract
{
private:
    int num; char *category; Signee s[SIZE];
public:
    Contract(){ category=nullptr; }
    Contract(int num, char *category, Signee *s){ this->category = new char[strlen(category)+1];
    strcpy(this->category,category); this->num=num; for(int i=0; i<SIZE; i++){ this->s[i] = s[i]; } }
    ~Contract(){}

    bool check(){ bool diff=false;
    for(int i=0; i<SIZE-1; i++){ if((strcmp(this->s[i].getSSN(),this->s[i+1].getSSN())) == 0) { diff = true; break; } } return diff; }
};

int main()
{
    char SSN[13], name[20], lastname[20], category[20]; int num, n; std::cin>>n;

    for(int i=0; i<n; i++)
    {
    	std::cin>>SSN>>name>>lastname; Signee s1(name, lastname, SSN);
    	std::cin>>SSN>>name>>lastname; Signee s2(name, lastname, SSN);
    	std::cin>>SSN>>name>>lastname; Signee s3(name, lastname, SSN);

    	std::cin>>num>>category; Signee s[SIZE]; s[0] = s1; s[1] = s2; s[2] = s3; Contract c(num, category, s);

        std::cout<<"Dogovor "<<num<<":"<<std::endl;
        if(c.check() == true) { std::cout<<"Postojat potpishuvaci so ist EMBG"<<std::endl; }
    	else { std::cout<<"Ne postojat potpishuvaci so ist EMBG"<<std::endl; }
    }

    return 0;
}
