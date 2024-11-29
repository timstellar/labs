#include "../include/header.hpp"

void printMatrix(Matrix& matrix) {
    for (size_t i = 0; i < matrix.m_; ++i) {
        for (size_t j = 0; j < matrix.n_; ++j) {
            std::cout << matrix.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------" << std::endl;
}

int main() {
    const char* str = "Hello, world!";
    char* copy = CopyString(str);
    char* concat = ConcatinateStrings(str, " Goodbye, world!");
    std::cout << copy << std::endl;
    std::cout << concat << std::endl;

    Matrix a;
    Construct(a, 2, 2);
    a.data_[0][0] = 1;
    a.data_[0][1] = 2;
    a.data_[1][0] = 3;
    a.data_[1][1] = 4;

    Matrix b;
    Construct(b, 2, 2);
    b.data_[0][0] = 5;
    b.data_[0][1] = 6;
    b.data_[1][0] = 7;
    b.data_[1][1] = 8;

    Matrix copy_a = Copy(a);
    Matrix sum = Add(a, b);
    Matrix sub = Sub(a, b);
    Matrix mult = Mult(a, b);

    printMatrix(a);
    printMatrix(b);
    printMatrix(copy_a);
    printMatrix(sum);
    printMatrix(sub);
    printMatrix(mult);

    std::cout << "Before" << std::endl;
    printMatrix(a);
    std::cout << "After" << std::endl;
    Transposition(a);
    printMatrix(a);
    std::cout << "A and B matrices are " << ((a == b) ? "equal" : "not equal") << std::endl;

    Destruct(a);
    Destruct(b);
    Destruct(copy_a);
    Destruct(sum);
    Destruct(sub);
    Destruct(mult);

    delete[] copy;
    delete[] concat;

    return 0;
}