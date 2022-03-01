#include "matrix.h"
#include <iostream>

Matrix::Matrix(int new_m, int new_n, int value) : m(new_m), n(new_n)
{
    p = new int*[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            p[i][j] = value;
        }
    }
}

Matrix::Matrix(double* vals, int n)
{
    p = new int*[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            p[i][j] = (i == j) * vals[i];
        }
    }
}

int* Matrix::operator[](int i)
{
    return p[i];
}

const int* Matrix::operator[](int i) const
{
    return p[i];
}

Matrix::~Matrix()
{
    for (int i = 0; i < m; i++)
    {
        delete [] p[i];
    }
    delete [] p;
}

Matrix Matrix::diagonal(double* vals, int n)
{
    Matrix m(vals, n);
    return m;
}