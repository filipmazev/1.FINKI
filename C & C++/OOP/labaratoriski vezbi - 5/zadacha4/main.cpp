#include <iostream>
#include <string.h>

class Mountaineering_Association
{
private:
    char* name{nullptr}; int tours_num{0}, members_num{0};
public:
    Mountaineering_Association(){ this->name = nullptr; this->tours_num=0; this->members_num=0; }

    Mountaineering_Association(char* name, int tours_num, int members_num){
        this->name = new char[strlen(name)+1]; strcpy(this->name,name);
        this->tours_num = tours_num; this->members_num = members_num;
    }

    Mountaineering_Association(const Mountaineering_Association& m_a){
        if(this != &m_a){
            delete[] this->name; this->name = new char[strlen(m_a.name)+1]; strcpy(this->name,m_a.name);
            this->tours_num = m_a.tours_num; this->members_num = m_a.members_num;
        }
    }

    Mountaineering_Association& operator = (const Mountaineering_Association& m_a){
        if(this != &m_a){
            delete[] this->name; this->name = new char[strlen(m_a.name)+1]; strcpy(this->name,m_a.name);
            this->tours_num = m_a.tours_num; this->members_num = m_a.members_num;
        } return *this;
    }

    friend std::ostream& operator << (std::ostream& out, Mountaineering_Association &m_a){
        out<<"Ime: "<<m_a.name<<" Turi: "<<m_a.tours_num<<" Clenovi: "<<m_a.members_num;
        return out<<std::endl;
    }

    inline friend bool operator < (const Mountaineering_Association& curr, const Mountaineering_Association& comp) noexcept {
        return (curr.members_num < comp.members_num);
    }

    inline friend bool operator > (const Mountaineering_Association& curr, const Mountaineering_Association& comp) noexcept {
        return (curr.members_num > comp.members_num);
    }

    inline Mountaineering_Association operator + (const Mountaineering_Association& other) noexcept {
        Mountaineering_Association tmp = this->members_num>other.members_num
        ?Mountaineering_Association(this->name, this->tours_num, this->members_num + other.members_num)
        :Mountaineering_Association(other.name, other.tours_num, this->members_num + other.members_num);
        return tmp;
    }

    ~Mountaineering_Association(){ delete[] this->name; this->name = nullptr; }
};

void most_members(Mountaineering_Association* m_a, int num){
    Mountaineering_Association maxi = m_a[0];

    for(int i=0; i<num; i++){ if(m_a[i]>maxi){ maxi = m_a[i]; } }
    std::cout<<"Najmnogu clenovi ima planinarskoto drustvo: "<<maxi;
}

int main()
{
    Mountaineering_Association arr[3]; Mountaineering_Association association_1;

    for (int i=0;i<3;i++)
   	{
    	char name[100]; int tours_num, members_num;
    	std::cin>>name>>tours_num>>members_num;
    	Mountaineering_Association m_a(name,tours_num,members_num);
        arr[i] = m_a;
   	}

    association_1 = arr[0] + arr[1]; std::cout<<association_1;
    most_members(arr, 3);

    return 0;
}

