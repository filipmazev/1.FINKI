#include<iostream>

enum type { ERROR, _int, _double };

class Number
{
public:
    Number() {}

    inline virtual double doubleValue() = 0;
    inline virtual int intValue() = 0;
    inline virtual void print() = 0;

    ~Number() {}
};

class Integer : public Number
{
private:
    int num{ int() };
public:
    Integer() {}

    Integer(int num) : Number() { this->num = num; }

    Integer(const Integer& i) : Number() { if (this != &i) { this->num = i.num; } }

    inline int intValue() noexcept { return (int)this->num; }

    inline double doubleValue() noexcept { return (double)this->num; }

    inline void print() { std::cout << num << std::endl; }

    ~Integer() {}
};

class Double : public Number
{
private:
    double num{ double() };
public:
    Double() {}

    Double(double num) : Number() { this->num = num; }

    Double(const Double& d) : Number() { if (this != &d) { this->num = d.num; } }

    inline int intValue() noexcept { return (int)this->num; }

    inline double doubleValue() noexcept { return (double)this->num; }

    inline void print() { std::cout << num << std::endl; }

    ~Double() {}
};

inline bool operator == (Number& cmp1, Number& cmp2) noexcept {
    return (cmp1.intValue() == cmp2.intValue() && cmp1.doubleValue() == cmp2.doubleValue());
}

class Numbers
{
private:
    Number** ptr_arr{ nullptr }; int num{ 0 };
public:
    Numbers() {}

    Numbers(Number** ptr_arr, int num) {
        this->num = num; this->ptr_arr = new Number * [num]; for (unsigned int i = 0; i < num; i++) { this->ptr_arr[i] = ptr_arr[i]; }
    }

    Numbers(const Numbers& n) {
        if (this != &n) {
            this->num = n.num; this->ptr_arr = new Number * [n.num]; for (unsigned int i = 0; i < n.num; i++) { this->ptr_arr[i] = n.ptr_arr[i]; }
        }
    }

    Numbers& operator += (Number* ptr) {
        for (unsigned int i = 0; i < this->num; i++) { if (*ptr_arr[i] == *ptr) { return *this; } }
        Number** tmp = new Number * [this->num + 1]; for (unsigned int i = 0; i < this->num; i++) { tmp[i] = this->ptr_arr[i]; }
        tmp[this->num++] = ptr; delete[] this->ptr_arr; this->ptr_arr = new Number * [this->num]; this->ptr_arr = tmp;
        return *this;
    }

    type getType(Number* ptr) { return dynamic_cast<Integer*>(ptr) != NULL ? (type)_int : (dynamic_cast<Double*>(ptr) != NULL ? (type)_double : (type)0 ) ; }

    void statistics() {

        double sum = 0.00, sum_double = 0.00; int cnt_int = 0, cnt_double = 0, sum_int = 0;

        for (int i = 0; i < this->num; i++) {
            sum += ptr_arr[i]->doubleValue();
            this->getType(ptr_arr[i]) == _int ? (sum_int += ptr_arr[i]->intValue(), cnt_int += 1) : (this->getType(ptr_arr[i]) == _double ? (sum_double += ptr_arr[i]->doubleValue(), cnt_double += 1) : 0);
        }

        std::cout << "Count of numbers: " << this->num << std::endl;
        std::cout << "Sum of all numbers: " << sum << std::endl;
        std::cout << "Count of integer numbers: " << cnt_int << std::endl;
        std::cout << "Sum of integer numbers: " << sum_int << std::endl;
        std::cout << "Count of double numbers: " << cnt_double << std::endl;
        std::cout << "Sum of double numbers: " << sum_double << std::endl;
    }

    void integersLessThan(Integer n) {
        int cnt = 0; for (int i = 0; i < this->num; i++) {
            if (getType(this->ptr_arr[i]) == _int) { if (this->ptr_arr[i]->intValue() < n.intValue()) { std::cout << "Integer: " << ptr_arr[i]->intValue() << std::endl; cnt++; } }
        } if (!cnt) { std::cout << "None" << std::endl; }
    }

    void doublesBiggerThan(Double n) {
        int cnt = 0; for (int i = 0; i < this->num; i++) {
            if (getType(this->ptr_arr[i]) == _double) { if (this->ptr_arr[i]->doubleValue() > n.doubleValue()) { std::cout << "Double: " << ptr_arr[i]->doubleValue() << std::endl; cnt++; } }
        } if (!cnt) { std::cout << "None" << std::endl; }
    }

    ~Numbers() { delete[] this->ptr_arr; this->ptr_arr = nullptr; }
};

int main()
{
    int n; std::cin >> n; Numbers numbers;

    for (unsigned int i = 0; i < n; i++) {
        int type; double number; std::cin >> type >> number;

        if (type == 0) { Integer* integer = new Integer((int)number); numbers += integer; }

        else { Double* doublee = new Double(number); numbers += doublee; }
    }

    int lessThan; double biggerThan;

    std::cin >> lessThan >> biggerThan;

    std::cout << "STATISTICS FOR THE NUMBERS\n"; numbers.statistics();
    std::cout << "INTEGER NUMBERS LESS THAN " << lessThan << std::endl; numbers.integersLessThan(Integer(lessThan));
    std::cout << "DOUBLE NUMBERS BIGGER THAN " << biggerThan << std::endl; numbers.doublesBiggerThan(Double(biggerThan));

    return 0;
}
