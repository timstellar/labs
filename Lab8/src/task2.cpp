#include "../include/header.hpp"

void Construct(Matrix& out, size_t n, size_t m) {
    if (out.data_ != nullptr) {
        Destruct(out);
    }
    out.n_ = n;
    out.m_ = m;
    out.data_ = new int*[m];
    for (size_t i = 0; i < m; ++i) {
        out.data_[i] = new int[n];
        for (size_t j = 0; j < n; ++j) {
            out.data_[i][j] = 0;
        }
    }
}
void Destruct(Matrix& in) {
    for (size_t i = 0; i < in.m_; ++i) {
        if (in.data_[i] != nullptr) {
            delete[] in.data_[i];
        }
    }
    delete[] in.data_;
    in.data_ = nullptr;
}

Matrix Copy(const Matrix& matrix) {
    Matrix copy;
    Construct(copy, matrix.n_, matrix.m_);
    for (size_t i = 0; i < matrix.m_; ++i) {
        for (size_t j = 0; j < matrix.n_; ++j) {
            copy.data_[i][j] = matrix.data_[i][j];
        }
    }
    return copy;
}

Matrix Add(const Matrix& a, const Matrix& b) {
    if (a.m_ != b.m_ || a.n_ != b.n_) {
        Matrix empty;
        return empty;
    } else {
        Matrix sum;
        Construct(sum, a.n_, a.m_);
        for (size_t i = 0; i < a.m_; ++i) {
            for (size_t j = 0; j < a.n_; ++j) {
                sum.data_[i][j] = a.data_[i][j] + b.data_[i][j];
            }
        }
        return sum;
    }
}

Matrix Sub(const Matrix& a, const Matrix& b) {
    if (a.m_ != b.m_ || a.n_ != b.n_) {
        Matrix empty;
        return empty;
    } else {
        Matrix sub;
        Construct(sub, a.n_, a.m_);
        for (size_t i = 0; i < a.m_; ++i) {
            for (size_t j = 0; j < a.n_; ++j) {
                sub.data_[i][j] = a.data_[i][j] - b.data_[i][j];
            }
        }
        return sub;
    }
}

Matrix Mult(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.m_) {
        Matrix empty;
        return empty;
    } else {
        Matrix mult;
        Construct(mult, b.n_, a.m_);
        for (size_t i = 0; i < a.m_; ++i) {
            for (size_t j = 0; j < b.n_; ++j) {
                for (size_t k = 0; k < a.n_; ++k) {
                    mult.data_[i][j] += a.data_[i][k] * b.data_[k][j];
                }
            }
        }
        return mult;
    }
}

void Transposition(Matrix& matrix) {
    Matrix buffer;
    Construct(buffer, matrix.m_, matrix.n_);
    for (size_t i = 0; i < matrix.m_; ++i) {
        for (size_t j = 0; j < matrix.n_; ++j) {
            buffer.data_[j][i] = matrix.data_[i][j];
        }
    }
    for (size_t i = 0; i < matrix.m_; ++i) {
        for (size_t j = 0; j < matrix.n_; ++j) {
            matrix.data_[i][j] = buffer.data_[i][j];
        }
    }
}

bool operator==(const Matrix& a, const Matrix& b) {
    if (a.m_ != b.m_ || a.n_ != b.n_) {
        return false;
    } else {
        for (size_t i = 0; i < a.m_; ++i) {
            for (size_t j = 0; j < a.n_; ++j) {
                if (a.data_[i][j] != b.data_[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}