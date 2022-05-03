#include <iostream>
#include <string.h>

#define DEFAULT_SIZE 1024

class Employee
{
protected:
    char* employeeName{ nullptr }; int age{ 0 }, experience{ 0 };
public:
    Employee() {}

    Employee(char* employeeName, int age, int experience) {
        this->employeeName = new char[strlen(employeeName) + 1]; strcpy_s(this->employeeName, strlen(employeeName), employeeName); //courses: strcpy(this->employeeName, employeeName);
        this->age = age; this->experience = experience;
    }

    Employee(const Employee& e) {
        if (this != &e) {
            delete[] this->employeeName; this->employeeName = new char[strlen(e.employeeName) + 1]; strcpy_s(this->employeeName, strlen(e.employeeName), e.employeeName); //courses: strcpy(this->employeeName, e.employeeName);
            this->age = e.age; this->experience = e.experience;
        }
    }

    int getAge() { return this->age; }

    ~Employee() { delete[] this->employeeName; employeeName = nullptr; }

    inline virtual double salary() = 0;
    inline virtual double bonus() = 0;
};

class SalaryEmployee : public Employee
{
private:
    int basicSalary{ 0 };
public:
    SalaryEmployee() {}

    SalaryEmployee(char* employeeName, int age, int experience, int basicSalary) : Employee(employeeName, age, experience) { this->basicSalary = basicSalary; }

    SalaryEmployee(const SalaryEmployee& e) : Employee(e.employeeName, e.age, e.experience) { if (this != &e) { this->basicSalary = e.basicSalary; } }

    ~SalaryEmployee() { delete[] this->employeeName; employeeName = nullptr; }

    inline double bonus() noexcept { return this->basicSalary * (this->experience / 100.00); }
    inline double salary() noexcept { return this->basicSalary + this->bonus(); }
};

class HourlyEmployee : public Employee
{
private:
    int hoursWorked{ 0 }, hourlyPay{ 0 };
public:
    HourlyEmployee() {}

    HourlyEmployee(char *employeeName, int age, int experience, int hoursWorked, int hourlyPay) : Employee(employeeName, age, experience) { this->hoursWorked = hoursWorked; this->hourlyPay = hourlyPay; }

    HourlyEmployee(const HourlyEmployee& e) : Employee(e.employeeName, e.age, e.experience) { if (this != &e) { this->hoursWorked = e.hoursWorked; this->hourlyPay = e.hourlyPay; } }

    ~HourlyEmployee() { delete[] this->employeeName; employeeName = nullptr; }

    inline double bonus() noexcept { int tmp = this->hoursWorked - 320; double sum = 0.00; if (tmp > 0) { while (tmp) { sum += this->hourlyPay * 0.5; tmp--; } } return sum; }
    inline double salary() noexcept { return this->hoursWorked * this->hourlyPay + this->bonus(); }
};

class Freelancer : public Employee
{
private:
    int numProjects{ 0 }; double* projects{ nullptr };
public:
    Freelancer() {}

    Freelancer(char* employeeName, int age, int experience, int numProjects, double* projects) : Employee(employeeName, age, experience) {
        this->numProjects = numProjects; this->projects = new double[numProjects]; for (unsigned int i = 0; i < numProjects; i++) { this->projects[i] = projects[i]; }
    }

    Freelancer(const Freelancer& e) : Employee(e.employeeName, e.age, e.experience) {
        if (this != &e) {
            this->numProjects = e.numProjects; this->projects = new double[e.numProjects]; for (unsigned int i = 0; i < e.numProjects; i++) { this->projects[i] = e.projects[i]; }
        }
    }

    ~Freelancer() { delete[] this->employeeName; employeeName = nullptr; delete[] this->projects; this->projects = nullptr; }

    inline double bonus() noexcept { int tmp = this->numProjects - 5; double sum = 0.00; if (tmp > 0) { while (tmp) { sum += 1000; tmp--; } } return sum; }
    inline double salary() noexcept { double sum = 0.00; for (unsigned int i = 0; i < this->numProjects; i++) { sum += this->projects[i]; } return sum + this->bonus(); }
};

inline bool operator == (Employee& cmp1, Employee& cmp2) noexcept { return ((cmp1.getAge() == cmp2.getAge()) && (cmp1.bonus() == cmp2.bonus())); }

class Company
{
private:
    char* name{ nullptr }; int num{ 0 }; Employee** ptr_arr{ nullptr };
public:
    Company() {}

    Company(char* name) { this->name = new char[strlen(name) + 1]; strcpy_s(this->name, strlen(name), name); } //courses: strcpy(this->name, name);

    Company(char *name, int num, Employee **ptr_arr){
        this->num = num; this->name = new char[strlen(name)+1]; strcpy_s(this->name, strlen(name), name); //courses: strcpy(this->name, name);
        this->ptr_arr = new Employee* [num]; for(int i=0; i<num; i++){ this->ptr_arr[i] = ptr_arr[i]; }
    }

    Company(const Company& c){
        if(this != &c){
            this->num = c.num; this->name = new char[strlen(c.name)+1]; strcpy_s(this->name, strlen(c.name), c.name); //courses: strcpy(this->name, c.name);
            this->ptr_arr = new Employee* [c.num]; for(int i=0; i<c.num; i++){ this->ptr_arr[i] = c.ptr_arr[i]; }
        }
    }

    Company& operator += (Employee* e) {
        Employee** tmp = new Employee * [this->num + 1];
        for (unsigned int i = 0; i < this->num; i++) { tmp[i] = ptr_arr[i]; }
        tmp[this->num++] = e; delete[] this->ptr_arr; this->ptr_arr = new Employee * [this->num]; this->ptr_arr = tmp;
        return *this;
    }

    ~Company() { delete[] this->name; this->name = nullptr; delete[] this->ptr_arr; this->ptr_arr = nullptr; }

    inline double total_salary() noexcept { double sum = 0.00; for (unsigned int i = 0; i < this->num; i++) { sum += ptr_arr[i]->salary(); } return sum; }

    inline double filtered_salary(Employee* e) noexcept { double sum = 0.00; for (unsigned int i = 0; i < this->num; i++) { if (*ptr_arr[i] == *e) { sum += ptr_arr[i]->salary(); } } return sum; }

    inline void print() {
        int sum_salary = 0, sum_hourly = 0, sum_freelance = 0;

        for (unsigned int i = 0; i < this->num; i++) {
            sum_salary += dynamic_cast<SalaryEmployee*>(ptr_arr[i]) != NULL ? 1 : 0;
            sum_hourly += dynamic_cast<HourlyEmployee*>(ptr_arr[i]) != NULL ? 1 : 0;
            sum_freelance += dynamic_cast<Freelancer*>(ptr_arr[i]) != NULL ? 1 : 0;
        }

        std::cout << "Vo kompanijata " << name << " rabotat: " << std::endl
            << "Salary employees: " << sum_salary << std::endl
            << "Hourly employees: " << sum_hourly << std::endl
            << "Freelancers: " << sum_freelance << std::endl;
    }
};

int main()
{
    char* name = new char[DEFAULT_SIZE], * employeeName = new char [DEFAULT_SIZE]; int n, age, experience, type; std::cin >> name >> n; Company c(name);

    for (unsigned int i = 0; i < n; i++) {
        std::cin >> type >> employeeName >> age >> experience;

        if (type == 1) {
            int basicSalary; std::cin >> basicSalary;
            c += new SalaryEmployee(employeeName, age, experience, basicSalary);
        }

        else if (type == 2) {
            int hoursWorked, hourlyPay; std::cin >> hoursWorked >> hourlyPay;
            c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
        }

        else {
            int numProjects; double projects[10]; std::cin >> numProjects;
            for (unsigned int i = 0; i < numProjects; i++) { std::cin >> projects[i]; }
            c += new Freelancer(employeeName, age, experience, numProjects, projects);
        }
    }

    c.print(); std::cout << "Vkupnata plata e: " << c.total_salary() << std::endl;
    char word[] = "Petre_Petrov", * tmp = new char[strlen(word) + 1]; strcpy_s(tmp, strlen(word), word); Employee* emp = new HourlyEmployee(tmp, 31, 6, 340, 80);
    std::cout << "Filtriranata plata e: " << c.filtered_salary(emp);

    return 0;
}
