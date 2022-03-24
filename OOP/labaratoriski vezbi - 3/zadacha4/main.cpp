#include <iostream>
#include <cstring>

class Table
{
private:
    int table_W, table_L;
public:
    Table(){}
    Table(int table_W, int table_L){ this->table_W=table_W; this->table_L=table_L; }
    ~Table(){}

    void print(){ std::cout<<"Masa: "<<this->table_W<<" "<<this->table_L<<std::endl; }
};

class Room
{
private:
    Table t; int room_W, room_L;
public:
    Room(){}
    Room(int room_W, int room_L, Table t){ this->t=t; this->room_W=room_W; this->room_L=room_L; }
    ~Room(){}

    void print(){ std::cout<<"Soba: "<<this->room_W<<" "<<this->room_L<<" "; t.print(); }
};

class House
{
private:
    Room r; char *address;
public:
    House(){ address = nullptr; }
    House(Room r, char *address){ this->address = new char[strlen(address)+1]; strcpy(this->address,address); this->r=r; }
    ~House(){}

    void print(){ std::cout<<"Adresa: "<<this->address<<" "; r.print(); }
};

int main()
{
    int n, table_W, table_L,  room_W, room_L; char address[30]; std::cin>>n;

    for(int i=0; i<n; i++)
    {
        std::cin>>table_W>>table_L>>room_W>>room_L>>address;
    	Table t(table_W,table_L); Room r(room_W,room_L,t); House h(r,address); h.print();
    }

    return 0;
}
