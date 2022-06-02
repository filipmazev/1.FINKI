#include <iostream>
#include <math.h>
using std::cout;
using std::endl;
using std::cin;

enum class ERROR { NO_ERROR, OUT_OF_BOUNDS };

class out_of_bounds {
public:
    out_of_bounds() {};
    void print() { cout << "ERROR: out of bounds" << endl; throw std::bad_alloc(); }
};

template <typename TYPE>
class Array
{
private:
    TYPE* arr{ nullptr }; int num{ 0 };
public:
    Array() {};

    Array(int num) { this->num = num; this->arr = new TYPE[num]; }

    Array(TYPE* arr, int num) {
        this->num = num; this->arr = new TYPE[num]; for (int i = 0; i < num; i++) { this->arr[i] = arr[i]; }
    }

    Array(const Array& a) {
        delete[] this->arr; this->arr = new TYPE[a.num]; for (int i = 0; i < a.num; i++) { this->arr[i] = a.arr[i]; } this->num = a.num;
    }

    Array& operator = (const Array& a) noexcept {
        delete[] this->arr; this->arr = new TYPE[a.num]; for (int i = 0; i < a.num; i++) { this->arr[i] = a.arr[i]; } this->num = a.num;
        return *this;
    }

    ~Array() { if (this->arr != nullptr) { delete[] this->arr; this->arr = nullptr; } }

    void Erase() { if (this->arr != nullptr) { delete[] this->arr; this->arr = nullptr; this->num = 0; this->arr = new TYPE[this->num]; } }

    auto& operator [] (int index) noexcept {
        try { if (index > num || index < 0) { throw(ERROR::OUT_OF_BOUNDS); } else { return this->arr[index]; } }
        catch (ERROR CODE) { if (CODE == ERROR::OUT_OF_BOUNDS) { out_of_bounds error; error.print(); return this->arr[0]; } }
        return this->arr[index];
    }

    friend std::istream& operator >> (std::istream& in, const Array& a) noexcept {
        int n = a.num; TYPE* tmp = new TYPE[n + 1]; for (int i = 0; i < n; i++) { tmp = a.arr[i]; }
        in >> tmp[n++]; delete[] a.arr; a.arr = new TYPE[n]; a.arr = tmp; a.num = n; return in;
    }

    friend std::ostream& operator << (std::ostream& out, const Array& a) noexcept {
        for (int i = 0; i < a.num; i++) { cout << "Array[" << i << "] = " << a.arr[i]; i < a.num - 1 ? cout << ", " : cout << " "; } return out << endl;
    }

    friend bool operator == (const Array& cmp_1, const Array& cmp_2) noexcept {
        if (typeid(cmp_1.arr[0]) != typeid(cmp_2.arr[0]) || cmp_1.num != cmp_2.num) { return false; }
        for (int i = 0; i < cmp_1.num; i++) { if (cmp_1.arr[i] != cmp_2.arr[i]) { return false; } }
        return true;
    }

    friend bool operator != (const Array& cmp_1, const Array& cmp_2) noexcept { return !(cmp_1 == cmp_2); }

    int getLenght() { return this->num; }
};


template <class TYPE> TYPE sum(Array<TYPE>  arr) { TYPE elem_sum = TYPE(); for (int i = 0; i < arr.getLenght(); i++) { elem_sum += arr[i]; } return elem_sum; };
template <class  TYPE> TYPE avg(Array< TYPE>& arr) { return sum(arr) / arr.getLenght(); }

template <class TYPE> void sort(Array<TYPE>& arr) {
    for (int i = 0; i < arr.getLenght(); i++) {
        for (int j = 0; j < arr.getLenght() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { TYPE temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp; }
        }
    }
}

template <class TYPE_1, class TYPE_2> bool equal(Array<TYPE_1>& cmp_1, Array<TYPE_2>& cmp_2) { return cmp_1 == cmp_2; }

template <typename TYPE> bool equal(Array<TYPE>& cmp_1, Array<double>& cmp_2) {
    if (cmp_1.getLenght() != cmp_2.getLenght() || abs(avg(cmp_1) - avg(cmp_2) > 0.5)) { return false; }
    for (int i = 0; i < cmp_1.getLenght(); i++) { if (abs(cmp_1[i] - cmp_2[i]) > 0.1) { return false; } }
    return true;
}

int main()
{
    int n; double adder; cin >> adder >> n; Array<int> arr(n); Array<double> sum_arr(n); Array<int> arr_2(n);
    for (int i = 0; i < n; i++) { cin >> arr[i]; sum_arr[i] = arr[i] + adder; }

    sort(arr); arr_2 = arr;

    cout << "The arrays: " << endl << arr << "and " << endl << arr_2;
    cout << ((equal(arr, arr_2)) ? " ARE" : " ARE NOT") << " same!" << endl;
    cout << "The Average of the array adArray is: " << avg(sum_arr) << endl;
    cout << "The arrays: " << endl << arr << "and " << endl << sum_arr << ((equal(arr, sum_arr)) ? " ARE" : " ARE NOT") << " same!";

    return 0;
}
