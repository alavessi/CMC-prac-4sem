#pragma once

class Matrix
{
public:
    Matrix(int new_m = 1, int new_n = 1, int value = 0);
    Matrix(double* vals, int n);
    ~Matrix();
    int* operator[](int i);
    const int* operator[](int i) const;
    static Matrix diagonal(double* vals, int n);
private:
    int m, n;
    int** p;
};
