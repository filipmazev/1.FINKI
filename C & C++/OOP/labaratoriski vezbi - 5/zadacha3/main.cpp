#include <iostream>

template<class TYPE>
class Matrix
{
private:
    TYPE** matrix{nullptr}; int r_size{0}, c_size{0};
public:
    Matrix(){ this->r_size=0; this->c_size=0; }

    Matrix(int r_size, int c_size){ this->r_size = r_size; this->c_size = c_size;
    this->matrix = new TYPE*[r_size]; for(size_t i=0; i<r_size; i++){ this->matrix[i] = new TYPE[c_size]; for(size_t j=0; j<c_size; j++){ this->matrix[i][j] = 0; } }
    }

    Matrix(const Matrix &m){
        if(this != &m){
            this->r_size = m.r_size; this->c_size = m.c_size;
            delete[] this->matrix; this->matrix = new TYPE*[m.r_size];
            for(size_t i=0; i<m.r_size; i++){ this->matrix[i] = new TYPE[m.c_size]; for(size_t j=0; j<m.c_size; j++){ this->matrix[i][j] = m.matrix[i][j]; } }
        }
    }

    inline Matrix &operator = (const Matrix &m){
        if(this != &m){
            this->r_size = m.r_size; this->c_size = m.c_size;
            delete[] this->matrix; this->matrix = new TYPE*[m.r_size];
            for(size_t i=0; i<m.r_size; i++){ this->matrix[i] = new TYPE[m.c_size]; for(size_t j=0; j<m.c_size; j++){ this->matrix[i][j] = m.matrix[i][j]; } }
        } return *this;
    }

    friend std::istream& operator >> (std::istream& input, Matrix& m) noexcept {
        input>>m.r_size>>m.c_size; m.matrix = new TYPE*[m.r_size]; for(size_t i=0; i<m.r_size; i++){ m.matrix[i] = new TYPE[m.c_size]; }
        for(size_t i=0; i<m.r_size; i++){ for(size_t j=0; j<m.c_size; j++){ input>>m.matrix[i][j]; } }
        return input;
    }

    friend std::ostream& operator << (std::ostream& out, Matrix& m) noexcept {
        for(size_t i=0; i<m.r_size; i++){ for(size_t j=0; j<m.c_size; j++){ out<<m.matrix[i][j]<<" "; } out<<std::endl; }
        return out<<std::endl;
    }

    inline Matrix operator + (const Matrix& other) noexcept {
        Matrix<TYPE> tmp((this->r_size>other.r_size?this->r_size:other.r_size),(this->c_size>other.c_size?this->c_size:other.c_size));
        for(int i=0; i<tmp.r_size; i++){ for(int j=0; j<tmp.c_size; j++){
                if(i < (this->r_size<other.r_size?this->r_size:other.r_size) && j < (this->c_size<other.c_size?this->c_size:other.c_size)){ tmp.matrix[i][j] = this->matrix[i][j]; }
                tmp.matrix[i][j] += other.matrix[i][j]; } }
        return tmp;
    }

    inline Matrix operator + (TYPE var) noexcept {
        Matrix<TYPE> tmp(this->r_size, this->c_size);
        for(int i=0; i<tmp.r_size; i++){ for(int j=0; j<tmp.c_size; j++){ tmp.matrix[i][j]+=this->matrix[i][j] + var; } }
        return tmp;
    }

    inline Matrix operator - (const Matrix& other) noexcept {
        Matrix<TYPE> tmp((this->r_size>other.r_size?this->r_size:other.r_size),(this->c_size>other.c_size?this->c_size:other.c_size));
        for(int i=0; i<tmp.r_size; i++){ for(int j=0; j<tmp.c_size; j++){
                if(i < (this->r_size<other.r_size?this->r_size:other.r_size) && j < (this->c_size<other.c_size?this->c_size:other.c_size)){ tmp.matrix[i][j] = this->matrix[i][j]; }
                tmp.matrix[i][j] -= other.matrix[i][j]; } }
        return tmp;
    }

    inline Matrix operator - (TYPE var) noexcept {
        Matrix<TYPE> tmp(this->r_size, this->c_size);
        for(int i=0; i<tmp.r_size; i++){ for(int j=0; j<tmp.c_size; j++){ tmp.matrix[i][j]+=this->matrix[i][j] - var; } }
        return tmp;
    }

    inline Matrix operator * (const Matrix& other) noexcept {
        Matrix<TYPE> tmp((this->r_size>other.r_size?this->r_size:other.r_size),(this->c_size>other.c_size?this->c_size:other.c_size));
        for(int i=0; i<(this->r_size<other.r_size?this->r_size:other.r_size); i++){
            for(int j=0; j<(this->c_size<other.c_size?this->c_size:other.c_size); j++){
                for(int k=0; k<(this->c_size<other.c_size?this->c_size:other.c_size); k++){
                    tmp.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j]; } } }
        return tmp;
    }

    inline Matrix operator * (TYPE var) noexcept {
        Matrix<TYPE> tmp(this->r_size, this->c_size);
        for(int i=0; i<tmp.r_size; i++){ for(int j=0; j<tmp.c_size; j++){ for(int k=0; k<tmp.c_size; k++) { tmp.matrix[i][j]+=this->matrix[i][k] * var; } } }
        return tmp;
    }

    ~Matrix(){ delete[] this->matrix; this->matrix=nullptr; }
};

int main()
{
    Matrix<float> A, B, C; std::cin>>A>>B>>C;
    Matrix<float> D=B*C; Matrix<float> R=A-D+2; std::cout<<R; return 0;
}
