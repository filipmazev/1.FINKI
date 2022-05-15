#include <iostream>
#include <string.h>
#include <math.h>

constexpr size_t ACCOUNT_NUMBER_LENGHT = 15;
constexpr size_t CURRENCY_LENGHT = 3;
constexpr auto EUR_VALUE = 61.00;
constexpr auto USD_VALUE = 50.00;

enum class ERROR { NO_ERROR, DATE_ERROR, CURRENCY_ERROR };

class Transaction {
protected:
    int day{ int() }, month{ int() }, year{ int() }; double value{ double() };
public:
    static double EUR; static double USD;

    Transaction() {}
    Transaction(int day, int month, int year, double value) { this->day = day; this->month = month; this->year = year; this->value = value; }
    Transaction(const Transaction& t) { if (this != &t) { this->day = t.day; this->month = t.month; this->year = t.year; this->value = t.value; } }
    Transaction& operator = (const Transaction& t) { if (this != &t) { this->day = t.day; this->month = t.month; this->year = t.year; this->value = t.value; } return *this; }
    ~Transaction() {}

    inline virtual double to_MKD() = 0;
    inline virtual double to_EUR() = 0;
    inline virtual double to_USD() = 0;
    inline virtual void print() = 0;
};

double Transaction::EUR = EUR_VALUE;
double Transaction::USD = USD_VALUE;

class Transaction_Foreign : public Transaction {
private:
    char currency[CURRENCY_LENGHT + 1];
public:
    Transaction_Foreign() {}
    Transaction_Foreign(int day, int month, int year, double value, char* currency) : Transaction(day, month, year, value) { strcpy(this->currency, currency); }
    Transaction_Foreign(const Transaction_Foreign& tf) : Transaction(tf.day, tf.month, tf.year, tf.value) { if (this != &tf) { strcpy(this->currency, tf.currency); } }
    inline Transaction_Foreign& operator = (const Transaction_Foreign& tf) noexcept { if (this != &tf) { this->day = tf.day; this->month = tf.month; this->year = tf.year; this->value = tf.value; strcpy(this->currency, tf.currency); } return *this; }
    ~Transaction_Foreign(){}

    inline double to_MKD() noexcept {  
        if (strcmp(currency, "EUR") == 0) { return this->value * EUR; }
        if (strcmp(currency, "USD") == 0) { return floor(this->value * USD); }
        else { return this->value; }
    }

    inline double to_EUR() noexcept { 
        if (strcmp(currency, "EUR") == 0) { return this->value; }
        if (strcmp(currency, "USD") == 0) { return (this->value * USD) / EUR; }
        else { return this->value / EUR; }
    }
    
    inline double to_USD() noexcept { 
        if (strcmp(currency, "USD") == 0) { return this->value; }
        if (strcmp(currency, "EUR") == 0) { return (this->value * EUR) / USD; }
        else { return this->value / EUR; }
    }
   
    inline void print() { std::cout << this->day << "/" << this->month << "/" << this->year << " " << this->value << " " << this->currency << std::endl; }
};

class Transaction_MKD : public Transaction {
public:
    Transaction_MKD() {}
    Transaction_MKD(int day, int month, int year, double value) : Transaction(day, month, year, value) {}
    Transaction_MKD(const Transaction_MKD& tm) : Transaction(tm.day, tm.month, tm.year, tm.value) { }
    inline Transaction_MKD& operator = (const Transaction_MKD& tm) noexcept { if (this != &tm) { this->day = tm.day; this->month = tm.month; this->year = tm.year; this->value = tm.value; } return *this; }
    ~Transaction_MKD() {}

    inline double to_MKD() noexcept { return this->value; }
    inline double to_EUR() noexcept { return this->value / EUR; }
    inline double to_USD() noexcept { return this->value / USD; }
    inline void print() { std::cout << this->day << "/" << this->month << "/" << this->year << " " << this->value << " MKD " << std::endl; }
};

class Account {
private:
    Transaction** ptr_arr{ nullptr }; int num{ 0 }; char* account_number{ nullptr }; double balance_MKD{ double() };
public:
    Account(){}
    
    Account(char* account_number, int balance_MKD) {
        this->account_number = new char[strlen(account_number) + 1]; strcpy(this->account_number, account_number);
        this->balance_MKD = balance_MKD;
    }

    Account(const Account& a) {
        if (this != &a) {
            delete[] this->ptr_arr; this->ptr_arr = new Transaction * [a.num]; for (int i = 0; i < a.num; i++) { this->ptr_arr[i] = a.ptr_arr[i]; }
            delete[] this->account_number; this->account_number = new char[strlen(a.account_number) + 1]; strcpy(this->account_number, a.account_number);
            this->balance_MKD = a.balance_MKD; this->num = a.num;
        }
    }

    inline Account& operator = (const Account& a) noexcept {
        if (this != &a) {
            delete[] this->ptr_arr; this->ptr_arr = new Transaction * [a.num]; for (int i = 0; i < a.num; i++) { this->ptr_arr[i] = a.ptr_arr[i]; }
            delete[] this->account_number; this->account_number = new char[strlen(a.account_number) + 1]; strcpy(this->account_number, a.account_number);
            this->balance_MKD = a.balance_MKD; this->num = a.num;
        } return *this;
    }

    inline  Account operator += (Transaction* new_transaction) noexcept {
        Transaction** tmp = new Transaction * [this->num + 1]; for (int i = 0; i < this->num; i++) { tmp[i] = this->ptr_arr[i]; }
        tmp[this->num++] = new_transaction; delete[] this->ptr_arr; this->ptr_arr = new Transaction * [this->num]; this->ptr_arr = tmp;
        return *this;
    }

    ~Account() {
        if (this->ptr_arr != nullptr) { delete[] this->ptr_arr; this->ptr_arr = nullptr; }
        if (this->account_number != nullptr) { delete[] this->account_number; this->account_number = nullptr; }
    }

    inline void print_MKD() {
        double total_balance = this->balance_MKD; for (int i = 0; i < this->num; i++) { total_balance += ptr_arr[i]->to_MKD(); }
        std::cout << "Korisnikot so smetka: " << this->account_number << " ima momentalno saldo od " << total_balance << " MKD" << std::endl;
    }

    inline void print_EUR() {
        double total_balance = this->balance_MKD / ptr_arr[0]->EUR; for (int i = 0; i < this->num; i++) { total_balance += ptr_arr[i]->to_EUR(); }
        std::cout << "Korisnikot so smetka: " << this->account_number << " ima momentalno saldo od " << total_balance << " EUR " << std::endl;
    }

    inline void print_USD() {
        double total_balance = this->balance_MKD / ptr_arr[0]->USD; for (int i = 0; i < this->num; i++) { total_balance += ptr_arr[i]->to_USD(); }
        std::cout << "Korisnikot so smetka: " << this->account_number << " ima momentalno saldo od " << total_balance << " USD " << std::endl;
    }

    inline void print_transaction() { for (int i = 0; i < this->num; i++) { ptr_arr[i]->print(); } }
};

class InvalidDateException {
private:
    int day{ int() }, month{ int() }, year{ int() };
public: 
    InvalidDateException(){}
    InvalidDateException(int day, int month, int year) { this->day = day; this->month = month; this->year = year; }
    void print() { std::cout << "Invalid Date " << day << "/" << month << "/" << year << std::endl; }
};

class InvalidCurrencyException {
private:
    char* currency{ nullptr };
public:
    InvalidCurrencyException(){}
    InvalidCurrencyException(char* currency) { this->currency = new char[strlen(currency) + 1]; strcpy(this->currency, currency); }
    void print(){ std::cout << currency << " is not a supported currency" << std::endl; }
};

int main() {
    char* account_number = new char[ACCOUNT_NUMBER_LENGHT+1]; strcpy(account_number, "300047024112789"); Account a(account_number, 1500);

    int n, day, month, year, type; double value; char currency[CURRENCY_LENGHT+1]; std::cin >> n;
    
    std::cout << "===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI===" << std::endl;
  
    for (int i = 0; i < n; i++) {
        std::cin >> type >> day >> month >> year >> value; if(type == 2){ std::cin >> currency; }

        try {
            if (day > 31 || day < 0 || month > 12 || month < 0) { throw(ERROR::DATE_ERROR); }
            if (type == 2) { if (strcmp(currency, "EUR") != 0 && strcmp(currency, "USD") != 0) { throw(ERROR::CURRENCY_ERROR); } }
            throw(ERROR::NO_ERROR);
        }

        catch (ERROR ERROR_CODE) {

            if (ERROR_CODE == ERROR::DATE_ERROR) { InvalidDateException invalid_date_exception(day, month, year); invalid_date_exception.print(); }

            if (ERROR_CODE == ERROR::CURRENCY_ERROR) { InvalidCurrencyException invalid_currency_exception(currency); invalid_currency_exception.print(); }

            if (ERROR_CODE == ERROR::NO_ERROR) {
                if (type == 2) { Transaction* t = new Transaction_Foreign(day, month, year, value, currency); a += t; }
                else { Transaction* t = new Transaction_MKD(day, month, year, value);  a += t; }
            }
        }
    }

    std::cout << "===PECHATENJE NA SITE TRANSAKCII===" << std::endl; a.print_transaction();
    std::cout << "===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI===" << std::endl; a.print_MKD();
    std::cout << "===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA===" << std::endl; a.print_EUR();
    std::cout << "===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI===" << std::endl; a.print_USD();
   
    double new_EUR, new_USD; std::cin >> new_EUR >> new_USD; Transaction::EUR = new_EUR; Transaction::USD = new_USD;

    std::cout << "\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n" << std::endl;    
    std::cout << "===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI===" << std::endl; a.print_MKD();
    std::cout << "===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA===" << std::endl; a.print_EUR();
    std::cout << "===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI===" << std::endl; a.print_USD();

    return 0;
}
