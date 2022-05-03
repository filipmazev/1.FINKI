#include<iostream>
#include<string.h>

#define SIZE 100

class Secret
{
public:
    inline virtual double simpleEntropy() = 0;
    inline virtual int total() = 0;
};

class DigitSecret : public Secret
{
private:
    int* arr = new int[SIZE], n;
public:
    DigitSecret(){}

    DigitSecret(int* arr, int n){ this->n = n; this->arr = new int[n]; for(int i=0; i<n; i++){ this->arr[i] = arr[i]; } }

    DigitSecret(const DigitSecret& ds){ if(this != &ds){ delete[] this->arr; this->arr = new int[ds.n]; for(int i=0; i<ds.n; i++){ this->arr[i] = ds.arr[i]; } this->n = ds.n; } }

    inline int total() noexcept { return n; }

    inline double simpleEntropy() noexcept
    {
        int sum=0;
        for(int i=0; i<n; i++){ int sum2=0;
            for(int j=0; j<n; j++){ if(arr[i] == arr[j]){ sum2++; } }
            if(sum2==1){ sum++; }
        }
        return (double)sum/n;
    }

    inline friend std::ostream& operator << (std::ostream& out, DigitSecret& other){
        for(int i=0; i<other.n; i++){ out<<other.arr[i]; } out<<" Simple entropy: "<<other.simpleEntropy()<<" Total: "<<other.total(); return out;
    }

    ~DigitSecret(){ if(this->arr != nullptr){ delete[] this->arr; this->arr = nullptr; } }
};

class CharSecret : public Secret
{
private:
    char* arr = new char[SIZE];
public:
    CharSecret(){}

    CharSecret(char* arr){ this->arr = new char[strlen(arr)+1]; strcpy(this->arr, arr); }

    CharSecret(const CharSecret& cs){ if(this != &cs){ delete[] this->arr; this->arr = new char[strlen(cs.arr)+1]; strcpy(this->arr, cs.arr); } }

    inline int total() noexcept { return strlen(arr); }

    inline double simpleEntropy() noexcept
    {
        int sum=0;
        for(int i=0; i<strlen(arr); i++)
        {
            int sum2=0;
            for(int j=0; j<strlen(arr); j++){ if(arr[i] == arr[j]){ sum2++; } }
            if(sum2==1){ sum++; }
        }
        return (double)sum/strlen(arr);
    }

    inline friend std::ostream& operator << (std::ostream& out, CharSecret& other){
        for(int i=0; i<strlen(other.arr); i++){ out<<other.arr[i]; } out<<" Simple entropy: "<<other.simpleEntropy()<<" Total: "<<other.total(); return out;
    }

    ~CharSecret(){ if(this->arr != nullptr){ delete[] this->arr; this->arr = nullptr; } }
};

inline bool operator == (Secret &s, Secret &s1) noexcept { return ((s.simpleEntropy() == s1.simpleEntropy()) && (s.total() == s1.total())); }
inline bool operator != (Secret &s, Secret &s1) noexcept { return !(s==s1); }

void process(Secret** ptr_arr, int n){
    double _max=0.00; int pos=0;

    for(int i=0; i<n; i++){
        double val = ptr_arr[i]->simpleEntropy();
        if(val > _max){ _max = val; pos=i; }
    }

    if(dynamic_cast<DigitSecret*>(ptr_arr[pos])){ std::cout<<*dynamic_cast<DigitSecret*>(ptr_arr[pos])<<std::endl; }
    else if(dynamic_cast<CharSecret*>(ptr_arr[pos])){ std::cout<<*dynamic_cast<CharSecret*>(ptr_arr[pos])<<std::endl; }
}

void printAll(Secret** ptr_arr, int n){
    for(int i=0; i<n; i++){
        if(dynamic_cast<DigitSecret*>(ptr_arr[i])){ std::cout<<*dynamic_cast<DigitSecret*>(ptr_arr[i])<<std::endl; }
        else if(dynamic_cast<CharSecret*>(ptr_arr[i])){ std::cout<<*dynamic_cast<CharSecret*>(ptr_arr[i])<<std::endl; }
    }
}

int main()
{
    int n; std::cin >> n;

    if (n == 0) {
        int numbers[] = { 1,2,3,4,5 };
        DigitSecret ds(numbers, 5); CharSecret cs("abcabc");
        std::cout << "Constructors" << std::endl << "OK" << std::endl;
    }

    else if (n == 1) {
        int numbers[] = { 1,2,3,4,5 };
        DigitSecret ds(numbers, 5); CharSecret cs("abcabc");
        std::cout << "operator <<" << std::endl << ds << std::endl << cs << std::endl;
    }

    else if (n == 2) {
        int numbers[] = { 1,2,3,4,5 };
        DigitSecret ds(numbers, 5); CharSecret cs("abcabc"); CharSecret css("abcabc");
        std::cout << "== and !=" << std::endl << (ds == cs) << std::endl << (cs != ds) << std::endl << (cs == css) << std::endl << (cs != css) << std::endl;
    }

    else if (n == 3) {
        std::cout << "Secret processor" << std::endl;
        int numbers1[] = { 1,2,3,4,5,6,4,3,2,1,1,2,3,4,5 }; DigitSecret ds1(numbers1, 15);
        int numbers2[] = { 1,2,3,4,5,0,0,0,5,5,4,4,3,3,2 }; DigitSecret ds2(numbers2, 15);
        int numbers3[] = { 1,0,9,4,3,8,4,0,9,3,1,4,3,2,1,4,4,3,7,2 }; DigitSecret ds3(numbers3, 20);

        CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq"); CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw"); CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq");
        Secret** s = new Secret * [6]; s[0] = &ds1; s[1] = &ds2; s[2] = &ds3; s[3] = &cs1; s[4] = &cs2; s[5] = &cs3;

        process(s, 6); delete[] s;
    }

    else if (n == 4) {
        std::cout << "Print all secrets" << std::endl;
        int numbers1[] = { 1,2,3,4,5,5,4,3,2,1,1,2,3,4,5 }; DigitSecret ds1(numbers1, 15);
        int numbers2[] = { 1,2,3,4,5,0,0,0,5,5,4,4,3,3,2 }; DigitSecret ds2(numbers2, 15);
        int numbers3[] = { 1,0,9,4,3,8,4,0,9,3,1,4,3,2,1,4,4,3,7,2 }; DigitSecret ds3(numbers3, 20);

        CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq"); CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw"); CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq");
        Secret** s = new Secret * [6]; s[0] = &ds1; s[1] = &ds2; s[2] = &ds3; s[3] = &cs1; s[4] = &cs2; s[5] = &cs3;

        printAll(s, 6); delete[] s;
    }

    return 0;
}
