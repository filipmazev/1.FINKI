#include <iostream>

class ArithmeticException {
public:
	inline void message() { std::cout << "Division by zero is not allowed" << std::endl; }
};

class NumbersNotDivisibleException {
public:
	inline void message(int num) { std::cout << "Division by " << num << " is not supported" << std::endl; }
};

class ArrayFullException {
public:
	inline void message() { std::cout << "The array is full. Increase the capacity" << std::endl; }
};

class IndexOutOfBoundsException {
public:
	inline void message(int index) { std::cout << "Index " << index << " is out of bounds" << std::endl; }
};

class NumberIsNotPositiveException {
protected:
	bool check { false };
public:
	inline void message(int num) { std::cout << "Number " << num << " is not positive integer" << std::endl; }
};

class PositiveIntegers : public NumberIsNotPositiveException {
private:
	int* pos_num_arr{ nullptr }, num{ int() }, _max{ int() };
public:
	PositiveIntegers() {}

	PositiveIntegers(int _max) { this->_max = _max; }

	PositiveIntegers(int* pos_num_arr, int num, int _max) {
		this->pos_num_arr = new int[num]; for (int i = 0; i < num; i++) { this->pos_num_arr[i] = pos_num_arr[i]; }
		this->num = num; this->_max = _max;
	}

	PositiveIntegers(const PositiveIntegers& pi) {
		if (this != &pi) {
			delete[] this->pos_num_arr; this->pos_num_arr = new int[pi.num]; for (int i = 0; i < pi.num; i++) { this->pos_num_arr[i] = pi.pos_num_arr[i]; }
			this->num = pi.num; this->_max = pi._max;
		}
	}

	inline PositiveIntegers& operator = (const PositiveIntegers& pi) noexcept {
		if (this != &pi) {
			delete[] this->pos_num_arr; this->pos_num_arr = new int[pi.num]; for (int i = 0; i < pi.num; i++) { this->pos_num_arr[i] = pi.pos_num_arr[i]; }
			this->num = pi.num; this->_max = pi._max;
		}
		return *this;
	}

	inline PositiveIntegers operator += (int number) noexcept {

		try {
			if (this->num + 1 <= this->_max) {
				try {
					if (number > 0) {
						int* tmp = new int[this->num + 1];
						for (int i = 0; i < this->num; i++) { tmp[i] = this->pos_num_arr[i]; }
						tmp[this->num++] = number; delete[] this->pos_num_arr; this->pos_num_arr = new int[this->num]; this->pos_num_arr = tmp;
					}
					else { throw(number); }
				}

				catch (int num) { NumberIsNotPositiveException error; error.message(number); }
			}
			else { throw(0); }
		}

		catch (int num) { ArrayFullException error; error.message(); }

		return *this;
	}

	inline PositiveIntegers operator * (int mult) noexcept {
		PositiveIntegers tmp(_max);
		for (int i = 0; i < this->num; i++) { tmp += (this->pos_num_arr[i] * mult); }
		return tmp;
	}

	inline PositiveIntegers operator / (int div) noexcept {
		PositiveIntegers tmp(_max); bool check = false;

		try {
			if (div != 0) {
				for (int i = 0; i < this->num; i++) {
					if ((this->pos_num_arr[i] % div) == 0) { tmp += (pos_num_arr[i] / div); } 
					else { check = true; }
				}
			}

			else { throw(div); }
		}

		catch (int num) { ArithmeticException error; error.message(); }

		if (check == true) { NumbersNotDivisibleException error; error.message(div); tmp.num = 0; }

		return tmp;
	}

	inline int operator [] (int index) noexcept {
		try {
			if (index < this->num && index >= 0) { this->check = false; return this->pos_num_arr[index]; }
			else { throw(index); }
		}
		catch (int i) { IndexOutOfBoundsException error; error.message(i); this->check = true; return int(); }
	}

	~PositiveIntegers() { if (this->pos_num_arr != nullptr) { delete[] this->pos_num_arr; this->pos_num_arr = nullptr; } }

	inline void increaseCapacity(int increase) { this->_max += increase; }

	inline void print() {
		if (this->num != 0) {
			std::cout << "Size: " << this->num << " Capacity: " << this->_max << " Numbers: ";
			for (int i = 0; i < this->num; i++) { std::cout << this->pos_num_arr[i] << " "; } std::cout << std::endl;
		}
	}

	bool getCheck() { return this->check; }
};

int main() {
	int n, capacity; std::cin >> n >> capacity;  PositiveIntegers pi(capacity);

	for (int i = 0; i < n; i++) { int number; std::cin >> number; pi += number; }

	std::cout << "===FIRST ATTEMPT TO ADD NUMBERS===" << std::endl;  pi.print();

	int incCapacity; std::cin >> incCapacity; pi.increaseCapacity(incCapacity);
	std::cout << "===INCREASING CAPACITY===" << std::endl; pi.print();

	int n1; std::cin >> n1;
	for (int i = 0; i < n1; i++) { int number; std::cin >> number; pi += number; }
	std::cout << "===SECOND ATTEMPT TO ADD NUMBERS===" << std::endl; pi.print();

	PositiveIntegers pi1;

	std::cout << "===TESTING DIVISION===" << std::endl;
	pi1 = pi / 0; pi1.print(); pi1 = pi / 1; pi1.print(); pi1 = pi / 2; pi1.print();

	std::cout << "===TESTING MULTIPLICATION===" << std::endl;
	pi1 = pi * 3; pi1.print();

	std::cout << "===TESTING [] ===" << std::endl;
	std::cout << "PositiveIntegers[-1] = "; pi[-1]; if (pi.getCheck() == false) { std::cout << pi[-1] << std::endl; }
	std::cout << "PositiveIntegers[2] = "; pi[2]; if (pi.getCheck() == false) { std::cout << pi[2] << std::endl; }
	std::cout << "PositiveIntegers[3] = "; pi[3]; if (pi.getCheck() == false) { std::cout << pi[3] << std::endl; }
	std::cout << "PositiveIntegers[12] = "; pi[12]; if (pi.getCheck() == false) { std::cout << pi[12] << std::endl; }

	return 0;
}
