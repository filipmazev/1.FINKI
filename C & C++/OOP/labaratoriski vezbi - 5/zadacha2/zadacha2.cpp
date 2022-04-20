#include <iostream>
#include <string.h>
#include <cmath>

class ComplexNumber
{
private:
	double real{ 0 }, imaginary{ 0 };
public:
	ComplexNumber() { this->real = 0; this->imaginary = 0; }
	ComplexNumber(double real, double imaginary) {
		this->real = real; this->imaginary = imaginary;
	}

	ComplexNumber(const ComplexNumber& c) { if (this != &c) { this->real = c.real; this->imaginary = c.imaginary; } }

	ComplexNumber& operator = (const ComplexNumber& c) { if (this != &c) { this->real = c.real; this->imaginary = c.imaginary; } return *this; }

	inline friend std::ostream& operator << (std::ostream& out, const ComplexNumber& c) {
		if (c.real != 0) { out << c.real; if (c.imaginary != 0) { out << "+" << c.imaginary << "i"; } }
		else if (c.imaginary != 0) { out << c.imaginary << "i"; }
		return out<<std::endl;
	}

	inline ComplexNumber operator + (const ComplexNumber &c) noexcept {
		ComplexNumber tmp; tmp.real = this->real + c.real; tmp.imaginary = this->imaginary + c.imaginary;
		return tmp;
	}

	inline ComplexNumber operator - (const ComplexNumber& c) noexcept {
		ComplexNumber tmp; tmp.real = this->real - c.real; tmp.imaginary = this->imaginary - c.imaginary;
		return tmp;
	}

	inline ComplexNumber operator * (const ComplexNumber& c) noexcept  {
		ComplexNumber tmp; tmp.real = this->real * c.real; tmp.imaginary = this->imaginary * c.imaginary;
		return tmp;
	}

	inline ComplexNumber operator / (const ComplexNumber& c) noexcept {
		ComplexNumber tmp; tmp.real = this->real / c.real; tmp.imaginary = this->imaginary / c.imaginary;
		return tmp;
	}

	inline friend bool operator == (const ComplexNumber& curr, const ComplexNumber& comp) noexcept
	{
		return (curr.real == comp.real && curr.imaginary == comp.imaginary);
	}

	inline friend bool operator > (const ComplexNumber &curr, const ComplexNumber &comp) noexcept
	{
		return curr == comp ? false : (curr.real != comp.real ? (curr.real > comp.real) : curr.imaginary > comp.imaginary);
	}

	inline friend bool operator < (const ComplexNumber& curr, const ComplexNumber& comp) noexcept
	{
		return curr == comp ? false : (curr.real != comp.real ? (curr.real < comp.real) : curr.imaginary < comp.imaginary);
	}

	friend std::istream& operator >> (std::istream& input, ComplexNumber& e) noexcept { input >> e.real >> e.imaginary;	return input; }

	double module() { return sqrt(pow(this->real, 2) + pow(imaginary, 2)); }

	~ComplexNumber() {}
};

class Equation
{
private:
	ComplexNumber* arr{ nullptr }; char* operation{ nullptr }; int num{ 0 };
public:
	Equation() { this->arr = nullptr; this->operation = nullptr; }
	
	Equation(const Equation& e) {
		if (this != &e) {
			delete[] this->arr; this->arr = new ComplexNumber[e.num];
			delete[] this->operation; this->operation = new char[strlen(e.operation) + 1];
			strcpy_s(this->operation, strlen(e.operation) + 1, e.operation);
			for (size_t i = 0; i < e.num; i++) { this->arr[i] = e.arr[i]; } this->num = e.num;
		}
	}

	Equation &operator = (const Equation& e) {
		if (this != &e) {
			delete[] this->arr; this->arr = new ComplexNumber[e.num];
			delete[] this->operation; this->operation = new char[strlen(e.operation) + 1];
			strcpy_s(this->operation, strlen(e.operation) + 1, e.operation);
			for (size_t i = 0; i < e.num; i++) { this->arr[i] = e.arr[i]; } this->num = e.num;
		} return *this;
	}

	friend std::istream& operator >> (std::istream& input, Equation& e) noexcept {

		char op = '/'; while (op != '=') {
			ComplexNumber* tmp = new ComplexNumber[e.num + 1];
			char* c_tmp = new char[(op != '=' ? e.num + 1 : e.num)]; strcpy_s(c_tmp, e.num, e.operation);
			for (size_t i = 0; i < e.num; i++) { tmp[i] = e.arr[i]; } std::cin >> tmp[e.num++] >> op;
			delete[] e.arr; e.arr = new ComplexNumber[e.num]; e.arr = tmp;
			if (op != '=') { c_tmp[e.num - 1] = op; } delete[] e.operation; e.operation = new char[e.num]; e.operation = c_tmp;
		}
		return input;
	}

	double sumModules() { double sum = 0.00; for (size_t i = 0; i < this->num; i++) { sum += this->arr[i].module(); } return sum; }

	ComplexNumber result() {
		ComplexNumber tmp = this->arr[0];
		for (int i = 0; i < this->num - 1; i++) {
			tmp = (operation[i] == '+' ? tmp + this->arr[i + 1] : (operation[i] == '-' ? tmp - this->arr[i + 1] : (operation[i] == '*' ? tmp * this->arr[i + 1] : tmp / this->arr[i + 1])));
		}
		return tmp;
	}

	~Equation() { delete[] this->arr; this->arr = nullptr; delete[] this->operation; this->operation = nullptr; }
};

int main() {
	int testCase; double real, imaginary;
	ComplexNumber first, second, result;

	std::cin >> testCase;

	if (testCase <= 8) {
		std::cin >> real >> imaginary; first = ComplexNumber(real, imaginary);
		std::cin >> real >> imaginary; second = ComplexNumber(real, imaginary);
	}

	if (testCase == 1) {
		std::cout << "===== OPERATOR + =====" << std::endl;
		result = first + second; std::cout << result;
	}

	else if (testCase == 2) {
		std::cout << "===== OPERATOR - =====" << std::endl;
		result = first - second; std::cout << result;
	}

	else if (testCase == 3) {
		std::cout << "===== OPERATOR * =====" << std::endl;
		result = first * second; std::cout << result;
	}

	else if (testCase == 4) {
		std::cout << "===== OPERATOR / =====" << std::endl;
		result = first / second; std::cout << result;
	}

	else if (testCase == 5) {
		std::cout << "===== OPERATOR == =====" << std::endl << first << second;
		if (first == second) { std::cout << "EQUAL" << std::endl; }
		else { std::cout << "NOT EQUAL" << std::endl; }
	}

	else if (testCase == 6) {
		std::cout << "===== OPERATOR > =====" << std::endl << first << second;
		if (first > second) { std::cout << "FIRST GREATER THAN SECOND" << std::endl; }
		else { std::cout << "FIRST LESSER THAN SECOND" << std::endl; }
	}

	else if (testCase == 7) {
		std::cout << "===== OPERATOR < =====" << std::endl << first << second;
		if (first < second) { std::cout << "FIRST LESSER THAN SECOND" << std::endl; }
		else { std::cout << "FIRST GREATER THAN SECOND" << std::endl; }
	}

	else if (testCase == 8) {
		std::cout << "===== MODULE =====" << std::endl;
		double module = first.module(); std::cout << first << "Module: " << module << std::endl << second;
		module = second.module(); std::cout << "Module: " << module << std::endl;
	}

	else if (testCase == 9) {
		std::cout << "===== OPERATOR >> & SUM OF MODULES =====" << std::endl;
		Equation equation; std::cin >> equation; std::cout << equation.sumModules();
	}

	//else if (testCase == 10) {
	//	std::cout << "===== EQUATION RESULT =====" << std::endl;
	//	Equation equation; std::cin >> equation; result = equation.result(); std::cout << result;
	//}

	return 0;
}

