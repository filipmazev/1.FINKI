#include <iostream>
#include <cstring>

class StockRecord
{
private:
    char ID[12], name[50];
    double buy_price, cur_price;
    int stock_ammount;
public:
    StockRecord()=default;
    StockRecord(char id[12], char n[50], double b_p, int s_a)
    { strcpy(ID,id); strcpy(name, n); buy_price = b_p; stock_ammount = s_a; }
    ~StockRecord(){};

    void setNewPrice(double c){ cur_price = c; }

    double value(){ return stock_ammount*cur_price; }
    double profit()const{ return stock_ammount * (cur_price - buy_price); }

    char *getName(){ return name; } double getBuy_Price(){ return buy_price; } double getCur_Price(){ return cur_price; } int getStockAmmount(){ return stock_ammount; }

    StockRecord &operator=(const StockRecord &adder)
    {
        strcpy(ID, adder.ID); strcpy(name, adder.name);
        buy_price = adder.buy_price; cur_price = adder.cur_price; stock_ammount = adder.stock_ammount;
    }

    friend std::ostream &operator<<(std::ostream &output, const StockRecord &adder)
    {
        output<<adder.name<<" "<<adder.stock_ammount<<" "<<adder.buy_price<<" "<<adder.cur_price<<" "<<adder.profit()<<std::endl;
        return output;
    }
};

class Client
{
private:
    char name_surname[60];
    int wallet_ID, arr_n=0;
    StockRecord *arr;
public:
    Client() = default;
    Client(char n_s[60], int w_id){ strcpy(name_surname,n_s); wallet_ID = w_id; arr_n=0; arr = new StockRecord[60]; }
    ~Client(){};

    double totalValue(){ double sum=0.00; for(int i=0; i<arr_n; i++){ sum+=arr[i].value(); } return sum; }

    Client &operator+=(StockRecord &other){ arr[arr_n]=other; arr_n++; return *this; }

    friend std::ostream &operator<<(std::ostream &output, Client &adder)
    {
        output<<adder.wallet_ID<<" "<<adder.totalValue()<<std::endl;
        for(int i=0; i<adder.arr_n; i++){ output<<adder.arr[i].getName()<<" "<<adder.arr[i].getStockAmmount()<<" "<<adder.arr[i].getBuy_Price()<<" "<<adder.arr[i].getCur_Price()<<" "<<adder.arr[i].profit()<<std::endl; }
        return output;
    }
};

int main()
{
    int test; std::cin>>test;

    if(test == 1)
    {
    	double price;
        std::cout<<"=====TEST NA KLASATA StockRecord====="<<std::endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        std::cout<<"Konstruktor OK"<<std::endl; std::cin>>price;
        sr.setNewPrice(price);
        std::cout<<"SET metoda OK"<<std::endl;
    }

    else if(test == 2)
    {
        std::cout<<"=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord====="<<std::endl;
    	char id[12], company[50]; double price, newPrice; int n, shares; std::cin>>n;
        for(int i=0; i<n; i++)
        {
        	std::cin>>id>>company>>price>>newPrice>>shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            std::cout<<sr.value()<<std::endl<<sr;
        }
    }

    else if(test == 3)
    {
    	std::cout<<"=====TEST NA KLASATA Client====="<<std::endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares; double oldPrice, newPrice; bool flag = true;
        std::cin>>clientName>>clientID>>n; Client c(clientName, clientID);
        std::cout<<"Konstruktor OK"<<std::endl;

        for(int i=0; i<n; i++)
        {
            std::cin>>companyID>>companyName>>oldPrice>>newPrice>>shares;
        	StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice); c += sr;
            if(flag){ std::cout<<"Operator += OK"<<std::endl; flag = false; }
        }

        std::cout<<c<<"Operator << OK"<<std::endl;
    }

    return 0;
}
