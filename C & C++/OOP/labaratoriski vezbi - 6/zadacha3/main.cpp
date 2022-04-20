#include <iostream>
#include <string.h>

class M_D
{
protected:
    int facsimile{0}; char *name{nullptr}, *surname{nullptr}; double starting_salary{0.00};
public:
    M_D(){ this->facsimile=0; this->name=nullptr; this->surname=nullptr; this->starting_salary=0.00; }

    M_D(int facsimile, char *name, char *surname, double starting_salary){
        this->name = new char[strlen(name)+1]; strcpy(this->name,name);
        this->surname = new char[strlen(surname)+1]; strcpy(this->surname,surname);
        this->facsimile = facsimile; this->starting_salary = starting_salary;
    }

    M_D(const M_D& m_d){
        if(this != &m_d){
            delete[] this->name; this->name = new char[strlen(m_d.name)+1]; strcpy(this->name,m_d.name);
            delete[] this->surname; this->surname = new char[strlen(m_d.surname)+1]; strcpy(this->surname,m_d.surname);
            this->facsimile = m_d.facsimile; this->starting_salary = m_d.starting_salary;
        }
    }

    M_D &operator = (const M_D& m_d){
        if(this != &m_d){
            delete[] this->name; this->name = new char[strlen(m_d.name)+1]; strcpy(this->name,m_d.name);
            delete[] this->surname; this->surname = new char[strlen(m_d.surname)+1]; strcpy(this->surname,m_d.surname);
            this->facsimile = m_d.facsimile; this->starting_salary = m_d.starting_salary;
        } return *this;
    }

    ~M_D(){ delete[] this->name; this->name = nullptr; delete[] this->surname; this->surname = nullptr; }

    void print(){ std::cout<<this->facsimile<<": "<<this->name<<" "<<this->surname<<std::endl; }
    double getSalary(){ return this->starting_salary; }

};

class family_doctor : protected M_D
{
private:
    int patient_num{0}; double* fees{nullptr};
public:
    family_doctor(){ this->patient_num= 0; this->fees = nullptr; }

    family_doctor(M_D& m_d, int patient_num, double *fees) : M_D(m_d) {
        this->patient_num = patient_num; this->fees = new double[patient_num]; for(int i=0; i<this->patient_num; i++){ this->fees[i] = fees[i]; }
    }

    double fee_avg(){ double sum=0.00; for(int i=0; i<this->patient_num; i++){ sum+=this->fees[i]; } return sum / patient_num; }

    void print(){ M_D::print(); std::cout<<"Prosek na kotizacii: "<<this->fee_avg()<<std::endl; }

    double getSalary(){ return starting_salary + (this->fee_avg()*0.30); }
};

int main()
{
	int n, patients, facsimile; double fees[100], starting_salary; char name[20], surname[20]; std::cin>>n;

	M_D* doc_arr = new M_D [n]; family_doctor * f_d_arr = new family_doctor [n];

	for (int i=0;i<n;i++){ std::cin >> facsimile >> name >> surname >> starting_salary; doc_arr[i] = M_D(facsimile,name,surname,starting_salary); }

	for (int i=0;i<n;i++){
        std::cin >> patients; for (int j=0;j<patients;j++){ std::cin >> fees[j]; }
		f_d_arr[i]=family_doctor(doc_arr[i],patients,fees);
    }

	int testCase; std::cin>>testCase;

	if (testCase==1){
		std::cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<std::endl;
		for (int i=0;i<n;i++){ doc_arr[i].print(); std::cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<doc_arr[i].getSalary()<<std::endl; }
	}

	else {
		std::cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<std::endl;
		for (int i=0;i<n;i++){ f_d_arr[i].print(); std::cout<<"Platata na gorenavedeniot maticen lekar e: "<<f_d_arr[i].getSalary()<<std::endl;
		}
	}

	delete[] doc_arr; delete[] f_d_arr; return 0;
}
